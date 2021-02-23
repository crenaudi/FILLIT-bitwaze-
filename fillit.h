/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:23:35 by crenaudi          #+#    #+#             */
/*   Updated: 2019/01/17 18:47:43 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUF_SIZE 42
# include "libft/libft.h"
# include <stdint.h>

typedef struct	s_tetri
{
	unsigned ligne1: 4;
	unsigned ligne2: 4;
	unsigned ligne3: 4;
	unsigned ligne4: 4;
}				t_tetri;

typedef struct	s_map
{
	uint16_t	map[16];
	int			nb_piece;
}				t_info_map;

typedef struct	s_piece
{
	int			x;
	int			y;
	int			h;
	int			w;
	uint16_t	data;
}				t_piece;

int				fillit(const int fd);
char			make_tab(const char *src, int i, int j);
void			height_width_piece(t_piece *piece);
int				solver(t_piece tab[], int nb_piece, int rnd, t_info_map *info);
int				print_sort(t_piece tab[], int i, int nb_piece);
void			freeland(char *tmp, char *tmp_sub);
void			print_map(uint16_t map[]);
void			print_in_color(char *str, int cara);

#endif
