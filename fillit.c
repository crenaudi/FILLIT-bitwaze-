/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:53:06 by crenaudi          #+#    #+#             */
/*   Updated: 2019/01/10 17:44:14 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "fillit.h"

int		check_c(char const *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '#' && s[i] != '.' && s[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int		fillit(const int fd)
{
	char	*src;
	char	buf[BUF_SIZE + 1];
	int		ret;
	int		i;

	src = NULL;
	ret = 0;
	i = 0;
	if (fd < 0)
		return (-1);
	while ((ret = read(fd, buf, BUF_SIZE)) != 0)
	{
		buf[ret] = '\0';
		src = (src == NULL) ? ft_strdup(buf) : ft_strjoin(src, buf);
	}
	if (check_c(src) != 1)
		return (0);
	return (make_tab(src, i, ret));
}

int		main(int argc, char **argv)
{
	int fd;

	fd = open(argv[1], O_RDONLY);
	(void)argc;
	if (fillit(fd) == 0)
	{
		ft_putstr("error");
		return (1);
	}
	close(fd);
	return (0);
}
