/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 19:13:14 by latabagl          #+#    #+#             */
/*   Updated: 2025/08/22 16:38:25 by latabagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#define TRUE 1
#define FALSE 0

#include <fcntl.h> // open
#include <stddef.h> // size_t
#include <stdlib.h>  // exit
 
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

typedef struct 	s_map
{
    char    **grid;        // The 2D array storing the map
    int     rows;          // Number of rows
    int     cols;          // Number of columns
    int     collectibles;  // Count of collectibles (C)
    int     exit;         // Count of exits (E)
    int     player;       // Count of players (P)
}   			t_map;

typedef enum e_error
{
    INVALID_FILENAME, // it's 0 !
    OPEN_MAP,
    MALLOC_ERR,
    MAP_TOO_SMALL,
    MAP_NOT_RECTANGULAR,
    INVALID_CHARACTER,
    ONE_PLAYER,
    ONE_EXIT,
    NO_COLLECTIBLE,
    WALL_PROBLEM,
    INVALID_PATH
}            t_error;

void    check_map(char *filename, t_map *map);
int	    is_filename_valid(char *filename);
void	read_map(t_map *map, char *filename);
void	count_rows(t_map *map, char *filename);

void	handle_error(int fd, int error);
void	print_error_message(int error);
void	free_memory(void);
void	remove_grid_newlines(char **grid);

void	is_map_rectangular(t_map *map);
void	count_cols(t_map *map);
void	valid_characters(t_map *map);
void	count_and_validate_characters(char c, t_map *map);
void	is_enclosed_by_walls(t_map *map);
int	    is_border(int row, int col, t_map *map);
void	is_path_valid(t_map *map);
void	get_player_pos(int *x, int *y, t_map *map);
void	fill_grid(char **grid, int x, int y, int cols, int rows);
char	**cpy_grid(char **grid, int rows);
void	check_path(char **grid_cpy, t_map *map);

// debug to be erased
void	print_map(char **grid);

#endif