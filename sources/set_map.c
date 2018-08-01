/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 13:48:45 by yandriie          #+#    #+#             */
/*   Updated: 2018/03/31 15:27:40 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	set_map_size(t_data *data, char *str)
{
	if (str &&
		ft_strlen(str) > MAP_STR_SIZE &&
		!ft_strncmp(MAP_STR, str, MAP_STR_SIZE))
	{
		str += MAP_STR_SIZE;
		if ((data->mrow = ft_atoi(str)) < 2)
			return (1);
		while (*str && *str == ' ')
			str++;
		while (*str >= '0' && *str <= '9')
			str++;
		if ((data->mcol = ft_atoi(str)) < 2)
			return (1);
		return (0);
	}
	return (1);
}

static int	set_map_data(t_data *data)
{
	size_t	i;
	char	*tmp;

	if (!(data->map = (char **)ft_memalloc(data->mrow * (sizeof(char *)))))
		return (1);
	i = -1;
	while (++i < data->mrow)
		if (!(data->map[i] = (char *)ft_memalloc(data->mcol * (sizeof(char)))))
			return (1);
	i = -1;
	tmp = NULL;
	while (++i < data->mrow)
	{
		if ((size_t)get_next_line(0, &tmp) != MAP_STR_OFF + data->mcol)
			return (1);
		data->map[i] =
			ft_strncpy(data->map[i], tmp + MAP_STR_OFF, data->mcol);
		ft_strdel(&tmp);
	}
	return (0);
}

static int	set_map_valid(t_data *data)
{
	size_t	i;
	size_t	j;
	size_t	dxo[3];

	i = -1;
	dxo[0] = 0;
	dxo[1] = 0;
	dxo[2] = 0;
	while (++i < data->mrow && (j = -1) == (size_t)-1)
	{
		while (++j < data->mcol)
		{
			(data->map[i][j] == BOARD_CHR) ? dxo[0]++ : (size_t)dxo[0];
			(data->map[i][j] == XB_CHR) ? dxo[1]++ : (size_t)dxo[1];
			(data->map[i][j] == XS_CHR) ? dxo[1]++ : (size_t)dxo[1];
			(data->map[i][j] == OB_CHR) ? dxo[2]++ : (size_t)dxo[2];
			(data->map[i][j] == OS_CHR) ? dxo[2]++ : (size_t)dxo[2];
		}
	}
	if (!dxo[2] || !dxo[1] || dxo[0] + dxo[1] + dxo[2] != i * j)
		return (1);
	return (0);
}

int			set_map(t_data *data, char *str)
{
	char	*trash;

	if (set_map_size(data, str))
		return (1);
	trash = NULL;
	if (get_next_line(0, &trash) <= 0)
	{
		ft_strdel(&trash);
		return (1);
	}
	else
		ft_strdel(&trash);
	if (set_map_data(data))
		return (1);
	if (set_map_valid(data))
		return (1);
	return (0);
}
