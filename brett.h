
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

/* inclusion guard */
#ifndef __BRETT_H__
#define __BRETT_H__

#include <stdio.h>
#include <stdlib.h>

struct t_brett
{
	int dim;
	int schritt_nr;
	int pos_x;
	int pos_y;
	int** felder;
};

int init_brett(struct t_brett* brett, int n, int start_x, int start_y);
int neuer_sprung(struct t_brett* brett, int x, int y);
int frei(struct t_brett* brett, int x, int y);
int entferne_sprung(struct t_brett* brett, int x, int y);
int besuchte_felder(struct t_brett* brett);
void print(struct t_brett* brett);
void loesche_brett(struct t_brett* brett);
void print_line(int n);
#endif /* __BRETT_H__ */
