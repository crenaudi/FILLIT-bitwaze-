/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 18:00:51 by crenaudi          #+#    #+#             */
/*   Updated: 2019/01/10 19:40:34 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

static int		grid(const char *s, int x, int y)
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
			if ((x - ((x / 4) * 4)) - y != 0)
				return (0);
			y++;
		}
		if (s[x] != '\n')
			i++;
		if (s[x] != '\0')
			x++;
	}
	if ((x + 1) % 21 == 0 && (x + 1) / 21 == y)
		return (y);
	return (0);
}

static int		split(char **tmp, int j, const char *src)
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

static int		piece_is_valid(unsigned short ref)
{
	static unsigned short	tab[19] = {
		0xF000, 0x8888,
		0xCC00,
		0xC600, 0x6C00, 0x8C40, 0x4C80,
		0xE400, 0x4E00, 0x4C40, 0x8C80,
		0x88C0, 0x44C0, 0x8E00, 0xE800, 0x2E00, 0xE200, 0xC440, 0xC880
	};
	int						i;

	i = 0;
	while (i < 19)
	{
		if (tab[i] == ref)
			return (1);
		i++;
	}
	return (0);
}

static int		parse_piece(char const *s)
{
	unsigned short	piece;
	int				i;

	i = 0;
	piece = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '#')
			piece |= 1 << (15 - i);
		i++;
	}
	while (!(0x8888 & piece))
		piece = piece << 1;
	i = 0;
	while (!(0xF000 & piece))
		piece = piece << 4;
	if (!(piece_is_valid(piece)))
		return (0);
	return (piece);
}

char			make_tab(const char *src, int i, int j)
{
	unsigned short	tab[11] = {0};
	unsigned short	piece;
	char			*tmp;
	int				nb_piece;

	if ((nb_piece = grid(src, 0, 0)) <= 0 || nb_piece > 26)
		return (0);
	j = nb_piece * 16;
	tmp = NULL;
	if (!(split(&tmp, j, src)))
		return (0);
	j = 0;
	while (nb_piece != i)
	{
		if ((piece = parse_piece(ft_strsub(tmp, j, 16))) == 0)
			return (0);
		j = j + 16;
		i++;
		tab[i] = piece;
	}
	return (solver(tab, nb_piece, 0));
}
