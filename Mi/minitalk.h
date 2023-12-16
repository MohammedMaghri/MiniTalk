/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:12:23 by mmaghri           #+#    #+#             */
/*   Updated: 2023/12/16 14:10:00 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H 
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

unsigned char	reverse_bits(unsigned char octet);
void			print_bits(unsigned char octet);
int				lencount(char *string);
char			*reverse(char *string);
char			*inaryconv(unsigned char AR, int pid);
void			checkthis(char string, pid_t pid);
void			minishare(char string, int pid);
int				atoifunction(char *string);
void			handle_signal(int signal);
void			putnbr(int number);
void			paste(char string);
void			binary_to_ascii( char *binary_str);
void			functieight(int signal);

#endif 
