/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 02:20:58 by nel-baz           #+#    #+#             */
/*   Updated: 2023/04/08 13:56:26 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "../ft_printf/ft_printf.h"

typedef struct s_server
{
	int	res;
	int	bits;
	int	pid;
	int	c;
}	t_serv;

void	exit_func(char *str)
{
	ft_printf("\033[0;31mError, %s\n", str);
	exit(1);
}

void	check_si_pid(siginfo_t *info, t_serv *s)
{
	if (s->pid != info->si_pid)
	{
		s->pid = info->si_pid;
		s->res = 0;
		s->bits = 0;
	}
}

void	ft_handler(int n, siginfo_t *info, void *ptr)
{
	static t_serv	s;

	(void)ptr;
	check_si_pid(info, &s);
	if (n == SIGUSR2)
		s.res = (s.res << 1) | 0;
	else
		s.res = (s.res << 1) | 1;
	s.bits++;
	if (s.bits == 8)
	{
		ft_printf("%c", s.res);
		s.bits = 0;
		s.res = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	conf;

	(void)argv;
	if (argc == 1)
	{
		pid = getpid();
		ft_printf("%d\n", pid);
		conf.sa_sigaction = ft_handler;
		conf.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &conf, NULL);
		sigaction(SIGUSR2, &conf, NULL);
		while (1)
			pause();
	}
	else
		exit_func("invalid number of param 🙁");
}
