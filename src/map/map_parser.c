/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 20:55:15 by latabagl          #+#    #+#             */
/*   Updated: 2025/08/18 20:02:02 by latabagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// return TRUE if map is valid
void	check_map(char *filename, t_map *map)
{
	if (!is_filename_valid(filename))
		handle_error(-1, INVALID_FILENAME); 
	count_rows(map, filename);
	read_map(map, filename);
	remove_grid_newlines(map->grid);
	print_map(map);
	is_map_rectangular(map);
	valid_characters(map);
}

// check file extension is .ber
int	is_filename_valid(char *filename)
{
	size_t	len;
	
	len = ft_strlen(filename);
	if (len < 5)
		return (FALSE);
	return (filename[len - 5] != '/' &&
		filename[len - 4] == '.' && 
		filename[len - 3] == 'b' && 
		filename[len - 2] == 'e' && 
		filename[len - 1] == 'r' );
}

void	read_map(t_map *map, char *filename)
{
	char			*line;
	unsigned int	i;
	int				fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		handle_error(-1, OPEN_MAP);
	map->grid = malloc((map->rows + 1) * sizeof(char *));
	if (!map->grid)
		handle_error(fd, MALLOC_ERR);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map->grid[i++] = line;
		line = get_next_line(fd);
	}	
	map->grid[i] = NULL;
	close(fd);
}

void	count_rows(t_map *map, char *filename)
{
	int				fd;
	char			*line;
	unsigned int	rows;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		handle_error(-1, OPEN_MAP);
	rows = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		rows++;
		line = get_next_line(fd);
	}
	map->rows = rows;
	close (fd);
}
