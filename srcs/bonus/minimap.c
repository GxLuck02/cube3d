/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttreichl <ttreichl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:08:36 by shmoreno          #+#    #+#             */
/*   Updated: 2024/12/12 15:25:53 by ttreichl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
          1111111111111111111111111
          1000000000110000000000001  
          1011000001110000000000001
          100100000000N0000000000001
111111111011000001110000000000001
100000000011000001110111110111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110001
11110111 1110101 101111010001     
11111111 1111111 111111111111

#define NORTH_WALL_TEXTURE	0xFFFFFF // White
#define SOUTH_WALL_TEXTURE	0xFF0000 // Red
#define EAST_WALL_TEXTURE	0x00FF00 // Green
#define WEST_WALL_TEXTURE	0x0000FF // Blue
#define CEILING_COLOR		0x87CEEB // Sky blue
#define FLOOR_COLOR			0x8B4513 // Brown
*/

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}
void chose_color_tiles_and_draw_it(t_game *game, t_coord coord, t_coord pixel)
{
	if (game->map->map[coord.y][coord.x] == '1')
		my_mlx_pixel_put(&game->img, coord.x * TILES_SIZE + pixel.x, coord.y * TILES_SIZE + pixel.y, FLOOR_COLOR);
	else if (game->map->map[coord.y][coord.x] == '0' || ft_strchr("NSEW", game->map->map[coord.y][coord.x]) != NULL)
		my_mlx_pixel_put(&game->img, coord.x * TILES_SIZE + pixel.x, coord.y * TILES_SIZE + pixel.y, NORTH_WALL_TEXTURE);
}

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
}

void	draw_minmap(t_game *game)
{
	draw_tiles(game);
	draw_player(game);
	
}
