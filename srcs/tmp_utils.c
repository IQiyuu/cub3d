/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 14:24:50 by dgoubin           #+#    #+#             */
/*   Updated: 2023/08/19 14:52:54 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char    *get_dir(t_player *player)
{
    if ((player->dir >= 0 && player->dir < 23.75) || (player->dir >= 356.25))
        return("(North)\n");
    if ((player->dir >= 23.75 && player->dir < 71.25))
        return("(North East)\n");
    if ((player->dir >= 71.25 && player->dir < 118.75))
        return("(East)\n");
    if ((player->dir >= 118.75 && player->dir < 166.25))
        return("(South East)\n");
    if ((player->dir >= 166.25 && player->dir < 213.75))
        return("(South)\n");
    if ((player->dir >= 213.75 && player->dir < 261.25))
        return("(South West)\n");
    if ((player->dir >= 261.25 && player->dir < 308.75))
        return("(West)\n");
    if ((player->dir >= 308.75 && player->dir < 356.25))
        return("(North West)\n");
    return ("(null)");
}

void    refresh_text(t_game *game)
{
    char    *str1;
    char    *str2;
    char    *str3;
    char    *tmp;
    char    *tmp2;

    mlx_delete_image(game->win, game->p_text[0]);
    mlx_delete_image(game->win, game->p_text[1]);
    mlx_delete_image(game->win, game->p_text[2]);
    /* */
    tmp = ft_itoa((int)floorf(game->player->x));
    str1 = ft_strjoin("x: ", tmp);
    free(tmp);
    /* */
    tmp = ft_itoa((int)floorf(game->player->y));
    str2 = ft_strjoin("y: ", tmp);
    free(tmp);
    /* */
    tmp = ft_itoa((int)floorf(game->player->dir));
    tmp2 = ft_strjoin("orientation: ", tmp);
    free(tmp);
    str3 = ft_strjoin(tmp2, get_dir(game->player));
    free(tmp2);
    game->p_text[1] = mlx_put_string(game->win, str2, WIDTH - 250, 25);
    game->p_text[2] = mlx_put_string(game->win, str3, WIDTH - 250, 50);
    game->p_text[0] = mlx_put_string(game->win, str1, WIDTH - 250, 0);
    free(str3);
    free(str2);
    free(str1);
    /* */
}

void    print_player(t_player *player)
{
    printf("Player :\n    - x: %f\n    - y: %f\n    - Orientation: %f %s", player->x, player->y, player->dir, get_dir(player));
}
