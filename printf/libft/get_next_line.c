/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nuovo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:31:18 by cfavero           #+#    #+#             */
/*   Updated: 2018/04/25 16:22:40 by cfavero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*get_list(t_list **start, int fd)
{
	t_list *tmp;

	tmp = *start;
	while (tmp)
	{
		if (tmp->content_size == (size_t)fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew(NULL, 0);
	tmp->content_size = fd;
	tmp->content = ft_strnew(0);
	ft_lstadd(start, tmp);
	return (tmp);
}

static int		get_line(char **line, char *content)
{
	char	*tr;

	if ((tr = ft_strchr(*line, '\n')))
	{
		*tr = '\0';
		tr = tr + 1;
		*line = ft_strdup(*line);
		content = ft_strcpy(content, tr);
		return (1);
	}
	else if (ft_strlen(content) > 0)
	{
		*content = '\0';
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*temp;
	t_list			*start;
	char			*buff;
	int				byte;

	start = get_list(&temp, fd);
	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	buff = ft_strnew(BUFF_SIZE + 1);
	while (!(ft_strchr(buff, '\n')))
	{
		byte = read(fd, buff, BUFF_SIZE);
		buff[byte] = '\0';
		if (byte < 0)
			return (-1);
		*line = ft_strjoin(start->content, buff);
		if (byte == 0)
			return (get_line(line, start->content));
		free(start->content);
		start->content = *line;
	}
	free(buff);
	return (get_line(line, start->content));
}
