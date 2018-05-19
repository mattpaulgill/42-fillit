/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   othertools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 19:10:36 by mgill             #+#    #+#             */
/*   Updated: 2018/05/18 19:10:40 by mgill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	[solver.c:??] called from deletetetri()
**	finds the first character that isn't a '.' to get the tetromino's letter
*/

char	getletter(char *tetri)
{
	while (*tetri == '.')
		tetri++;
	return (*tetri);
}

/*
** [inputchecker.c:161] called from inputchecker()
** switches hashes in tetrominos to capital letters.
*/

int		hashtoletter(char *validtetri, int row)
{
	int i;

	i = 0;
	while (validtetri[i])
	{
		if (validtetri[i] == '#')
			validtetri[i] = (65 + row);
		i++;
	}
	return (0);
}

/*
** [fillit.c:82] called from tetriread()
**	counts valid tetrominos by checking for double newlines
*/

int		countvalidtetris(char *buf)
{
	int totaltetris;
	int i;

	totaltetris = 0;
	i = -1;
	while (buf[++i])
	{
		if (buf[i] == '\n' && buf[i + 1] == '\n')
		{
			totaltetris++;
		}
	}
	return (totaltetris + 1);
}
