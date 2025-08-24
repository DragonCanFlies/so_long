/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:14:46 by latabagl          #+#    #+#             */
/*   Updated: 2025/08/24 16:10:09 by latabagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	is_path_valid(t_map *map)
{
	int		x;
	int		y;
	char	**grid_cpy;

	get_player_pos(&x, &y, map);
	grid_cpy = cpy_grid(map->grid, map->rows);
	fill_grid(grid_cpy, x, y, map->cols, map->rows);
	check_path(grid_cpy, map);
	free_memory(grid_cpy);
}

void	get_player_pos(int *x, int *y, t_map *map)
{
	int	col;
	int	row;

	row = 0;
	while (map->grid[row])
	{
		col = 0;
		while (map->grid[row][col])
		{
			if (map->grid[row][col] == 'P')
			{
				*x = col;
				*y = row;
				return ;
			}
			col++;
		}
		row++;
	}
}

void	fill_grid(char **grid, int x, int y, int cols, int rows)
{
	if (x < 0 || y < 0 || x >= cols || y >= rows)
		return;
	if (grid[y][x] == '1' || grid[y][x] == 'F')
		return ;
	grid[y][x] = 'F';
	fill_grid(grid, x + 1, y, cols, rows);
	fill_grid(grid, x - 1, y, cols, rows);
	fill_grid(grid, x, y + 1, cols, rows);
	fill_grid(grid, x, y - 1, cols, rows);
}

char	**cpy_grid(char **grid, int rows)
{
	char	**cpy;
	int		row;

	cpy = malloc((rows + 1) * sizeof(char *)); // !!!
	row = 0;
	while (grid[row])
	{
		cpy[row] = ft_strdup(grid[row]); // !!!
		row++;
	}
	cpy[row] = NULL;
	return (cpy);
}

void	check_path(char **grid_cpy, t_map *map)
{
	int	col;
	int	row;
	int	reachable_exit;
	int reachable_collectibles;

	reachable_collectibles = 0;
	reachable_exit = 0;
	row = 0;
	while (map->grid[row])
	{
		col = 0;
		while (map->grid[row][col])
		{
			if (grid_cpy[row][col] == 'F' &&
				map->grid[row][col]== 'E')
					reachable_exit = 1;
			if (grid_cpy[row][col] == 'F' &&
				map->grid[row][col]== 'C')
					reachable_collectibles++;
			col++;
		}
		row++;
	}
	if (!reachable_exit || reachable_collectibles != map->collectibles)
		handle_error(-1, INVALID_PATH, map->grid);
}

