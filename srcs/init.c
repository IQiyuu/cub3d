/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:44:04 by dgoubin           #+#    #+#             */
/*   Updated: 2023/08/19 14:59:07 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_map(t_game *game)
{
    int     fd;
    int     size;
    char    *line;

    size = 0;
    fd = open("maps/basic.cub", O_RDONLY);
    if (fd < 0)
        return ;
    line = get_next_line(fd);
    while (line)
    {
        free(line);
        line = get_next_line(fd);
        size++;
    }
    close(fd);
    game->map = (char **)malloc(sizeof(char *) * (size + 1));
    size = 0;
    fd = open("maps/basic.cub", O_RDONLY);
    if (fd < 0)
        return ;
    line = get_next_line(fd);
    while (line)
    {
        game->map[size++] = line;
        line = get_next_line(fd);
    }
    game->map[size] = NULL;
}

void    init_player(t_game *game)
{
    int i;
    int j;

    game->player = (t_player *)malloc(sizeof(t_player));
    game->player->mouse_sensi = MOUSE_SENSI;
    game->player->speed = PLAYER_SPEED;
    i = -1;
    while (game->map[++i])
    {
        j = -1;
        while (game->map[i][++j])
        {
            if (game->map[i][j] == 'N' || game->map[i][j] == 'E' || game->map[i][j] == 'S' || game->map[i][j] == 'W')
            {
                game->player->x = i;
                game->player->y = j;
            }
            if (game->map[i][j] == 'N')
                game->player->dir = 0;
            else if (game->map[i][j] == 'E')
                game->player->dir = 90;
            else if (game->map[i][j] == 'S')
                game->player->dir = 180;
            else if (game->map[i][j] == 'W')
                game->player->dir = 270;
        }
    }
}

void    init_game(t_game *game)
{
    game->disp_map = 1;
    game->error = SUCCESS;
    init_map(game);
    init_player(game);
    ft_printab(game->map);
    print_player(game->player);
}
