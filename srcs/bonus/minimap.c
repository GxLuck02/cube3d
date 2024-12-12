/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttreichl <ttreichl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:08:36 by shmoreno          #+#    #+#             */
/*   Updated: 2024/12/12 18:28:59 by ttreichl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_tiles(t_game *game)
{
	t_coord	coord;
	t_coord pixel;

	coord.y = -1;
	while (game->map->map[++coord.y])
	{
		coord.x = 0;
		while (game->map->map[coord.y][coord.x])
		{
			if (ft_isspace(game->map->map[coord.y][coord.x]) == 1)
			{
				coord.x++;
				continue;
			}
			pixel.y = 0;
			while (pixel.y < TILES_SIZE)
			{
				pixel.x = -1;
				while (++pixel.x < TILES_SIZE)
					chose_color_tiles_and_draw_it(game, coord, pixel);
				pixel.y++;
			}
			coord.x++;
		}
	}
}

/*void	draw_player_direction(t_game *game)
{
	
}*/


void	draw_player(t_game *game)
{
	t_coord pixel;

	pixel.y = 0;
	while (pixel.y < PLAYER_SIZE)
	{
		pixel.x = 0;
		while (pixel.x < PLAYER_SIZE)
		{
			my_mlx_pixel_put(&game->img, game->ply->pos_x * TILES_SIZE + \
				pixel.x, game->ply->pos_y * TILES_SIZE + pixel.y, SOUTH_WALL_TEXTURE);
			pixel.x++;
		}
		pixel.y++;
	}
	//draw_player_direction(game);
}

void	draw_minmap(t_game *game)
{
	draw_tiles(game);
	draw_player(game);
	
}
