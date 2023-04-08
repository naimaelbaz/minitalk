/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:24:27 by nel-baz           #+#    #+#             */
/*   Updated: 2023/04/08 14:52:32 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "../ft_printf/ft_printf.h"

void	exit_func(char *str)
{
	ft_printf("\033[0;31mError, %s\n", str);
	exit(1);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				signe;
	unsigned long	res;

	res = 0;
	signe = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			signe *= (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i++] - 48);
		if (res >= 9223372036854775807)
		{
			if (signe == 1)
				return (-1);
			else
				return (0);
		}
	}
	return (res * signe);
}

void	sent_msg(int pid, char chr)
{
	int		i;
	int		c;
	char	r;

	i = 7;
	while (i >= 0)
	{
		c = chr >> i;
		r = c & 1;
		if (r)
		{
			if (kill(pid, SIGUSR1) != 0)
				exit_func("🙁");
		}
		else
		{
			if (kill(pid, SIGUSR2) != 0)
				exit_func("🙁");
		}
		i--;
		usleep(900);
	}
}

void	msg_res(int i)
{
	if (i == SIGUSR1)
		ft_printf("\033[0;32mMessage received");
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc == 3)
	{
		signal(SIGUSR1, &msg_res);
		pid = ft_atoi(argv[1]);
		i = 0;
		while (argv[2][i])
			sent_msg(pid, argv[2][i++]);
		sent_msg(pid, '\0');
	}
	else
		exit_func("invalid number of param 🙁");
	return (0);
}
