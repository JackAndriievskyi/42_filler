/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 12:57:24 by yandriie          #+#    #+#             */
/*   Updated: 2018/04/04 11:04:20 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		free_this(t_data *data, int f, char **str)
{
	size_t	i;

	ft_strdel(str);
	i = 0;
	if (data->map && f >= 0)
	{
		while (i < data->mrow)
			if (data->map[i++])
				ft_strdel(&(data->map[i - 1]));
		free(data->map);
		data->map = NULL;
	}
	i = 0;
	if (data->fig && f <= 0)
	{
		while (i < data->frow)
			if (data->fig[i++])
				ft_strdel(&(data->fig[i - 1]));
		free(data->fig);
		data->fig = NULL;
	}
	return (1);
}

static void		destine(t_data *data)
{
	size_t	i;
	size_t	j;
	size_t	cadv;
	size_t	padv;

	i = -1;
	padv = -1;
	data->x = 0;
	data->y = 0;
	while (++i < data->mrow - data->frow + 1 && (j = -1) == (size_t)-1)
		while (++j < data->mcol - data->fcol + 1)
			if (place_valid(data, j, i))
			{
				cadv = count_adv(data, j, i);
				if (cadv <= padv)
				{
					data->x = j;
					data->y = i;
					padv = cadv;
				}
			}
	ft_putnbr(data->y);
	ft_putchar(' ');
	ft_putnbr(data->x);
	ft_putchar('\n');
}

static int		set(t_data *data, char **str)
{
	if (*str &&
		ft_strlen(*str) > MAP_STR_SIZE &&
		!ft_strncmp(MAP_STR, *str, MAP_STR_SIZE))
	{
		free_this(data, 1, NULL);
		if (set_map(data, *str))
			return (free_this(data, 0, str));
		ft_strdel(str);
		return (-1);
	}
	if (*str &&
		ft_strlen(*str) > FIG_STR_SIZE &&
		!ft_strncmp(FIG_STR, *str, FIG_STR_SIZE))
	{
		free_this(data, -1, NULL);
		if (set_figure(data, *str))
			return (free_this(data, 0, str));
		ft_strdel(str);
		return (0);
	}
	return (free_this(data, 0, str));
}

int				main(void)
{
	t_data	data;
	int		ret;
	char	*str;

	ft_bzero(&data, sizeof(t_data));
	str = NULL;
	if (get_next_line(0, &str) > -1)
		if (set_player(&data, str))
			return (1);
	ft_strdel(&str);
	while (get_next_line(0, &str) > -1)
	{
		if ((ret = set(&data, &str)) == 1)
			return (1);
		if (ret == -1)
		{
			if (get_next_line(0, &str) == -1)
				return (free_this(&data, 0, &str));
			if (set(&data, &str))
				return (1);
		}
		destine(&data);
	}
	return (0);
}
