# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/05 09:30:50 by nel-baz           #+#    #+#              #
#    Updated: 2022/11/07 16:52:24 by nel-baz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_putchar.c ft_putnbr.c ft_putnbrhex.c ft_putstr.c 

OBJS = $(SRCS:.c=.o)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $<

all : $(NAME)

$(NAME):	$(OBJS)
		ar rc $(NAME) $(OBJS)

clean:	
		rm -rf $(OBJS)

fclean:	clean
		rm -rf $(NAME)
		
re : fclean all

.PHONY : all fclean clean re bonus