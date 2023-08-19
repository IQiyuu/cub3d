/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:09:02 by dgoubin           #+#    #+#             */
/*   Updated: 2023/08/19 13:38:16 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_window(t_game *game)
{
    game->win = mlx_init(WIDTH, HEIGHT, "cub3d", true);
    if (!game->win)
    {
        game->error = OPEN_WIN;
        ft_exit(game);
    }
    mlx_loop_hook(game->win, loop, game);
    mlx_key_hook(game->win, key, game);
    mlx_close_hook(game->win, ft_close, game);
    mlx_loop(game->win);
    return ;
}
