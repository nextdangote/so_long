/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguede <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:53:43 by aguede            #+#    #+#             */
/*   Updated: 2023/02/15 14:53:47 by aguede           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
int		the_strlen(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_empty(char *stock);
char	*ft_extract(char *stock);
char	*ft_lire_stock(int fd, char *stock);

#endif
