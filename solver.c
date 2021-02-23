/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 19:17:27 by crenaudi          #+#    #+#             */
/*   Updated: 2019/01/16 22:58:09 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	enable_bits(t_piece piece, uint16_t map[], int y)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		map[y + (3 - i)] |= ((piece.data >> (4 * i) & 0xF) << (12 - piece.x));
		i++;
	}
}

static void	disable_bits(t_piece piece, uint16_t map[], int y)
{
	int			i;

	i = 0;
	while (i < 4)
	{
		map[y + (3 - i)] ^= ((piece.data >> (4 * i) & 0xF) << (12 - piece.x));
		i++;
	}
}

static int	test_place(t_piece piece, uint16_t map[], int y)
{
	int	i;
	int	x;

	i = 0;
	x = piece.x;
	while (i < 4)
	{
		if (((piece.data >> (4 * i) & 0xF)
					& (map[y + (3 - i)] >> (12 - piece.x))) != 0)
			return (0);
		i++;
	}
	return (1);
}

static int	resolve(t_piece *p, t_info_map *info, t_piece tab[], int i)
{
	static int	index = 0;
	int			j;

	j = 0;
	if (index == info->nb_piece)
		return (1);
	p->y = 0;
	while (p->y <= (i - p->h))
	{
		p->x = 0;
		while (p->x <= (i - p->w))
		{
			if (test_place(*p, info->map, p->y) == 1)
			{
				enable_bits(*p, info->map, p->y);
				if (resolve(&tab[++index], info, tab, i) == 1)
					return (1);
				index--;
				disable_bits(*p, info->map, p->y);
			}
			p->x++;
		}
		p->y++;
	}
	return (0);
}

int			solver(t_piece tab[], int nb_piece, int rnd, t_info_map *info)
{
	uint16_t	ligne;
	int			index;
	int			i;

	i = (ft_sqrt(nb_piece * 4));
	if (i * i < nb_piece * 4)
		i++;
	i += rnd;
	index = 0;
	ligne = 1 << (16 - (i + 1));
	while (index != i)
		info->map[index++] = ligne;
	while (index != 16)
		info->map[index++] = 0xFFFF;
	if (resolve(&tab[0], info, tab, i) == 0)
	{
		rnd++;
		solver(tab, nb_piece, rnd, info);
	}
	else
	{
		if (print_sort(tab, i, nb_piece) == 0)
			return (0);
	}
	return (1);
}
