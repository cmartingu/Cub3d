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

#include "cube.h"

int	main(int argc, char **argv)
{
	t_data	game;
	int		fd;

	if (argc != 2)
		ft_exit(0, &game);
	if (ft_strncmp(".cub", argv[1] + ft_strlen(argv[1]) - 4, 4) != 0)
		ft_exit(0, &game);
	init_data(&game);
	game.mapname = ft_strdup(argv[1]);
	fd = open(game.mapname, O_RDONLY);
	if (fd < 0)
		ft_exit(0, &game);
	check_map(&game, fd);
	check_imgs(&game);
	fill_map(&game);
	gameplay(&game);
	free_game_data(&game);
	return (0);
}
