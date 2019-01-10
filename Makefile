# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/13 14:13:30 by crenaudi          #+#    #+#              #
#    Updated: 2019/01/07 18:00:04 by crenaudi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
LIB = t
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -c
SRC = validate.c		\
	  print_short.c		\
	  fillit.c

.PHONY: all fclean re

all:
	@$(CC) $(CFLAGS) $(LIB) $(SRC)
	@echo ".........."
	@echo "| all ok |"
	@echo ".........."

fclean:
	@$(RM) $(NAME)
	@echo "............."
	@echo "| fclean ok |"
	@echo "............."

re: fclean all











