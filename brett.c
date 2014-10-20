/*
 * <one line to give the program's name and a brief idea of what it does.>
 * Copyright (C) 2014  Niklas Beck <s6nnbeck@uni-bonn.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#include "brett.h"

int init_brett(struct t_brett* brett, int n, int start_x, int start_y)
{
	brett->dim 		= n;
	brett->schritt_nr 	= 0;
	brett->pos_x 		= 0;
	brett->pos_y 		= 0;
	int i;
	
	if(!(brett->felder = malloc(n * sizeof(int*))))
		return 1;
	
	for(i=0; i!=n; ++i)
	{
		if(!(brett->felder[i] = calloc(n,(sizeof(int)))))  // alloziert und init mit 0 (void)
			return 1;
	}
	
	return (frei(brett, (start_x-1), (start_y-1))) ? neuer_sprung(brett, (start_x-1), (start_y-1)) : 1; // ooops (0 wenn erfolg)
}

int frei(struct t_brett* brett, int x, int y)
{
	x += brett->pos_x;
	y += brett->pos_y;

	if(((x >= 0) && (x < brett->dim)) && ((y >= 0) && (y < brett->dim)))
		return (brett->felder[x][y] == 0);
	else return 0;
}

int entferne_sprung(struct t_brett* brett, int x, int y)
{
	brett->schritt_nr--;
	brett->felder[brett->pos_x][brett->pos_y] = 0;
	brett->pos_x -= x;
	brett->pos_y -= y;
	return 0;
}

int neuer_sprung(struct t_brett* brett, int x, int y)
{
	brett->schritt_nr++;
	brett->pos_x += x;
	brett->pos_y += y;
	brett->felder[brett->pos_x][brett->pos_y] = brett->schritt_nr;
	return 0;
}

int besuchte_felder(struct t_brett* brett) { return brett->schritt_nr; }

void loesche_brett(struct t_brett* brett)
{
	int n = brett->dim;
	int i;
	
	for(i=0; i!=n; ++i)
		free(brett->felder[i]);
	free(brett->felder);
}

void print_line(int n)
{
	printf("\n+");
	int k;
	
	for(k=0; k!=n; ++k)
		printf("---+");
}

void print(struct t_brett* brett)
{
	int n = brett->dim;
	int i, j;
	print_line(n);
	
	for(i=0; i!=n; ++i)
	{
		printf("\n+");
		
		for(j=0; j!=n; ++j)
		{
			printf("%3i+", brett->felder[i][j]);
		}
		print_line(n);
	}
}

