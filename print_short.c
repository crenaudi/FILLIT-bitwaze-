/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:06:33 by crenaudi          #+#    #+#             */
/*   Updated: 2018/12/27 14:29:53 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"

void	ft_print_bits(unsigned int a)
{
	unsigned int	ref;
	unsigned int	i;

	i = 0;
	ref = 128;
	while (ref != 0)
	{
		if (a >= ref)
		{
			write(1, "#", 1);
			a = a % ref;
		}
		else
			write(1, ".", 1);
		ref = ref / 2;
		i++;
		if (i == 4)
		{
			write(1, "\n",1);
			i = 0;
		}
	}
}

void	ft_print_short(unsigned short src)
{
	unsigned int a;
	unsigned int b;

	b = (char)src;
	a = src >> 8;
	ft_print_bits(a);
	ft_print_bits(b);
}
/*
int main(void)
{
	unsigned short a;
	unsigned short b;
	unsigned short c;
	unsigned short d;

	a = 0xE400;
	b = 0x00E4;
	c = 0xE4E4;
	d = 0x0000;

	ft_print_short(a);
	ft_putchar('\n');
	ft_print_short(b);
	ft_putchar('\n');
	ft_print_short(c);
	ft_putchar('\n');
	ft_print_short(d);
	ft_putchar('\n');
	return (0);
}
*/
