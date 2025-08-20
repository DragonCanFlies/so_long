/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:25:16 by latabagl          #+#    #+#             */
/*   Updated: 2025/08/18 23:11:33 by latabagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*error_messages[] = {
	"Invalid filename, extension must be .ber.",
	"Map can't be opened.",
	"Memory allocation failure.",
	"Map must have minimum 3 rows and 3 cols.",
	"Map must be rectangular.",
	"Map characters must be P, C, E, 0 and 1."
};

// error handling
void	handle_error(int fd, int error)
{
	free_memory();
	if (fd != -1)
		close (fd);
	print_error_message(error);
	exit (1) ;
}

void	print_error_message(int error)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error_messages[error], 2);
	ft_putstr_fd("\n", 2);
}

// free memory
void	free_memory(void)
{
	ft_printf("free memory\n");
}

void	remove_grid_newlines(char **grid)
{
	char	**grid_walker;
	size_t	len;
	
	grid_walker = grid;
	while (*grid_walker)
	{
		len = ft_strlen(*grid_walker);
		if ((*grid_walker)[len - 1] == '\n')
			(*grid_walker)[len - 1] = '\0';
		grid_walker++;
	}
	return ;
}
