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


int		setsidesize(int numtetris)
{
	int i;
	int minimum;

	i = 2;
	minimum = numtetris * 4;
	while (minimum > (i * i))
		i++;
	printf("setsidesize returns a map size of %i\n", i);
	return (i + MAPOFFSET);
}

/*
int		placetetris(char **map, char **separatedtetris)
{

	//remove

	//check
	checkspot(char map, separatedtetris);

}
*/

int		checkspot(char **map, char **tet, int mapside, int numtetris)
{
	int i;
	int j;
	int t;
	int s;
	int printi = 1;

	i = 0;
	j = 0;
	t = 0;
	s = 0;

	while (tet[s][t])
	{
		printf("\n  ____________________________\n||  while loop iteration #%i  ||\n  ----------------------------\n", printi);
/*			if (map[i][j] != '\0')
			{
				i++;
				j = 0;
			}
*/
			printf("\nENTER\n");
			if (j >= 4)
			{
				i++;
				j = 0;
			}
		
			if ((tet[s][t]) && (tet[s][t] == 'A' || tet[s][t] == 'B' || tet[s][t] == 'C' || tet[s][t] == 'D'))
			{
					printf("*1* tet[%i][%i] is %c\n", s, t, tet[s][t]);
				//	printf("~~tet[%i][%i] == A or B is true\n", s, t);

				if (map[i][j] == '.')
				{
					printf("dot found at map[%i][%i]: %c\n", i, j, map[i][j]);
					map[i][j] = tet[s][t];
					j++;
					t++;
					printf(GRN" map[%i][%i] now set to %c\n"RESET, i, j-1, map[i][j-1]);
					printf("tet[%i][%i] is currently == %c\n", s, t, tet[s][t]);
				}
				else if (map[i][j] == 'A' || map[i][j] == 'B' || map[i][j] == 'C' || map[i][j] == 'D')
				{
					j++;
				}
			}
			else if (tet[s][t] == '.' && tet[s][t])
			{
					printf("~2~ tet[%i][%i] is %c\n", s, t, tet[s][t]);
				//	printf("~~tet[%i][%i] == . is true\n", s, t);
					printf("  map[%i][%i] is %c\n", i, j, map[i][j]);
					j++;
					t++;
			}
			if ((tet[s][t] != '.' && tet[s][t] != 'A' && tet[s][t] != 'B' && tet[s][t] != 'C' && tet[s][t] != 'D'))
			{
				printf("-3- tet[%i][%i] is not a letter or dot: [%c]\n", s, t, tet[s][t]);
				s++;

				t = 0;

				printf("-3- tet[%i][%i] is: [%c]\n", s, t, tet[s][t]);
				i = 0;
				j = 0;
				printf(" --3-- map[%i][%i] == %c", i, j, map[i][j]);

				//return 1;
			}
		/*	if ((tet[s][t] == '\0') || (!tet[s][t]))
			{
				printf("@@@@@@@@@@@@@@@");
				//return 0;
			} */

			if (s >= numtetris)
			{
				printf("size limit met, i: %i, mapside: %i\n", i, mapside);
				return 0;
			}	
		printi++;
	}
	return 0;

}


/*

char 	**checkspot(char **map, char **separatedtetris, int mapside)
{

	int i;
	int j;
	int t;
	int s;
	int printi;

	i = 0;
	j = 0;
	t = 0;
	s = 0;
	printf("mapside: %i\n", mapside);
	while(separatedtetris[s][t] != '\0')
	{
		printf("i: %i \nj: %i\n\n", i, j);
		if (j >= mapside - MAPOFFSET)
			{
				i++;
				j = 0;
			}
		if (separatedtetris[s][t] == '\0')
		{
			printf("i: %i, separatedtetris[%i][%i] is equal to 0", i, s, t);
			s++;
			t = 0;
		}
		if (separatedtetris[s][t] == '.')
		{
				j++;
				t++;
		}
	//	if (ft_isalpha(separatedtetris[s][t]))
		else

		{
			if (map[i][j] == '.')
			{
				map[i][j] = separatedtetris[s][t];
				j++;
				i++;
			}
			t++;
		}
	//	checkspot(map, separatedtetris, numtetris);

		//put

		printf(CYN"\n --map after checkspot--\n" RESET);

		printi = 0;
		while(printi < mapside)
		{
			printf("%s\n", map[printi]);
			printi++;
		}

	}
	return map;
}
*/

int		solver(char **separatedtetris, int numtetris)
{
	char **map;
	int mapside;
	int i;
	int j;
	int test;
	
	mapside = setsidesize(numtetris);

	if (!(map = (char**)malloc(sizeof(char *) * mapside)))
		return (0);
	map[numtetris + 1] = 0;
	
	
	i = 0;
	while(i < numtetris)
	{
		printf("separatedtetris [%i]: [%s]\n", i, separatedtetris[i]);
		i++;
	}


	i = 0;
	while(i < mapside - MAPOFFSET)
	{
		j = 0;
		map[i] = ft_strnew(mapside - MAPOFFSET);
		while (j < mapside - MAPOFFSET)
		{
			map[i][j] = '.';
			j++;			
		}
		printf("map[%i]: %s\n",i, map[i]);
		i++;
	}
//	printf("\n separatedtetris from solver: [%s]", *separatedtetris);
	printf(CYN"\n --map from solver below--\n" RESET);


	i = 0;


	while(i < mapside)
	{
		printf("%s\n", map[i]);
		i++;
	}

//	placetetris(map, separatedtetris);
	test = checkspot(map, separatedtetris, mapside, numtetris);

	printf(CYN"\n --map after checkspot--\n" RESET);

	i = 0;


	while(i < mapside)
	{
		printf("%s\n", map[i]);
		i++;
	}






return 0;
}



