/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 01:33:02 by nel-baz           #+#    #+#             */
/*   Updated: 2023/04/08 13:26:43 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

void	numb_bytes(t_serv	*s)
{
	if (s->res >= 0b11000000 && s->res < 0b11100000)
		s->bytes = 2;
	if (s->res >= 0b11100000 && s->res < 0b11110000)
		s->bytes = 3;
	if (s->res >= 0b11110000)
		s->bytes = 4;
}

void	unicode_handler(t_serv *s)
{
	s->c |= s->res << s->a;
	s->a += 8;
	s->i++;
	if (s->i == s->bytes)
	{
		write(1, &(s->c), 4);
		s->i = 0;
		s->a = 0;
		s->c = 0;
	}
}

void	check_si_pid(siginfo_t *info, t_serv *s)
{
	if (s->pid != info->si_pid)
	{
		s->pid = info->si_pid;
		s->res = 0;
		s->bits = 0;
		s->a = 0;
		s->c = 0;
		s->i = 0;
	}
}
