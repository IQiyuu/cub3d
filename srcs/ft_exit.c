/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:17:12 by dgoubin           #+#    #+#             */
/*   Updated: 2023/08/19 14:43:29 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_exit(t_game *game)
{
    if (game->win)
        mlx_terminate(game->win);
    ft_freetab(game->map);
    //system("leaks cub3d");
    exit(game->error);
}
