/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 19:17:27 by crenaudi          #+#    #+#             */
/*   Updated: 2019/01/10 19:43:51 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
/*
static int	resolve()
{}
*/
int			solver(unsigned short **tab, int nb_piece, int round)
{
	int			i;

	i = (ft_sqrt(nb_piece * 4)) + round;
	ft_putnbr(i);
	if (!(resolve()))
	{
		round++;
		solver(tab, nb_piece, round);
	}
	return (1);
}

