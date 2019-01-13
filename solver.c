/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 19:17:27 by crenaudi          #+#    #+#             */
/*   Updated: 2019/01/13 21:29:24 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "fillit.h"

void			print_map(uint16_t map[]);

static void		enable_bits(t_piece piece, uint16_t map[], int y)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		map[y + (3 - i)] |= ((piece.data >> (4 * i) & 0xF) << (12 - piece.x));
		i++;
	}
}

/*
	a = 1000 1000
	b = 1100 0111
	c=     b
		& ~a
	c =      1100 0111
		&	~1000 1000

	c =		1100 0111
		&	0111 0111
			0100 0111
*/


static void		disable_bits(t_piece piece, uint16_t map[], int y)
{
	int			i;

	i = 0;
	while (i < 4)
	{
		map[y + (3 - i)] ^= ((piece.data >> (4 * i) & 0xF) << (12 - piece.x));
		i++;
	}
}


void			print_map(uint16_t map[])
{
	int		i;

	i = 0;
	while (i != 8)
	{
		ft_print_bits(map[i], 16, 16);
		i++;
	}
	ft_putchar('\n');
}

static int	test_place(t_piece piece, uint16_t map[], int y)
{
	int	i;
	int	x;

	i = 0;
	x = piece.x;
	while (i < 4)
	{
		if (((piece.data >> (4 * i) & 0xF) & (map[y + (3 - i)] >> (12 - piece.x))) != 0)
			return (0);
		i++;
	}
	//piece.have_place = 1;
	return (1);
}

static int	resolve(t_piece piece, uint16_t map[], int y, t_piece tab[], int i, int nb_piece)
{
	static int	index = 0;
	int			stop;
	int			j;

	j = 0;
	stop = i;
	if (index == nb_piece)
		return (1);
	piece.x = 0;
	piece.y = 0;
	while (y <= (i - piece.h))
	{
		piece.x = 0;
		while (piece.x <= (i - piece.w))
		{
			if (test_place(piece, map, y) == 1)
			{
				enable_bits(piece, map, y);
				index++;
				if (resolve(tab[index], map, 0, tab, i, nb_piece) == 1)
					return (1);
				index--;
				disable_bits(piece, map, y);
			}
			piece.x++;
		}
		y++;
	}
	return (0);
}

int			solver(t_piece tab[], int nb_piece, int round)
{
	uint16_t	map[16];
	uint16_t	ligne;
	int			index;
	int			i;

	i = (ft_sqrt(nb_piece * 4));
	if (i * i < nb_piece * 4)
		i++;
	i += round;
	//printf("%d %d\n", nb_piece, ft_sqrt(nb_piece * 4));
	index = 0;
	ligne = 0;
	ligne |= 1 << (16 - (i + 1));
	ligne |= 1 << (16 - (i + 2));
	while (index != i)
	{
		map[index] = ligne;
		index++;
	}
	while (index != 16)
	{
		map[index] = 0xFFFF;
		index++;
	}
	//attention tu n'envoie qu'une copie de ta piece penser a &tab[0], *piece, piece->elment
	if (resolve(tab[0], map, 0, tab, i, nb_piece) == 0)
	{
		round++;
		solver(tab, nb_piece, round);
	}
	else
	{
		print_map(map);
	}
	return (1);
}
