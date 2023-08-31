/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:14:13 by dgoubin           #+#    #+#             */
/*   Updated: 2023/08/31 17:09:59 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int test_collision(t_game *game)
{
    if (game->map[(int)(game->player->y / 75)][(int)(game->player->x / 75)] == '1')
        return (1);
    if (game->map[(int)(game->player->y / 75)][(int)((game->player->x + 32) / 75)] == '1')
        return (1);
    if (game->map[(int)((game->player->y + 32) / 75)][(int)(game->player->x / 75)] == '1')
        return (1);
    if (game->map[(int)((game->player->y + 32) / 75)][(int)((game->player->x + 32) / 75)] == '1')
        return (1);
    return (0);
}

void    loop(void *param)
{
    t_game  *game;

    game = (t_game *)param;
    if (game->win->delta_time < 0.01f)
        return ;
    if (mlx_is_key_down(game->win, MLX_KEY_ESCAPE))
        ft_exit(game);
    if (mlx_is_key_down(game->win, MLX_KEY_W))
    {
        game->player->y += (game->player->speed * sin((game->player->dir - 90) * M_PI / 180));
        game->player->x += (game->player->speed * cos((game->player->dir - 90) * M_PI / 180));
        if (test_collision(game))
        {
            game->player->y -= (game->player->speed * sin((game->player->dir - 90) * M_PI / 180));
            game->player->x -= (game->player->speed * cos((game->player->dir - 90) * M_PI / 180));
        }
    }
    if (mlx_is_key_down(game->win, MLX_KEY_D))
    {
        game->player->y += (game->player->speed * sin(game->player->dir * M_PI / 180));
        game->player->x += (game->player->speed * cos(game->player->dir * M_PI / 180));
        if (test_collision(game))
        {
            game->player->y -= (game->player->speed * sin(game->player->dir * M_PI / 180));
            game->player->x -= (game->player->speed * cos(game->player->dir * M_PI / 180));
        }
    }
    if (mlx_is_key_down(game->win, MLX_KEY_A))
    {
        game->player->y += (game->player->speed * sin((game->player->dir + 180) * M_PI / 180));
        game->player->x += (game->player->speed * cos((game->player->dir + 180) * M_PI / 180));
        if (test_collision(game))
        {
            game->player->y -= (game->player->speed * sin((game->player->dir + 180) * M_PI / 180));
            game->player->x -= (game->player->speed * cos((game->player->dir + 180) * M_PI / 180));
        }
    }
    if (mlx_is_key_down(game->win, MLX_KEY_S))
    {
        game->player->y += (game->player->speed * sin((game->player->dir + 90) * M_PI / 180));
        game->player->x += (game->player->speed * cos((game->player->dir + 90) * M_PI / 180));
        if (test_collision(game))
        {
            game->player->y -= (game->player->speed * sin((game->player->dir + 180) * M_PI / 180));
            game->player->x -= (game->player->speed * cos((game->player->dir + 180) * M_PI / 180));
        }
    }
    if (game->disp_play)
        print_player(game->player);
    print_minimap(game);
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
    if ((keydata.key == MLX_KEY_F5 || keydata.key == MLX_KEY_P) && keydata.action == MLX_PRESS)
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
    if (keydata.key == MLX_KEY_KP_SUBTRACT && keydata.action != MLX_RELEASE)
        game->player->speed -= 0.1;
    if (keydata.key == MLX_KEY_KP_ADD && keydata.action != MLX_RELEASE)
        game->player->speed += 0.1;
}

void    ft_close(void *param)
{
    ft_exit((t_game *)param);
}
