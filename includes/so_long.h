/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 19:13:14 by latabagl          #+#    #+#             */
/*   Updated: 2025/08/06 22:42:59 by latabagl         ###   ########.fr       */
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

typedef struct 	s_map
{
    char    **grid;        // The 2D array storing the map
    int     rows;          // Number of rows
    int     cols;          // Number of columns
    int     collectibles;  // Count of collectibles (C)
    int     exits;         // Count of exits (E)
    int     players;       // Count of players (P)
}   			t_map;

typedef enum e_error
{
    INVALID_FILENAME, // it's 0 !
    OPEN_MAP,
    MALLOC_ERR
}            t_error;

void    check_map(char *filename, t_map *map);
int	    is_filename_valid(char *filename);
void	read_map(t_map *map, char *filename);
void	count_rows(t_map *map, char *filename);

void	handle_error(int fd, int error);
void	print_error_message(int error);
void	free_memory(void);

// debug to be erased
void	print_map(t_map *map);

#endif