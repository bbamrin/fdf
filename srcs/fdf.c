/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkathy <pkathy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 19:54:18 by pkathy            #+#    #+#             */
/*   Updated: 2019/09/04 19:57:41 by pkathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>
t_fdf	*init()
{
	t_fdf *fdf;

	if (!(fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf))))
		return (0);
	return (fdf);
}

void print_int_tab(t_fdf *fdf)
{
	for (int i = 0; i < fdf->height; ++i)
	{
		for (int j = 0; j < fdf->width; ++j)
			printf("%d ", fdf->map[i][j]);
		printf("\n");
	}
}

void 	free_fdf(t_fdf *fdf)
{
	int	i;

	i = -1;
	while (++i < fdf->height)
		ft_memdel((void **) &(fdf->map[i]));
	free((fdf->map));
	free(fdf);
}

int		main(int argc, char **argv)
{
	t_fdf *fdf;

	if (argc != 2)
		return (0);
	if (!(fdf = init()))
		return (0);
	if (!create_map(fdf, argv[1]))
	{
		//printf("test\n");
		free_fdf(fdf);
		return (0);
	}
	print_int_tab(fdf);
	free_fdf(fdf);
	return (0);
}
