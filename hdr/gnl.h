/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 16:58:00 by gshona            #+#    #+#             */
/*   Updated: 2021/02/06 03:44:38 by asumerag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		gnl(int fd, char **line);
int		end_line(char *s);
size_t	ft_strlen(const char *s);
char	*ft_stradd(char *s1, char *s2);
char	*new_str(char *s);
char	*next_str(char *s);

#endif
