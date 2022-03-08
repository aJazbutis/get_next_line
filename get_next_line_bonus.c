/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajazbuti <ajazbuti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:18:46 by ajazbuti          #+#    #+#             */
/*   Updated: 2021/11/12 23:46:47 by ajazbuti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_get_line(char **bfd)
{
	char	*line;
	char	*tmp;

	if (ft_strchr(*bfd))
	{
		line = ft_substr(*bfd, 0, ft_strchr(*bfd) - *bfd + 1 );
		tmp = *bfd;
		*bfd = ft_substr(ft_strchr(*bfd) + 1, 0, ft_len(*bfd) - ft_len(line));
		if (ft_len(*bfd) == 0)
		{
			free(*bfd);
			*bfd = NULL;
		}
		free(tmp);
	}
	else
	{
		line = ft_strdup(*bfd);
		free(*bfd);
		*bfd = NULL;
	}
	return (line);
}

static	void	ft_feed_buffer(int fd, char *buff, char **bfd, int size)
{
	int	rd;

	rd = 1;
	while (rd)
	{
		rd = read(fd, buff, size);
		if (rd <= 0)
			break ;
		buff[rd] = '\0';
		if (ft_strchr(buff))
		{
			*bfd = ft_strjoin(*bfd, buff);
			return ;
		}
		*bfd = ft_strjoin(*bfd, buff);
	}
}

char	*get_next_line(int fd)
{
	static char	*b_fd[1024];
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > 1023)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		if (b_fd[fd])
		{
			free(b_fd[fd]);
			b_fd[fd] = NULL;
		}
		return (NULL);
	}
	if (ft_strchr(b_fd[fd]))
		line = ft_get_line(&b_fd[fd]);
	else
	{
		ft_feed_buffer(fd, buffer, &b_fd[fd], BUFFER_SIZE);
		line = ft_get_line(&b_fd[fd]);
	}
	free(buffer);
	return (line);
}
