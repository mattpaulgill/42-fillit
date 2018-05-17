/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputchecker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 02:29:35 by mgill             #+#    #+#             */
/*   Updated: 2018/04/23 19:49:27 by mgill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*
 * [line ??]	called from shapecheck.
 * checks if there are only dots and hashes in a single tetromino.
 * i is passed into charcheck containing the last index of a tetromino.
 * [line 26]	j = 19: the max index in a tetromino, j is subtracted from i
 * 		and decremented to check each character of the tetromino.
 * [line 36]	hashcount != 4: if there aren't exactly 4 hashes, it is invalid.
 */
int 	charcheck(char *buf, int i, int hashcount)
{
	int j;

	j = 19;
	while (j >= 0)
	{
		if (buf[i - j] != '#' && buf[i - j] != '.' && buf[i - j] != '\n')
			return (0);
		if (buf[i - j] == '#')
			hashcount++;
		j--;
	}
	if (hashcount != 4)
		return (0);
	return (1);
}

/*
 * [line ??]
 *
 * [line ??]
 *
 * [line ??]
 *
 * [line ??]
 *
 */
int 	shapecheck(char *buf, int i, int widthcount, int heightcount)
{
	while(buf[++i])
	{
		if (widthcount % 4 == 0 && i > 0)
		{
			heightcount++;
			widthcount = 0;
			if(buf[i] != '\n')
				return (0);
			i++;
		}
		if (heightcount == 4)
		{
			if (charcheck(buf, i - 1, 0) == 0)
				return (0);
			if (!buf[i])
				return (1);
			if (buf[i] != '\n')
				return (0);
			heightcount = 0;
			i++;
		}
		widthcount++;
	}
	return (1);
}
/*
 * [line ??]
 *
 * [line ??]
 *
 * [line ??]
 *
 * [line ??]
 *
 */
int 	countvalidtetris(char *buf)
{
	int totaltetris;
	int i;

	totaltetris = 0;
	i = -1;
	while(buf[++i])
	{
		if(buf[i] == '\n' && buf[i + 1] == '\n')
		{
			totaltetris++;
		}
	}
	return (totaltetris + 1);
}
/*
 * [line ??]
 *
 * [line ??]
 *
 * [line ??]
 *
 * [line ??]
 *
 */
char	**tetricpy(char *buf, int numberoftetris)
{
	int i;
	int j;
	int row;
	char **twodarr;

	i = 0;
	row = 0;
	if (!(twodarr = (char**)ft_memalloc(sizeof(char *) * numberoftetris + 1)))
		return (0);
	twodarr[numberoftetris] = 0;
	while (row < numberoftetris)
	{
		j = 0;
		twodarr[row] = ft_strnew(20);
		while (j < 16)
		{
			if (buf[i] != '\n')
			{
				twodarr[row][j] = buf[i];
				j++;
			}
			i++;
		}
		row++;
	}
	return (twodarr);
}

/* [line ??] called from inputchecker.
 * switches hashes in tetrominos to capital letters.
 */
int		hashtoletter(char *validtetri, int row)
{
	int i;

	i = 0;
	while(validtetri[i])
		{
			if (validtetri[i] == '#')
				validtetri[i] = (65 + row);
			i++;
		}
	return 0;
}
/*
 * [fillit.c:??]	called from main.
 * returns a 2d array of the valid tetrominos in the proper format.
 * [line ??]
 *
 * [line ??]
 *
 * [line ??]
 *
 */
char	**inputchecker(char *buf, int numberoftetris, char validtetris[20][15], int row)
{
	char **separatedtetris;
	int i;

	separatedtetris = tetricpy(buf, numberoftetris);
	while(separatedtetris[++row])
	{
		i = 0;
		while(i < 19 && row < numberoftetris)
		{
			if ((ft_strstr(separatedtetris[row], validtetris[i]) != 0)) //if a match is found
			{
				ft_bzero(separatedtetris[row], ft_strlen(separatedtetris[row]));
				ft_strcpy(separatedtetris[row], validtetris[i]);
				hashtoletter(separatedtetris[row], row);
				//printf(GRN"\nmatch found,\n  separatedtetris[%s],\n  validtetris[%s]\n"RESET, separatedtetris[row], validtetris[i]);
				break ;
			}
			else
			{
				if (i == 18)
					return (0);
				i++;
			}
		}
	}
	return (separatedtetris);
}