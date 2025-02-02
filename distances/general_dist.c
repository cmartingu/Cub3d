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

float	distancia_a_bloque(t_data *data, t_img_calc *img_c)
{
	if (img_c->ang_cum >= 0 && img_c->ang_cum < 90)
		return (ang_90(data, img_c));
	else if (img_c->ang_cum >= 90 && img_c->ang_cum < 180)
		return (ang_180(data, img_c));
	if (img_c->ang_cum >= 180 && img_c->ang_cum < 270)
		return (ang_270(data, img_c));
	else if (img_c->ang_cum >= 270 && img_c->ang_cum < 360)
		return (ang_360(data, img_c));
	return (0);
}

float	angulo_rayo(t_player *player, int x)
{
	float	result;

	result = player->angle_v + 45;
	result = result - (x * (90 / WIDTH));
	if (result >= 360)
		return (result - 360);
	if (result < 0)
		return (result + 360);
	return (result);
}

int	destroy(t_data *data)
{
	mlx_destroy_window((*data).mlx_init, (*data).win);
	exit(0);
}

void	change_vision(t_data *data, int keycode)
{
	if (keycode == 65361)
		data->player->angle_v = data->player->angle_v + 5;
	if (keycode == 65363)
		data->player->angle_v = data->player->angle_v - 5;
	if (data->player->angle_v > 360)
		data->player->angle_v = data->player->angle_v - 360;
	if (data->player->angle_v < 0)
		data->player->angle_v = data->player->angle_v + 360;
	draw_img(data);
}

void	gameplay(t_data *data)
{
	data->cols--;
	data->mlx_init = mlx_init();
	if (!data->mlx_init)
	{
		fprintf(stderr, "Error initializing MLX\n");
		return ;
	}
	data->win = mlx_new_window(data->mlx_init, WIDTH, HEIGHT, "Cub3D");
	if (!data->win)
	{
		fprintf(stderr, "Error creating window\n");
		return ;
	}
	create_images(data);
	draw_img(data);
	mlx_hook(data->win, 2, 1L << 0, ft_move, data);
	mlx_hook(data->win, ON_DESTROY, 0, destroy, data);
	mlx_loop(data->mlx_init);
}
