/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 09:56:44 by nel-baz           #+#    #+#             */
/*   Updated: 2023/04/08 13:51:21 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "../ft_printf/ft_printf.h"

typedef struct s_server
{
	int	res;
	int	bits;
	int	bytes;
	int	pid;
	int	c;
	int	i;
	int	a;
}	t_serv;

void	numb_bytes(t_serv	*s);
void	unicode_handler(t_serv *s);
void	check_si_pid(siginfo_t *info, t_serv *s);

#endif