/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_adv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 15:56:45 by yandriie          #+#    #+#             */
/*   Updated: 2018/04/04 11:05:16 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static size_t	this_adv(t_data *data, size_t x, size_t y)
{
	size_t	i;
	size_t	j;
	size_t	adv;
	size_t	res;

	i = -1;
	adv = 0;
	res = -1;
	while (++i < data->mrow && (j = -1) == (size_t)-1)
		while (++j < data->mcol)
			if (data->map[i][j] == data->ochr)
			{
				adv = SET_ADV(DIF(x, j), DIF(y, i));
				if (adv < res)
					res = adv;
			}
	return (res);
}

size_t			count_adv(t_data *data, size_t x, size_t y)
{
	size_t	i;
	size_t	j;
	size_t	cadv;

	cadv = 0;
	i = -1;
	while (++i < data->frow && (j = -1) == (size_t)-1)
		while (++j < data->fcol)
			if (data->fig[i][j] == SHAPE_CHR)
				cadv += this_adv(data, j + x, i + y);
	return (cadv);
}
