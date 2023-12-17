/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:12:23 by mmaghri           #+#    #+#             */
/*   Updated: 2023/12/17 13:11:33 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H 
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "Printf/ft_printf.h"
# include "minitalk.h"

unsigned char	reverse_bits(unsigned char octet);
void			print_bits(unsigned char octet);
int				lencount(char *string);
char			*reverse(char *string);
char			*inaryconv(unsigned char AR);
void			checkthis(char string, pid_t pid);
void			minishare(char string, int pid);
int				atoifunction(char *string);
void			handle_signal(int signal);
void			binary_to_ascii( char *binary_str);
void			functieight(int signal);

#endif 
