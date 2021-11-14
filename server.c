/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalthaus <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 11:31:40 by yalthaus          #+#    #+#             */
/*   Updated: 2021/11/14 16:59:29 by yalthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sighandler(int signum)
{
	static char	c = 0;
	static int	bit = 7;

	if (signum == SIGUSR1)
		c |= (1 << bit);
	if (signum == SIGUSR2)
		c &= ~(1 << bit);
	bit--;
	if (bit == -1)
	{
		write(1, &c, 1);
		bit = 7;
	}
}

static void	ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			n = -n;
			write(1, "-", 1);
		}
		if (n > 9)
			ft_putnbr(n / 10);
		write(1, &"0123456789"[n % 10], 1);
	}
}

int	main(void)
{
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	while (1)
		sleep(100);
	return (0);
}
