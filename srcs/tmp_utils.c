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

void    print_player(t_player *player)
{
    printf("Player :\n    - x: %f\n    - y: %f\n    - Orientation: %f => ", player->x, player->y, player->dir);
    if ((player->dir >= 0 && player->dir < 23.75) || (player->dir >= 356.25))
        printf("North\n");
    if ((player->dir >= 23.75 && player->dir < 71.25))
        printf("North East\n");
    if ((player->dir >= 71.25 && player->dir < 118.75))
        printf("East\n");
    if ((player->dir >= 118.75 && player->dir < 166.25))
        printf("South East\n");
    if ((player->dir >= 166.25 && player->dir < 213.75))
        printf("South\n");
    if ((player->dir >= 213.75 && player->dir < 261.25))
        printf("South West\n");
    if ((player->dir >= 261.25 && player->dir < 308.75))
        printf("West\n");
    if ((player->dir >= 308.75 && player->dir < 356.25))
        printf("North West\n");
}
