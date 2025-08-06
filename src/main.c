/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 19:13:01 by latabagl          #+#    #+#             */
/*   Updated: 2025/08/06 23:30:39 by latabagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    play_game(void);

// free memory !!!
int main(int argc, char **argv)
{
    t_map   map;

    if (argc != 2)
    {
        return (1);
    }
    map.grid = NULL;
    check_map(argv[1], &map);
    play_game();
    return (0);
}

void    play_game(void)
{
    ft_printf("What a game !\n");
}
