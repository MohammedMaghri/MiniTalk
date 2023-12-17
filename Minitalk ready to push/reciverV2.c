/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reciverV2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:21:23 by mmaghri           #+#    #+#             */
/*   Updated: 2023/12/17 13:09:21 by mmaghri          ###   ########.fr       */
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

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	res;
	int				count;

	res = 0;
	count = 8;
	while (count)
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
		count--;
	}
	return (res);
}
