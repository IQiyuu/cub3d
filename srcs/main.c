/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:40:50 by dgoubin           #+#    #+#             */
/*   Updated: 2023/08/19 13:45:05 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char *av[])
{
    t_game  game;
    (void)ac;
    (void)av;
    init_game(&game);
    init_window(&game);
    return (SUCCESS);    
}
