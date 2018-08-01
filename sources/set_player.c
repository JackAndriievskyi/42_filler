/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 13:42:16 by yandriie          #+#    #+#             */
/*   Updated: 2018/04/04 11:03:33 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		set_player(t_data *data, char *str)
{
	if (str &&
		ft_strlen(str) > PLAYER_STR_SIZE &&
		!ft_strncmp(PLAYER_STR, str, PLAYER_STR_SIZE) &&
		(str[10] == '1' || str[10] == '2'))
	{
		data->pchr = SET_CHR(str[PLAYER_STR_SIZE] % 2);
		data->ochr = SET_CHR((str[PLAYER_STR_SIZE] + 1) % 2);
		return (0);
	}
	return (1);
}
