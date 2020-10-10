#include "../includes/fdf.h"

size_t	skip_space(size_t start, char const *str, char space)
{
	size_t i;

	i = start;
	while (str[i] == space && str[i])
		i++;
	return (i);
}

size_t	skip_word(size_t start, char const *str, char space)
{
	size_t i;

	i = start;
	while (!(str[i] == space) && str[i] != '\0')
		i++;
	return (i);
}

void	strsplit_free(char ***str_arr)
{
	int	i;

	if (str_arr && *str_arr)
	{
		i = -1;
		while ((*str_arr)[++i])
			ft_strdel(&((*str_arr)[i]));
		free(*str_arr);
		*str_arr = NULL;
	}
}


int		get_wc(char *str)
{

	size_t	i;
	size_t	j;
	int		wc;

	wc = 0;
	i = skip_space(0, str, ' ');
	while (str[i])
	{
		j = skip_space(i, str, ' ');
		i = skip_word(i, str, ' ');
		if (j != i)
			wc++;
		i = skip_space(i, str, ' ');
	}
	return (wc);
}