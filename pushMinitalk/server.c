/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:40:31 by mmaghri           #+#    #+#             */
/*   Updated: 2023/12/18 16:55:51 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	visualedit(int number)
{
	ft_printf("\n");
	ft_printf("   \033[0;93m");
	ft_printf(" By : [ Mohammed Maghri ]\n\n");
	ft_printf("\033[0;91m\n");
	ft_printf("       / #####       /  #####   / @@@         ");
	ft_printf("        /  ####################    ####    ####\n");
	ft_printf("      |  ######     /  ######                  ");
	ft_printf("       |  ####################    ####   ####\n");
	ft_printf("      |  ###  ##   /  ##  ###   | ###           ");
	ft_printf("                 ###             #### ####\n");
	ft_printf("      |  ###   ## /  ## | ###   | ###    *---------");
	ft_printf("-*         |  ###             ####  ####\n");
	ft_printf("      |  ###    ##  ##  | ###   | ###    |__________|");
	ft_printf("         |  ###             ####   ####\n");
	ft_printf("      |  ###      ##    | ###   | ###       ");
	ft_printf("                  |  ###             ####     ####\n");
	ft_printf("\033[1;97m      /  ###            / ###   | ### ");
	ft_printf("                        |  ###             ####      ####\n");
	ft_printf("\n");
	ft_printf("\033[0;93m\n");
	ft_printf("                                         ");
	ft_printf("{ %d }\n\n", number);
}

void	topaste(int signal)
{
	static unsigned char	c;
	static int				n;

	if (signal == SIGUSR1 && n != 8)
		c = c | (1 << n++);
	else if (signal == SIGUSR2 && n != 8)
		c |= (0 << n++);
	if (n == 8)
	{
		ft_printf("%c", c);
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
