/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 09:52:00 by yandriie          #+#    #+#             */
/*   Updated: 2018/03/29 13:05:34 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	formres(char **line, t_list *lst)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	tmp = (char *)lst->content;
	i = 0;
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	if (!(*line = ft_strnew(i)))
		return (-1);
	*line = (char *)ft_memmove(*line, tmp, i);
	if (tmp[i] == '\0')
	{
		ft_bzero(tmp, i);
		free(tmp);
		return (i);
	}
	j = 0;
	while (tmp[i + 1 + j] != '\0')
		j++;
	lst->content = ft_strsub(tmp, i + 1, j);
	free(tmp);
	return (i);
}

static int	readthis(char **line, t_list *lst, size_t i)
{
	char	buf[BUFF_SIZE];
	size_t	size;
	int		ret;
	int		f;
	char	*tmp;

	size = i;
	f = 0;
	while ((ret = read(lst->content_size, buf, BUFF_SIZE)) > 0)
	{
		f++;
		i = size;
		size += ret;
		if (!(lst->content = ft_realloc(lst->content, size + 1)))
			return (-1);
		ft_memmove(lst->content + i, buf, ret);
		tmp = (char *)lst->content;
		tmp[size] = 0;
		if (ft_strchr(lst->content, (int)('\n')))
			break ;
	}
	if (ret == -1 || (f == 0 && i == 0))
		return (ret);
	return (formres(line, lst));
}

static int	somefunc(char **line, t_list *lst)
{
	size_t	i;
	char	*tmp;

	tmp = (char *)lst->content;
	if (!tmp)
		return (readthis(line, lst, 0));
	i = 0;
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	if (tmp[i] == '\0')
		return (readthis(line, lst, i));
	return (formres(line, lst));
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	t_list			*tmp;

	if (fd < 0 || !line)
		return (-1);
	tmp = lst;
	while (tmp)
	{
		if (tmp->content_size == (size_t)fd)
			return (somefunc(line, tmp));
		tmp = tmp->next;
	}
	if (!(tmp = ft_lstnew(NULL, 0)))
		return (-1);
	tmp->content_size = fd;
	if (!lst)
		lst = tmp;
	return (somefunc(line, tmp));
}
