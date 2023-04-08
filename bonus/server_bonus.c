/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 09:55:43 by nel-baz           #+#    #+#             */
/*   Updated: 2023/04/08 14:44:27 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

void	exit_func(char *str)
{
	ft_printf("\033[0;31mError, %s\n", str);
	exit(1);
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
		if (s.res == 0b00000000)
			kill(info->si_pid, SIGUSR1);
		else if (s.res > 0b00000000 && s.res < 0b10000000)
			write(1, &(s.res), 1);
		else
		{
			numb_bytes(&s);
			unicode_handler(&s);
		}
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
