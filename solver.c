/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 21:01:46 by mgill             #+#    #+#             */
/*   Updated: 2018/04/27 21:17:50 by mgill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	printtetris(char **tetri, int numtetris)
{
	int i;
	i = 0;
	while(i < numtetris)
	{
		printf("separatedtetris [%i]: [%s]\n", i, tetri[i]);
		i++;
	}
}

void	printmap(char **map, int mapside)
{
	int i;
	i = 0;
	while(i < mapside)
	{
		printf("%s\n", map[i]);
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
	printf("setsidesize returns a map size of %i\n", i);
	return (i);
}

char		**makemap(int mapside)
{
	printf(GRN"\n |makemap called|\n" RESET);
	int		i;
	int		j;
	char	**map;
	int		size_c;

	size_c = mapside + 3;
	map = (char **)ft_memalloc(sizeof(*map) * (size_c + 1));
	if (!map)
		return (0);
	map[size_c] = "\0";
	i = -1;
	while (++i < mapside)
	{
		map[i] = ft_memalloc(size_c);
		if (!map)
			return (0);
		j = -1;
		while (++j < mapside)
			map[i][j] = '.';
	}
	i--;
	while (++i < size_c)
		map[i] = ft_memalloc(size_c);
	return (map);
}

char	getletter(char *tetri)
{
	printf(GRN"\n |getletter called|\n" RESET);
	int i;

	i = 0;
	while (tetri[i])
	{
		if (tetri[i] >= 'A' && tetri[i] <= 'Z')
		{
			return (tetri[i]);
		}
		i++;
	}
	return (0); //error, letter not found
}

/*
void	deletetetri(char **map, char *tetri, int mapside)
{
	printf(YEL"\n |deletetetri called for [%c] |\n" RESET, getletter(tetri));
	char	letter;
	int		lettersfound;
	int		x;
	int		y;

	letter = getletter(tetri);
	lettersfound = 0;
	x = 0;
	y = 0;
	while (map[x][y])
	{
		if (map[x][y] == letter)
		{
			map[x][y] = '.';
			lettersfound++;
			if(lettersfound == 4)
				return;
		}
		if(y >= mapside)
		{
			x++;
			y = -1;
		}
		y++;
	}
}
*/

void	deletetetri(char **grid, char *tetri, int row, int col)
{
	char	ch;
	int		i;

	ch = getletter(tetri);
	i = 0;
	while (grid[row])
	{
		col = 0;
		while (grid[row][col])
		{
			if (i == 4)
				return ;
			if (grid[row][col] == ch)
			{
				i++;
				grid[row][col] = '.';
			}
			col++;
		}
		row++;
	}
}

void	puttetri(char **map, char *tetri, int x, int y)
{
	printf(CYN"\n ~! puttetri for [%c] !~\n" RESET, getletter(tetri));
	int i;
	int c;

	i = 0;
	c = 0;
	while (tetri[i])
	{
		if (tetri[i] >= 'A' && tetri[i] <= 'Z')
		{
			map[x][y] = tetri[i];
		}
		i++;
		c++;
		y++;
		if (c == 4)
		{
			x++;
			c = 0;
			y -= 4;
		}
	}

	//printmap(map, 4);
}

int		checkspot(char **map, char *tetri, int x, int y)
{
	printf(GRN"\n |checkspot called for [%c] |\n" RESET, getletter(tetri));
	int i;
	int c;

	i = 0;
	c = 0;
	while (tetri[i])
	{
		printf("\n -checkspot check-  x: %i  y: %i  i: %i  c: %i \n", x, y, i, c);
		if (c == 4)
		{
			x++;
			c = 0;
			y = 0;
		}
		if (map[x][y] != '.' && tetri[i] >= 'A' && tetri[i] <= 'Z')
			return 0;
		i++;
		c++;
		y++;
	}
	return (1);
}

int		cycle(char **map, char **tetri, int x, int y, int mapside)
{
	if (*tetri == 0)
		return (1);
	printf(MAG"\n ||cycle called||\n" RESET);
	while (map[x])
	{
		while (map[x][y])
		{
			if (checkspot(map, *tetri, x, y))
			{
				puttetri(map, *tetri, x, y);
				if(cycle(map, (tetri + 1), x, y, mapside))
					return (1);
				else
					deletetetri(map, *tetri, x, y);
			}
			y++;
		}
		x++;
		y = 0;
	}
	return (0);
}

int		solver(char **separatedtetris, int numtetris)
{
	char **map;
	int mapside;
	mapside = setsidesize(numtetris);
	map = makemap(mapside);
	if (!map)
		return (0);
	printtetris(separatedtetris, numtetris);

	printf(CYN"\n --map from solver below--\n" RESET);

	printmap(map, mapside);

	printf(CYN"\n --map from cycle below--\n" RESET);
	cycle(map, separatedtetris, 0, 0, mapside);
	printmap(map, mapside);
	return 0;
}



