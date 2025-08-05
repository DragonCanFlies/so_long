/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 19:13:01 by latabagl          #+#    #+#             */
/*   Updated: 2025/08/05 17:50:31 by latabagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    play_game(void);
int     is_map_valid(char *map);

int main(int argc, char **argv)
{
    char *map;

    if (argc != 2)
    {
        return (1);
    }
    map = argv[1];
    if (!is_map_valid(map))
    {
        return (1);
    }
    play_game();
    return (0);
}

void    play_game(void)
{
    ft_printf("What a game !");
}

int     is_map_valid(char *map)
{
    (void) map;
    return (1);
}