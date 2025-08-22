/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:07:56 by latabagl          #+#    #+#             */
/*   Updated: 2025/08/22 13:41:36 by latabagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

// rectangular map, min 3 rows, min 3 cols of same size
void	is_map_rectangular(t_map *map)
{	
	int	i;

	if (map->rows < 3)
		handle_error(-1, MAP_TOO_SMALL);
	count_cols(map);
	if (map->cols < 3)
		handle_error(-1, MAP_TOO_SMALL);
	i = 0;
	while (map->grid[i])
	{
		if ((int)ft_strlen(map->grid[i]) != map->cols)
			handle_error(-1, MAP_NOT_RECTANGULAR);
		i++;
	}
}

void	count_cols(t_map *map)
{
	int	i;
	
	char	*first_row = *(map->grid);
	i = 0;
	while (first_row[i])
		i++;
	map->cols = i;
}

// only allowed characters 1 0 P C E, only one P and E min 1 C
void	valid_characters(t_map *map)
{
	int	i;
	int	j;

	map->player = 0;
	map->exit = 0;
	map->collectibles = 0;
	i = 0;
	while (map->grid[i])
	{
		j = 0;
		while(map->grid[i][j])
		{
			count_and_validate_characters(map->grid[i][j], map);
			j++;
		}
		i++;
	}
	if (map->player != 1)
		handle_error(-1, ONE_PLAYER);
	else if (map->exit != 1)
		handle_error(-1, ONE_EXIT);
	else if (map->collectibles == 0)
		handle_error(-1, NO_COLLECTIBLE);
}

void	count_and_validate_characters(char c, t_map *map)
{
	if (c == 'P')
		map->player++;
	else if (c == 'E')
		map->exit++;
	else if (c == 'C')
		map->collectibles++;
	else if (c == '1' || c == '0')
		;
	else
		handle_error(-1, INVALID_CHARACTER);
}

void	is_enclosed_by_walls(t_map *map)
{
	int	col;
	int	row;

	row = 0;
	while (map->grid[row])
	{
		col = 0;
		while (map->grid[row][col])
		{
			if (is_border(row, col, map) && 
				map->grid[row][col] != '1')
					handle_error(-1, WALL_PROBLEM);
			col++;
		}
		row++;
	}
}
