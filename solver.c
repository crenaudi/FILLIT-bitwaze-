/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 19:17:27 by crenaudi          #+#    #+#             */
/*   Updated: 2019/01/11 23:15:11 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "fillit.h"

static int	test_place(t_piece piece, uint16_t map[], int y)
{
	int	i;

	i = 0;
	ft_putchar('\n');
	ft_print_bits(piece.data, 16, 4);
	ft_putchar('\n');
	while (i < 4)
	{
		if ((((piece.data >> (4 * i)) & 0xF) & map[y + i]) != 0)
			return (0);
		i++;
	}
	piece.have_place = 1;
	return (1);
}

static int	resolve(t_piece piece, uint16_t map[], int y)
{
	if (test_place(piece, map, y) == 0)
		return (0);
	if (piece.have_place == 0)
	{
		return (1);
	}
	return(1);
}

int			solver(t_piece tab[], int nb_piece, int round)
{
	uint16_t	map[16];
	uint16_t	ligne;
	int			index;
	int			i;

	i = (ft_sqrt(nb_piece * 4)) + round;
	index = 0;
	ligne = 0;
	ligne |= 1 << (16 - i);
	ligne |= 1 << (16 - (i + 1));
	while (index != i)
	{
		map[index] = ligne;
		ft_print_bits(map[index], 16, 16);
		index++;
	}
	map[index] = 0xFFFF;
	ft_print_bits(map[index], 16, 16);
	if (resolve(tab[0], map, 0) == 0)
	{
		round++;
		//solver(tab, nb_piece, round);
	}
	return (1);
}

