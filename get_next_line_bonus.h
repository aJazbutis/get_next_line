/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajazbuti <ajazbuti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:17:47 by ajazbuti          #+#    #+#             */
/*   Updated: 2021/11/12 16:18:14 by ajazbuti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strchr(char *s);
size_t	ft_len(char *s);
char	*ft_strdup(char *s);
char	*ft_substr(char	*s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
#endif
