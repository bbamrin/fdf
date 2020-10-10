/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkathy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:30:46 by pkathy            #+#    #+#             */
/*   Updated: 2019/09/26 19:07:45 by pkathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H
# define ERROR_CODE -10
# define EMPTY_CELL  -1
# define PLAYER_CELL -2
# define ENEMY_CELL -3
# define MAXINT	2147483647
# define MODE 0

# include "../libft/libft.h"
# include "../libft/get_next_line.h"

typedef struct	s_fdf
{
	int 	height;
	int 	width;
	int 	**map;
}				t_fdf;

int				get_wc(char *str);
void			strsplit_free(char ***str_arr);
int				create_map(t_fdf *fdf, char *fname);
#endif
