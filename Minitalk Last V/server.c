/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:40:31 by mmaghri           #+#    #+#             */
/*   Updated: 2023/12/16 19:19:14 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "minitalk.h"

void	visualedit(int number)
{
	printf("\n");
	printf("   \033[0;93m                                 ");
	printf(" By : [ Mohammed Maghri ]\n\n");
	printf("\033[0;91m\n");
	printf("       / #####       /  #####   / @@@         ");
	printf("        /  ####################    ####    ####\n");
	printf("      |  ######     /  ######                  ");
	printf("       |  ####################    ####   ####\n");
	printf("      |  ###  ##   /  ##  ###   | ###           ");
	printf("                 ###             #### ####\n");
	printf("      |  ###   ## /  ## | ###   | ###    *---------");
	printf("-*         |  ###             ####  ####\n");
	printf("      |  ###    ##  ##  | ###   | ###    |__________|");
	printf("         |  ###             ####   ####\n");
	printf("      |  ###      ##    | ###   | ###       ");
	printf("                  |  ###             ####     ####\n");
	printf("\033[1;97m      /  ###            / ###   | ### ");
	printf("                        |  ###             ####      ####\n");
	printf("\n");
	printf("\033[0;93m\n");
	printf("                                         PID : { %d }\n\n", number);
}

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
	int	id ;

	id = getpid();
	visualedit(id);
	signal(SIGUSR1, topaste);
	signal(SIGUSR2, topaste);
	while (1)
	{
		pause();
	}
	return (0);
}
