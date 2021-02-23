/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 18:48:07 by crenaudi          #+#    #+#             */
/*   Updated: 2019/01/13 19:54:44 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	height_width_piece(t_piece *piece)
{
	int	x;
	int	y;
	int	tmp;

	y = 0;
	piece->h = 0;
	piece->w = 0;
	while (y < 4)
	{
		tmp = 0;
		if ((piece->data >> (4 * y) & 0xF) != 0)
			piece->h++;
		x = 0;
		while (x < 4)
		{
			if (((piece->data >> (4 * y) & 0xF) & (1 << (3 - x))) != 0)
				tmp++;
			x++;
		}
		if (tmp > piece->w)
			piece->w = tmp;
		y++;
	}
}
