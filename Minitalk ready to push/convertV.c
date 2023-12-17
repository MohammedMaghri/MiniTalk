/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertV.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:48:48 by mmaghri           #+#    #+#             */
/*   Updated: 2023/12/17 13:07:55 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	lencount(char *string)
{
	int	index ;

	index = 0 ;
	while (string[index])
	{
		index++ ;
	}
	return (index);
}

char	*reverse(char *string)
{
	int		index;
	int		incre;
	char	*allocation ;

	allocation = malloc(sizeof(char) * lencount(string)) + 1;
	incre = 0;
	index = lencount(string) - 1;
	while (index >= 0)
	{
		allocation[incre] = string[index];
		index-- ;
		incre++ ;
	}
	allocation[incre] = '\0';
	free(string);
	return (allocation);
}

char	*inaryconv(unsigned char AR)
{
	int		i;
	int		j;
	char	res;
	char	*string;
	int		arr[7];

	res = 0;
	i = 7 ;
	j = 7 ;
	string = malloc(sizeof(string) * 8);
	while (i >= 0)
	{
		arr[i] = (AR >> i) & 1;
		i--;
	}
	string[8] = '\0';
	while (j >= 0)
	{
		string[j] = arr[j] + '0';
		j--;
	}
	string = reverse(string);
	return (string);
}

void	checkthis(char string, pid_t pid)
{
	if (string == '1')
	{
		kill(pid, SIGUSR1);
		usleep(20);
	}
	else if (string == '0')
	{
		kill(pid, SIGUSR2);
		usleep(20);
	}
}

void	minishare(char string, int pid)
{
	char	*res ;
	int		index ;

	res = inaryconv(string);
	index = 0 ;
	while (res[index])
	{
		checkthis(res[index], pid);
		index++ ;
		if (index == 8)
		{
			usleep(50);
		}
	}
}
