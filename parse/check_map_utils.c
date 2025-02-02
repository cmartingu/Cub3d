/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:55:53 by carlos-m          #+#    #+#             */
/*   Updated: 2024/08/01 17:55:57 by carlos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	check_textures(char	**split, t_data *game)
{
	if (split[0][0] == 78 && split[0][1] == 79 && split[0][2] == 0)
		fill_texture(split[1], NO, game);
	else if (split[0][0] == 83 && split[0][1] == 79 && split[0][2] == 0)
		fill_texture(split[1], SO, game);
	else if (split[0][0] == 87 && split[0][1] == 69 && split[0][2] == 0)
		fill_texture(split[1], WE, game);
	else if (split[0][0] == 69 && split[0][1] == 65 && split[0][2] == 0)
		fill_texture(split[1], EA, game);
	else if (split[0][0] == 70 && split[0][1] == 0)
		check_color(split[1], F, game);
	else if (split[0][0] == 67 && split[0][1] == 0)
		check_color(split[1], C, game);
	else
		ft_exit(0, game);
}

void	fill_texture(char *path, t_ident ident, t_data	*game)
{
	path[ft_strlen(path) - 1] = '\0';
	if (ident == NO)
	{
		game->mapcheck.no++;
		game->north.path = ft_strdup(path);
	}
	else if (ident == SO)
	{
		game->mapcheck.so++;
		game->south.path = ft_strdup(path);
	}
	else if (ident == WE)
	{
		game->mapcheck.we++;
		game->west.path = ft_strdup(path);
	}
	else if (ident == EA)
	{
		game->mapcheck.ea++;
		game->east.path = ft_strdup(path);
	}
	if (game->mapcheck.no > 1 || game->mapcheck.so > 1 || \
	game->mapcheck.we > 1 || game->mapcheck.ea > 1)
		ft_exit(1, game);
}

void	fill_color(t_data *game, t_ident ident, t_color	*color, char *rgb)
{
	char	**split;

	if (ident == F)
		game->mapcheck.f++;
	else if (ident == C)
		game->mapcheck.c++;
	if (game->mapcheck.c > 1 || game->mapcheck.f > 1)
		ft_exit(0, game);
	split = ft_split(rgb, 44);
	color->r = ft_atoi(split[0]);
	color->g = ft_atoi(split[1]);
	color->b = ft_atoi(split[2]);
	ft_free(split);
}

void	check_color(char	*rgb, t_ident ident, t_data *game)
{
	char	**split;
	int		r;
	int		g;
	int		b;
	int		i;

	split = ft_split(rgb, 44);
	if (!split)
		ft_exit(1, game);
	i = 0;
	while (split[i] != NULL)
		i++;
	if (i != 3)
		ft_exit(1, game);
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	ft_free(split);
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		ft_exit(0, game);
	if (ident == F)
		fill_color(game, F, &game->floor, rgb);
	else if (ident == C)
		fill_color(game, C, &game->ceiling, rgb);
}

void	check_inmap(t_data *game)
{
	if (game->mapcheck.no == 1 && game->mapcheck.so == 1 && \
		game->mapcheck.we == 1 && game->mapcheck.ea == 1 && \
		game->mapcheck.f == 1 && game->mapcheck.c == 1)
		game->mapcheck.in_map = 1;
}
