/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 13:15:26 by mgill             #+#    #+#             */
/*   Updated: 2018/04/20 02:49:39 by mgill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>

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

	i = 0;
	tetrisfound = 0;
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
	char buf[526]; //26 tetriminos is the max input, so 26 * 21 characters + 1 for \0
	char **tetriswithletters;
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
		if(!(tetriswithletters = shapechecker(buf, numtetris, validtetris)))
		{
			printf("TETRIS WITH LETTERS NOT VALID\n");
			return 0;
		}
		else
		{
			solver(tetriswithletters, numtetris);
		}
	}
	return 0;
}
