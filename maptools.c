/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maptools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 05:39:01 by mgill             #+#    #+#             */
/*   Updated: 2018/05/17 06:09:10 by mgill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	[solver:] called from solver()
**	frees the map's memory
*/

void	freemap(char **map, int mapside)
{
	int i;

	i = 0;
	while (i < mapside)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	printmap(char **map, int mapside)
{
	int i;

	i = 0;
	while (i < mapside)
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
}

int		setsidesize(int numtetris)
{
	int i;
	int minimum;

	i = 2;
	minimum = numtetris * 4;
	while (minimum > (i * i))
		i++;
	return (i);
}

char	**makemap(int mapside, int mapsidewithoffset, int i)
{
	char	**map;
	int		j;

	mapsidewithoffset = mapside + MAPOFFSET;
	map = (char **)malloc(sizeof(char *) * mapsidewithoffset + 1);
	if (!map)
		return (0);
	map[mapsidewithoffset] = 0;
	while (++i < mapside)
	{
		map[i] = ft_strnew(mapsidewithoffset);
		if (!map)
			return (0);
		ft_bzero(map[i], mapsidewithoffset);
		j = -1;
		while (++j < mapside)
			map[i][j] = '.';
	}
	i--;
	while (++i < mapsidewithoffset)
	{
		map[i] = ft_strnew(mapsidewithoffset);
		ft_bzero(map[i], mapsidewithoffset);
	}
	return (map);
}
