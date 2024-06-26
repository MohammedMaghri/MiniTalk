/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reciver.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:40:31 by mmaghri           #+#    #+#             */
/*   Updated: 2023/12/16 14:16:12 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "minitalk.h"

void	topaste(int signal)
{
	static unsigned char	c;
	static int				n;

	if (signal == SIGUSR1 && n != 8)
		c |= (1 << n++);
	else if (signal == SIGUSR2 && n != 8)
		c |= (0 << n++);
	if (n == 8)
	{
		printf("%c", reverse_bits(c));
		fflush(stdout);
		c = 0;
		n = 0;
	}
}

int	main(void)
{
	printf("Receiver process PID: %d\n", getpid());
	signal(SIGUSR1, topaste);
	signal(SIGUSR2, topaste);
	while (1)
	{
		pause();
	}
	return (0);
}
