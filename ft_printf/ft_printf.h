/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:52:48 by nel-baz           #+#    #+#             */
/*   Updated: 2022/11/08 22:40:12 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *ptr, ...);
int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_putnbr(int index);
int		ft_putnbrhex(unsigned long long index, char *base, int b);
int		ft_putpointer(unsigned long long n);

#endif