/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:23:35 by crenaudi          #+#    #+#             */
/*   Updated: 2019/01/10 19:43:01 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef	FILLIT_H
# define	FILLIT_H

# define BUF_SIZE 42

struct	s_tetri
{
	unsigned ligne1: 4;
	unsigned ligne2: 4;
	unsigned ligne3: 4;
	unsigned ligne4: 4;
};

int		fillit(const int fd);
char	make_tab(const char *src, int i, int j);
int		solver(unsigned short **tab, int nb_piece, int round);
int		ft_print_short(unsigned short src);

# endif
