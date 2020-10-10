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


int		parse_size(t_fdf *fdf, char *fname)
{
	char	*str;
	int		fd;

	str = 0;
	fdf->height = 0;
	fdf->width = 0;
	if ((fd = open(fname, O_RDONLY)) < 0)
		return (-1);
	while (get_next_line(fd, &str) > 0)
	{
		if (!(fdf->height))
			fdf->width = get_wc(str);
		fdf->height++;
		ft_strdel(&str);
	}
	if (close(fd) == -1)
		return (0);
	return (fdf->height > 0 && fdf->width > 0);
}

int 	fill_map_line(t_fdf *fdf, char *str, int i)
{
	char	**str_arr;
	int		j;

	j = 0;
	if (!(str_arr = ft_strsplit(str, ' ')))
		return (0);
	while (str_arr[j] && j < fdf->width)
	{
		fdf->map[i][j] = ft_atoi(str_arr[i]);
		i++;
	}
	strsplit_free(&str_arr);
	return (1);
}

int 	read_map(t_fdf *fdf, char *fname)
{
	char	*str;
	int		fd;
	int 	i;

	str = 0;
	i = -1;
	if ((fd = open(fname, O_RDONLY)) < 0)
		return (-1);
	while (++i < fdf->height && get_next_line(fd, &str) > 0)
	{

		ft_strdel(&str);
	}
	if (close(fd) == -1)
		return (0);
	return (fdf->height > 0 && fdf->width > 0);
}

int		create_map(t_fdf *fdf, char *fname)
{
	char	*str;
	int		fd;
	int 	i;

	if (parse_size(fdf, fname))
		return (0);
	if (!(fdf->map = (int **)ft_memalloc(sizeof(int *) * fdf->height)))
		return (0);
	str = 0;
	i = -1;
	if ((fd = open(fname, O_RDONLY)) < 0)
		return (0);
	while (++i < fdf->height && get_next_line(fd, &str) > 0)
	{
		if (!(fdf->map[i] = (int *)ft_memalloc(sizeof(int) * fdf->width)))
			return (0);
		if (!fill_map_line(fdf, str, i))
			return (0);
		ft_strdel(&str);
	}
	if (close(fd) == -1)
		return (0);
	return (1);
}