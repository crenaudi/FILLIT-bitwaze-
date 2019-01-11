/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:23:35 by crenaudi          #+#    #+#             */
/*   Updated: 2019/01/11 19:34:00 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef	FILLIT_H
# define	FILLIT_H

# define BUF_SIZE 42
#include <stdint.h>

typedef struct	s_tetri
{
	unsigned ligne1: 4;
	unsigned ligne2: 4;
	unsigned ligne3: 4;
	unsigned ligne4: 4;
}				t_tetri;

typedef struct	s_piece
{
	int			y;
	int			have_place;
	uint16_t	data;
}				t_piece;

int		fillit(const int fd);
char	make_tab(const char *src, int i, int j);
int		solver(t_piece tab[], int nb_piece, int round);

# endif
