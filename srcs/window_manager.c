/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:09:02 by dgoubin           #+#    #+#             */
/*   Updated: 2023/09/11 18:25:44 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    put_square(t_game *game, int x, int y, int size, uint32_t color)
{
    int i;
    int j;

    i = 0;
    while (i++ < size)
    {
        j = 0;
        while (j++ < size)
            mlx_put_pixel(game->bg, x + i, y + j, color);
    }

}

float distance(float x1, float y1, float x2, float y2)
{
    return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void    print_ray(t_game *game)
{
    float   x;
    float   y;
    float   angle;
    float   dist;
    int     a;

    mlx_delete_image(game->win, game->bg);
    game->bg = mlx_new_image(game->win, WIDTH, HEIGHT);
    a = 0;
    angle = game->player->dir - FOV / 2;
    while (angle <= game->player->dir + FOV / 2)
    {
        x = (game->player->x + 16) / 75;
        y = (game->player->y + 16) / 75;
        while (game->map[(int)y][(int)x] != '1')
        {
            mlx_put_pixel(game->bg, x * 75, y * 75, 0x00FFFFFF);
            x += 0.01 * cos((angle - 90) * M_PI / 180);
            y += 0.01 * sin((angle - 90) * M_PI / 180);
        }
        dist = distance(x * 75, y * 75, game->player->x, game->player->y);
        float   wallHeight = HEIGHT / dist * 25;
        int color = 0;
        if (dist > 255)
            dist = 255;
        color = color | ((int)(255 - dist) << 24);
        color = color | ((int)(255 - dist) << 16);
        color = color | ((int)(255 - dist) << 8);
        color = color | 0xFF;
        for (int i = HEIGHT / 2 - wallHeight / 2; i < HEIGHT / 2 + wallHeight / 2; i++)
        {
           mlx_put_pixel(game->bg, a, i, color);
        }
        angle += 0.03335;
        a++;
    }
    mlx_image_to_window(game->win, game->bg, 0, 0);
}

void    print_minimap(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            put_square(game, j * 75, i * 75, 75, 0x666666FF);
            if (game->map[i][j] == '1')
                put_square(game, j * 75, i * 75, 75, 0x111111FF);
            else if (game->map[i][j] == '0')
                put_square(game, j * 75, i * 75, 75, 0x666666FF);  
            j++;
        }
        i++;
    }
    put_square(game, game->player->x, game->player->y, 32, 0xFF0000FF);
    print_ray(game);
}

void    init_window(t_game *game)
{
    game->win = mlx_init(WIDTH, HEIGHT, "cub3d", true);
    if (!game->win)
    {
        game->error = OPEN_WIN;
        ft_exit(game);
    }
    game->bg = mlx_new_image(game->win, WIDTH, HEIGHT);
    if (!game->bg)
        return ;
    mlx_image_to_window(game->win, game->bg, 0, 0);
    print_minimap(game);
    mlx_loop_hook(game->win, loop, game);
    mlx_key_hook(game->win, key, game);
    mlx_close_hook(game->win, ft_close, game);
    mlx_loop(game->win);
    return ;
}
