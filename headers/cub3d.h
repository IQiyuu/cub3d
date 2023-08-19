/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:41:15 by dgoubin           #+#    #+#             */
/*   Updated: 2023/08/19 14:58:29 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "MLX42/MLX42.h"
# include <math.h>
# include <fcntl.h>

# define WIDTH 1500
# define HEIGHT 1500
# define PLAYER_SPEED 5
# define MOUSE_SENSI 50

enum e_error    {SUCCESS,
        FAILLURE,
        OPEN_WIN};

typedef struct  s_player
{
    float       x;
    float       y;
    float       dir;
    float       mouse_sensi;
    float       speed;
}   t_player;

typedef struct s_game
{
    mlx_t           *win;
    int             disp_map;
    int             disp_play;
    mlx_texture_t   *textures;
    int             error;
    char            **map;
    t_player        *player;
}   t_game;

void    init_game(t_game *game);
void    init_window(t_game *game);
void    ft_exit(t_game *game);

/*              UTILS TMP           */
void    print_player(t_player *player);

/*              hooks               */
void    key(mlx_key_data_t keydata, void *param);
void    loop(void *param);
void    ft_close(void *param);

#endif