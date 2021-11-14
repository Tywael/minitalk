/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalthaus <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 11:35:18 by yalthaus          #+#    #+#             */
/*   Updated: 2021/11/14 16:58:48 by yalthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "minitalk.h"

int	ft_str_isnum(char *str)
{
	int	i;

	i = -1;
	while (*(str + ++i))
		if (*(str + i) < '0' || *(str + i) > '9')
			return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	char	*s;
	int		sign;
	int		rep;

	s = (char *)str;
	sign = 1;
	rep = 0;
	while ((*s >= 9 && *s <= 13) || *s == ' ')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s <= '9' && *s >= '0')
	{
		rep = (rep * 10) + (*s - '0');
		s++;
	}
	return (sign * rep);
}

void	sender(pid_t pid, char *str)
{
	int	bit;

	bit = 7;
	while (*str)
	{
		bit = 7;
		while (bit >= 0)
		{
			if (*str & (1 << bit--))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(10);
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*str;

	if (argc != 3 || ft_str_isnum(argv[1]))
	{
		write(1, "ERROR : invalid argument", 24);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	str = argv[2];
	sender(pid, str);
	sender(pid, "\n");
	return (0);
}
