/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:07:42 by aguede            #+#    #+#             */
/*   Updated: 2023/02/09 21:51:57 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int nb);
int		ft_putunsignednbr(unsigned int nb);
int		ft_putptr(unsigned long long ptr_to_hex);
int		ft_printf(const char *stringficelle, ...);
int		ft_putunsignednbr(unsigned int nb);
int		ft_puthex(unsigned int to_hex, const char typeoslm);
int		ft_whichtype(char a, va_list arguments);
int		ft_add0x_putpointer(unsigned long long ptr_to_hex);
int		ft_putpercent(void);

#endif
