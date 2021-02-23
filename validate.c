/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 18:00:51 by crenaudi          #+#    #+#             */
/*   Updated: 2019/01/17 18:56:47 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	grid(const char *s, int x, int y)
{
	int	i;

	i = 0;
	while (s[x] != '\0')
	{
		if (s[x] == '\n' && i != 4)
			return (0);
		if (s[x] == '\n')
			i = 0;
		if (s[x] == '\n' && (s[++x] == '\n' || s[x] == '\0'))
		{
			if ((x - y) % 4 != 0)
				return (0);
			y++;
		}
		if (s[x] != '\n')
			i++;
		if (s[x] != '\0')
			x++;
	}
	if ((x + 1) % 21 == 0 && (x + 1) / 21 == y)
	{
		return (y);
	}
	return (0);
}

static int	split(char **tmp, int j, const char *src)
{
	char	*dest;
	int		i;

	i = 0;
	if (!(dest = (char *)malloc(sizeof(char) * (j + 1))))
		return (0);
	dest[j] = '\0';
	j = 0;
	while (src[i] != '\0')
	{
		while (src[i] == '\n')
			i++;
		dest[j] = src[i];
		if (src[i] != '\0')
			i++;
		j++;
	}
	*tmp = ft_strdup(dest);
	free(dest);
	return (1);
}

static int	piece_is_valid(uint16_t ref)
{
	static uint16_t	tab[19] = {
		0xF000, 0x8888,
		0xCC00,
		0xC600, 0x6C00, 0x8C40, 0x4C80,
		0xE400, 0x4E00, 0x4C40, 0x8C80,
		0x88C0, 0x44C0, 0x8E00, 0xE800, 0x2E00, 0xE200, 0xC440, 0xC880
	};
	int				i;

	i = 0;
	while (i < 19)
	{
		if (tab[i] == ref)
			return (1);
		i++;
	}
	return (0);
}

static int	parse_piece(char const *s)
{
	uint16_t	piece;
	int			i;

	i = 0;
	piece = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '#')
			piece |= 1 << (15 - i);
		i++;
	}
	if (piece == 0)
		return (0);
	while (!(0x8888 & piece))
		piece = piece << 1;
	while (!(0xF000 & piece))
		piece = piece << 4;
	if (!(piece_is_valid(piece)))
		return (0);
	return ((unsigned short)piece);
}

char		make_tab(const char *src, int i, int j)
{
	t_piece		tab[12];
	t_piece		piece;
	t_info_map	info;
	char		*tmp;
	char		*tmp_sub;

	if ((info.nb_piece = grid(src, 0, 0)) <= 0 || info.nb_piece > 26)
		return (0);
	tmp = NULL;
	if (!(split(&tmp, (info.nb_piece * 16), src)))
		return (0);
	j = 0;
	while (info.nb_piece != i)
	{
		tmp_sub = ft_strsub(tmp, j, 16);
		if ((piece.data = parse_piece(tmp_sub)) == 0)
			return (0);
		j = j + 16;
		height_width_piece(&piece);
		tab[i++] = piece;
	}
	if (solver(tab, info.nb_piece, 0, &info) == 0)
		return (0);
	freeland(tmp, tmp_sub);
	return (1);
}
