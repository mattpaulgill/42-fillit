/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 13:15:26 by mgill             #+#    #+#             */
/*   Updated: 2018/04/16 05:22:39 by mgill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>

/*
int		strlength(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		//printf("   i: %i  character: %c\n", i, str[i]);
		i++;
	}
	return (i);
}
*/

/*
int 	inputcheck(char *buf)
{
	int hashcount;
	int count;
	int linecount;
	int i;
	int len;
	int tetrisfound;

	hashcount = 0;
	count = 1;
	linecount = 1;
	i = 0;
	len = strlength(buf);
	tetrisfound = 0;

	while (buf[i])
	{
		if (buf[i] != '#' && buf[i] != '.')
		{
			printf("invalid character found: [%c] at index [%i]\n", buf[i], i);
			printf("linecount: %i  count: %i\n", linecount, count);
			return 0;
		}
		else if (buf[i] == '#')
		{
			hashcount++;
		}		
		i++;
		count++;
		if (count % 5 == 0 && linecount < 5)
		{
			if (buf[i] != '\n')
			{
				printf("no new line at end of line\n");
				return 0;
			}
			else
			{
			//	printf("new line found at linecount %i\n",linecount);
				i++;
				linecount++;
				count = 1;
			}
		}

		if (linecount == 5)
		{
			if (hashcount != 4)
			{
				printf("wrong amount of #'s found. hashcount: %i\n", hashcount);
				return 0;
			}
			else
			{
				hashcount = 0;
			}
			if (buf[i] != '\n')
			{
				printf("no new line after tetrimino at tetrimino #%i\n", tetrisfound + 1);
				return 0;
			}
			else
			{
				i++;
				linecount = 1;
				tetrisfound++;
				printf("  tetris found: %i\n", tetrisfound);
			}
		}
	}
	return tetrisfound;
}
*/

void	makevalidtetris(char valid[20][15])
{
	ft_strcpy(valid[0], "###...#");
	ft_strcpy(valid[1], ".#...#..##");
	ft_strcpy(valid[2], "#...###");
	ft_strcpy(valid[3], "##..#...#");
	ft_strcpy(valid[4], "###.#");
	ft_strcpy(valid[5], "##...#...#");
	ft_strcpy(valid[6], "..#.###");
	ft_strcpy(valid[7], "#...#...##");
	ft_strcpy(valid[8], "###..#");
	ft_strcpy(valid[9], ".#..##...#");
	ft_strcpy(valid[10], ".#..###");
	ft_strcpy(valid[11], "#...##..#");
	ft_strcpy(valid[12], ".##.##");
	ft_strcpy(valid[13], "#...##...#");
	ft_strcpy(valid[14], "##..##");
	ft_strcpy(valid[15], "#...#...#...#");
	ft_strcpy(valid[16], "####");
	ft_strcpy(valid[17], ".#..##..#");
	ft_strcpy(valid[18], "##...##");
}

/*
 *fd stores the file descriptor returned from open();
 */
int		tetriread(char *argv[], char *buf)
{
	int fd;
	int i;
	int tetrisfound;
//	char buf[526]; //26 tetriminos is the max input, so 26 * 21 characters + 1 for \0
//	char checkedInput[26][21];

	i = 0;
	tetrisfound = 0;
/*
//write
	fd = open("test", O_CREAT | O_WRONLY, 0600);

	if (fd == -1)
	{
		printf("Failed to create and open the file.\n");
		exit(1);
	}

	write(fd, "Hello World!\n", 13);

	close(fd);
*/

//read
	fd = open(argv[1], O_RDONLY);

	if (fd == -1)
	{
		printf("Failed to open and read the file.\n");
		exit(1);
	}
	read(fd, buf, 526);
	buf[ft_strlen(buf)] = '\0';
	close(fd);
	tetrisfound = inputcheck(buf);
	if (tetrisfound > 0)
	{
		printf("%s", buf);
		printf(GRN"\nRESULT: Input is valid!!\n" RESET);
		/*
		while (i < tetrisfound)
		{
			shapechecker(checkedInput[i], buf);
			i++;
			printf("checkedInput[%i]: %s\n",i, checkedInput[i]);
		}
		*/
		return tetrisfound;
	}
	else
	{
		printf("%s", buf);
		printf(RED"\nRESULT: Input not valid\n" RESET);
	}

	return 0;
}

int		main(int argc, char *argv[])
{
	char validtetris[20][15];
	char buf[526]; //26 tetriminos is the max input, so 26 * 21 characters + 1 for \0i
	int numtetris;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return 0;
	}
	makevalidtetris(validtetris);
	numtetris = tetriread(argv, buf);
	if (numtetris)
	{
		shapechecker(buf, numtetris, validtetris);

	}


	return 0;
}
