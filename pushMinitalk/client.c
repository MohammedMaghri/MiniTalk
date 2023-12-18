/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:49:06 by mmaghri           #+#    #+#             */
/*   Updated: 2023/12/18 15:25:26 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	main(int argc, char *argv[])
{
	int		pid ;
	int		i;
	int		len;

	if (argc != 3)
	{
		ft_printf("Usage: %s <pid>\n", argv[0]);
		return (1);
	}
	i = 0 ;
	pid = atoifunction(argv[1]);
	len = lencount(argv[2]);
	while (argv[2][i] != '\0')
	{
		minishare(argv[2][i], pid);
		i++ ;
	}
	if (i == len)
	{
		ft_printf("\033[0;93m MESSAGE RECIVED SUCCEFFLY!!");
	}
}
