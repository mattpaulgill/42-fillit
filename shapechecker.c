/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapechecker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 02:29:35 by mgill             #+#    #+#             */
/*   Updated: 2018/04/16 05:21:13 by mgill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	len = ft_strlen(buf);
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

char	**ft_tetricpy(char *str, int numtetris)
{
	int i;
	int j;
	int row;
	char **twodarr;

	i = 0;
	row = 0;
	if (!(twodarr = (char**)malloc(sizeof(char *) * numtetris + 1)))
		return (0);
	while (row < numtetris)
	{
		j = 0;
		twodarr[row] = ft_strnew(20);
		while (j < 16)
		{
			if (str[i] != '\n')
			{
				twodarr[row][j] = str[i];
				j++;
			}
			i++;
		}
		row++;
	}
	return (twodarr);
/*
 * old version of ft_tetricopy which works
 *
	int i;
	int j;
	int row;
	int linecount;
	char **twodarr;

	i = 0;
	j = 0;
	row = 0;
	linecount = 1;
	if (!(twodarr = (char**)malloc(sizeof(char *) * numtetris + 1)))
		return (0);
	while (i <= numtetris)
	{
		twodarr[i] = 0;
		i++;
	}
	i = 0;
	while (numtetris-- > 0)
	{
		twodarr[numtetris] = ft_strnew(21);
	}
	while (str[i])
	{
		if (str[i] == '\n' && linecount < 5)
		{
			i++;
			linecount++;
		}
		if (linecount == 5)
		{
			twodarr[row][j] = '\0';
			printf("twodar[%i], copied tetri: %s\n", row, twodarr[row]);
			i++;
			linecount = 1;
			j = 0;
			if(str[i])
				row++;
			else
				break ;
		}
		twodarr[row][j] = str[i];
		i++;
		j++;
	}
	return (twodarr);
*/
}

int		shapechecker(char *str, int numtetris, char validtetris[20][15])
{
	char **separatedtetris;
	int i;
	int row;
	int  matchfound;
//	return (ft_tetricpy(str));
	separatedtetris = ft_tetricpy(str, numtetris);
	i = 0;
	row = 0;
	matchfound = 0;
//	printf("validtetris: %s", validtetris[0]);
	while(separatedtetris[row])
	{
		while(i < 19 && !matchfound)
		{
//			printf("loop entered, i: %i\n",i);
			if ((ft_strstr(separatedtetris[row], validtetris[i]) != 0)) //if a match is found
			{
				matchfound = 1;
				printf(GRN"\nmatch found,\n  separatedtetris[%s],\n  validtetris[%s]\n"RESET, separatedtetris[row], validtetris[i]); 
			}
			else
			{
				if (i == 18)
				{
					printf(YEL"Tetri #%i [%s] is not a valid tetri\n"RESET, row + 1, separatedtetris[row]);
					return 0;
				}
				i++;
			}
		}
		if (matchfound)
		{
			i = 0;
			row++;
			matchfound = 0;
		}
	}
	return 0;
}
