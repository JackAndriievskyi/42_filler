/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 15:22:25 by yandriie          #+#    #+#             */
/*   Updated: 2018/03/31 15:23:29 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		place_valid(t_data *data, size_t x, size_t y)
{
	size_t	i;
	size_t	j;
	size_t	touch;

	touch = 0;
	i = -1;
	while (++i < data->frow)
	{
		j = -1;
		while (++j < data->fcol)
			if (data->fig[i][j] == SHAPE_CHR)
			{
				if (data->map[i + y][j + x] == data->ochr)
					return (0);
				if (data->map[i + y][j + x] == data->ochr + 32)
					return (0);
				if (data->map[i + y][j + x] == data->pchr)
					touch++;
				if (data->map[i + y][j + x] == data->pchr + 32)
					touch++;
			}
	}
	if (touch == 1)
		return (1);
	return (0);
}
