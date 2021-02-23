/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:03:56 by crenaudi          #+#    #+#             */
/*   Updated: 2019/01/16 23:14:26 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		print_piece(char *string, t_piece p, int letter, int i)
{
	int		start;
	int		i_bits;

	i_bits = 15;
	start = (p.y * i) + p.x;
	while (string[start] != '\0' && i_bits >= 0)
	{
		if ((1 & (p.data >> i_bits)) == 1)
			string[start] = 65 + letter;
		start++;
		if (i_bits % 4 == 0)
			start = start + (i - 4);
		i_bits--;
	}
}

int				print_sort(t_piece tab[], int i, int n)
{
	int			index;
	int			size;
	static char	*string;

	index = 0;
	size = i * i;
	string = (char *)malloc(sizeof(char) * (size + 1));
	string[size] = '\0';
	while (size--)
		string[size] = '.';
	size++;
	while (n--)
	{
		print_piece(string, tab[size], size, i);
		size++;
	}
	while (string[index] != '\0')
	{
		ft_putchar(string[index]);
		if ((index + 1) % i == 0)
			ft_putchar('\n');
		index++;
	}
	return (1);
}
