/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:49:47 by latabagl          #+#    #+#             */
/*   Updated: 2025/08/06 23:36:38 by latabagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_map *map)
{
	unsigned int	i;

	while (map->grid[i])
	{
		ft_printf("%s", map->grid[i]);
		i++;
	}
}

// void	check_map(char *filename, t_map *map)
// {
// 	if (!is_filename_valid(filename))
// 		handle_error(-1, INVALID_FILENAME); 
// 	map->rows = 0;
// 	iterate_map(map, filename, count_line);
// 	map->grid = malloc((map->rows + 1) * sizeof(char *));
// 	if (!map->grid)
// 		handle_error(-1, MALLOC_ERR);
// 	iterate_map(map, filename, store_line);
// 	map->grid[map->rows] = NULL;
// 	print_map(map);
// }

// void	iterate_map(t_map *map, char *filename, 
// 	void (*func)(char *, t_map *, unsigned int))
// {
// 	char			*line;
// 	unsigned int	i;
// 	int				fd;

// 	fd = open(filename, O_RDONLY);
// 	if (fd == -1)
// 		handle_error(-1, OPEN_MAP);
// 	i = 0;
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		func(line, map, i);
// 		line = get_next_line(fd);
// 		i++;
// 	}	
// 	close(fd);
// }

// void	count_line(char *line, t_map *map, unsigned int i)
// {
// 	(void) i;
// 	map->rows++;
// 	free(line);
// }

// void	store_line(char *line, t_map *map, unsigned int i)
// {
// 	map->grid[i] = line;
// }



