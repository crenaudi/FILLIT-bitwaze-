/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 19:17:27 by crenaudi          #+#    #+#             */
/*   Updated: 2019/01/08 20:55:03 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

static unsigned short	*make_map(unsigned short *map, int nb_piece, int round)
{
	int				i;
	int				size;

	i = 16;
	size = 1;
	nb_piece = nb_piece * (2 + round);
	while (i < (nb_piece * nb_piece))
	{
		i = i + 16;
		size++;
	}
	if (!(map = (unsigned short *)malloc(sizeof(unsigned short) * (size + 1))))
		return (0);
	map[size + 1] = 0;
	i = 0;
	while (i <= size)
	{
		map[i] = 0x0000;
		i++;
	}
	return (map);
}
/*
static int		move_piece(unsigned short *piece, char **map)
{
	int	x;
	int	i;
	int	index;

	x = 0;
	i = 0;
	index = 0;
	while (((piece & map[i]) == 0x0000))
	{
		if (!(0x1111 & piece))
		{
			piece = piece >> 1;
			x++;
			}
		else (!(0x000F & (piece = piece << x)))
		{
			piece = piece << 4;
			x = 0;
		}
		if (deborde de y)
			return (0);
		index++;
	}
	return (1);
}
*/
unsigned short	solver(unsigned short tab[26], int nb_piece, int round)
{
	/*t_fillit	hey;*/
	unsigned short	*map;
	int				i;

	i = 0;
	map = NULL;
	map = make_map(map, nb_piece, round);
	while (map[i] != '\0')
	{
		ft_print_short(map[i]);
		i++;
	}
	i = 0;
	while (tab[i] != 0)
	{
		//if (!(tab[i] & map[i]))
		//{
			i++;
			//ft_print_short(tab[i]);
			//map[j] = tab[i] ^ map[j];
		//}
		//else
		//{
		//	i++;
		//}
	}
	/*
	while (tab[i] != 0)
	{
		if (tab[i] ^= map)
		{
			i++;
		}
		else
		{
			if (!(move_piece()))
			{
				free(map);
				round++;
				solver();
			}
			i++;
		}
	}*/
	return (1);
}

