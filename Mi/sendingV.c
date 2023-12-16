/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sendingV.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:49:06 by mmaghri           #+#    #+#             */
/*   Updated: 2023/12/16 13:32:42 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "minitalk.h"

int	atoifunction(char *string)
{
	int		index;
	int		number;
	int		negat;

	number = 0;
	negat = 1 ;
	index = 0 ;
	while (string[index] && string[index] >= 9 && string[index] <= 13)
		index++ ;
	if (string[index] == '-' || string[index] == '+')
	{
		if (string[index] == '-')
			negat *= -1 ;
		index++;
	}
	while (string[index] >= '0' && string[index] <= '9')
	{
		number = (number * 10) + (string[index] - '0');
		index++ ;
	}
	return (number * negat);
}

void	paste(char string)
{
	write(1, &string, 1);
}

int	main(int argc, char *argv[])
{
	pid_t	pid ;
	int		i;

	if (argc != 3)
	{
		printf("Usage: %s <pid>\n", argv[0]);
		return (1);
	}
	i = 0 ;
	pid = (pid_t)atoifunction(argv[1]);
	while (argv[2][i] != '\0')
	{
		minishare(argv[2][i], pid);
		i++ ;
	}
}
