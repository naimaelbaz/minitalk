# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 10:00:07 by nel-baz           #+#    #+#              #
#    Updated: 2023/04/08 14:55:35 by nel-baz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C = client

NAME_S = server

NAME_CB = client_bonus

NAME_SB = server_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS_C = src/client.c

SRCS_S = src/server.c

SRCS_CB = bonus/client_bonus.c

SRCS_SB = bonus/server_bonus.c bonus/server_utils_bonus.c

OBJS_C = $(SRCS_C:.c=.o)

OBJS_S = $(SRCS_S:.c=.o)

OBJS_CB = $(SRCS_CB:.c=.o)

OBJS_SB = $(SRCS_SB:.c=.o)

src/%.o: src/%.c ft_printf/ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c server_bonus.h ft_printf/ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

all : ft_printf $(NAME_C) $(NAME_S)

bonus : ft_printf $(NAME_CB) $(NAME_SB)

ft_printf :
	make -C ft_printf all

$(NAME_C):  $(OBJS_C)
	$(CC) $(CFLAGS) $(OBJS_C) ./ft_printf/libftprintf.a -o $(NAME_C)

$(NAME_S):  $(OBJS_S)
	$(CC) $(CFLAGS) $(OBJS_S) ./ft_printf/libftprintf.a -o $(NAME_S)

$(NAME_CB):  $(OBJS_CB)
	$(CC) $(CFLAGS) $(OBJS_CB) ./ft_printf/libftprintf.a -o $(NAME_CB)

$(NAME_SB):  $(OBJS_SB)
	$(CC) $(CFLAGS) $(OBJS_SB) ./ft_printf/libftprintf.a -o $(NAME_SB)

clean:	
	rm -rf $(OBJS_C) $(OBJS_S) $(OBJS_CB) $(OBJS_SB)
	make -C ft_printf/ clean

fclean:	clean
	rm -rf $(NAME_C) $(NAME_S) $(NAME_CB) $(NAME_SB)
	make -C ft_printf/ fclean

re : fclean all

.PHONY : all fclean clean re ft_printf