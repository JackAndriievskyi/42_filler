/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_figure.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:24:16 by yandriie          #+#    #+#             */
/*   Updated: 2018/04/04 11:03:48 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	set_fig_size(t_data *data, char *str)
{
	if (str &&
		ft_strlen(str) > FIG_STR_SIZE &&
		!ft_strncmp(FIG_STR, str, FIG_STR_SIZE))
	{
		str += FIG_STR_SIZE;
		if ((data->frow = ft_atoi(str)) < 1)
			return (1);
		while (*str >= '0' && *str <= '9')
			str++;
		if ((data->fcol = ft_atoi(str)) < 1)
			return (1);
		return (0);
	}
	return (1);
}

static int	set_fig_data(t_data *data)
{
	size_t	i;
	char	*tmp;

	if (!(data->fig = (char **)ft_memalloc(data->frow * (sizeof(char *)))))
		return (1);
	i = -1;
	while (++i < data->frow)
		if (!(data->fig[i] = (char *)ft_memalloc(data->fcol * (sizeof(char)))))
			return (1);
	i = -1;
	tmp = NULL;
	while (++i < data->frow)
	{
		if ((size_t)get_next_line(0, &tmp) != FIG_STR_OFF + data->fcol)
			return (1);
		data->fig[i] =
			ft_strncpy(data->fig[i], tmp + FIG_STR_OFF, data->fcol);
		ft_strdel(&tmp);
	}
	return (0);
}

static int	set_fig_valid(t_data *data)
{
	size_t	i;
	size_t	j;
	size_t	ds[2];

	i = -1;
	ds[0] = 0;
	ds[1] = 0;
	while (++i < data->frow && (j = -1) == (size_t)-1)
		while (++j < data->fcol)
		{
			(data->fig[i][j] == FIGURE_CHR) ? ds[0]++ : (size_t)ds[0];
			(data->fig[i][j] == SHAPE_CHR) ? ds[1]++ : (size_t)ds[1];
		}
	if (!ds[1] || ds[0] + ds[1] != i * j)
		return (1);
	return (0);
}

int			set_figure(t_data *data, char *str)
{
	if (set_fig_size(data, str))
		return (1);
	if (set_fig_data(data))
		return (1);
	if (set_fig_valid(data))
		return (1);
	return (0);
}
