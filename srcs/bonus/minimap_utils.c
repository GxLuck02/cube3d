/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttreichl <ttreichl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:38:57 by ttreichl          #+#    #+#             */
/*   Updated: 2024/12/12 17:39:41 by ttreichl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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