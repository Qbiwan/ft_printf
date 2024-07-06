# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wquek <wquek@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 10:57:34 by wquek             #+#    #+#              #
#    Updated: 2024/07/05 23:20:36 by wquek            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
SOURCEFILES = ft_printf.c ft_itoa_unsigned.c ft_printf_misc.c ft_printf_hex.c
OBJECTFILES = $(SOURCEFILES:.c=.o)
INCLUDE = -I./

all: $(NAME)
$(NAME): $(OBJECTFILES)
	@make -C Libft
	@cp Libft/libft.a $(NAME)
	@ar rc $@ $^
%.o : %.c
	$(CC) $(FLAGS) $(INCLUDE) -c $^ -o $@
clean:
	rm -f $(OBJECTFILES)
fclean: clean
	rm -f $(NAME)
	make fclean -C Libft
re: fclean all
.PHONY: all clean fclean re

