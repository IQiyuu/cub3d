/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:14:13 by dgoubin           #+#    #+#             */
/*   Updated: 2023/08/19 14:54:42 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    loop(void *param)
{
    t_game  *game;
    static  int cpt = 0;

    game = (t_game *)param;
    if (mlx_is_key_down(game->win, MLX_KEY_ESCAPE))
        ft_exit(game);
    if (game->disp_play && cpt > 20)
        refresh_text(game);
    if (cpt++ > 20)
        cpt = 0;
}

void key(mlx_key_data_t keydata, void *param)
{
    t_game  *game;

    game = (t_game *)param;
    if (keydata.key == MLX_KEY_M && keydata.action == MLX_PRESS)
    {
        game->disp_map = !game->disp_map;
		printf("%s", game->disp_map ? "Map displayed\n":"Map hidden\n");
    }
    if (keydata.key == MLX_KEY_F5 && keydata.action == MLX_PRESS)
    {
        game->disp_play = !game->disp_play;
		printf("%s", game->disp_play ? "Player infos displayed\n":"Player infos hidden\n");
        if (!game->disp_play)
        {
            mlx_delete_image(game->win, game->p_text[0]);
            mlx_delete_image(game->win, game->p_text[1]);
            mlx_delete_image(game->win, game->p_text[2]);
        }
    }
}

void    ft_close(void *param)
{
    ft_exit((t_game *)param);
}
