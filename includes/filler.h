/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 14:47:03 by yandriie          #+#    #+#             */
/*   Updated: 2018/08/01 08:59:14 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

# define PLAYER_STR "$$$ exec p"
# define PLAYER_STR_SIZE 10
# define MAP_STR "Plateau "
# define MAP_STR_SIZE 8
# define MAP_STR_OFF 4
# define FIG_STR "Piece "
# define FIG_STR_SIZE 6
# define FIG_STR_OFF 0
# define BOARD_CHR '.'
# define XB_CHR 'X'
# define XS_CHR 'x'
# define OB_CHR 'O'
# define OS_CHR 'o'
# define FIGURE_CHR '.'
# define SHAPE_CHR '*'

# define SET_CHR(c) (((c) == 1) ? OB_CHR : XB_CHR)
# define DIF(x, y) (((x) - (y)) < 0 ? (y) - (x) : (x) - (y))
# define SET_ADV(x, y) ((x) * (x) + (y) * (y))

typedef struct	s_data
{
	char		pchr;
	char		ochr;
	size_t		mcol;
	size_t		mrow;
	size_t		fcol;
	size_t		frow;
	size_t		x;
	size_t		y;
	size_t		cadv;
	size_t		padv;
	char		**map;
	char		**fig;
}				t_data;

int				set_player(t_data *data, char *str);
int				set_map(t_data *data, char *str);
int				set_figure(t_data *data, char *str);

size_t			count_adv(t_data *data, size_t x, size_t y);
int				place_valid(t_data *data, size_t x, size_t y);

#endif
