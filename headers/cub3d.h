/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:41:15 by dgoubin           #+#    #+#             */
/*   Updated: 2023/09/02 11:54:48 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "MLX42/MLX42.h"
# include <fcntl.h>
# include <math.h>

# define WIDTH 1500
# define HEIGHT 1500
# define PLAYER_SPEED 10
# define MOUSE_SENSI 15
# define FOV 50

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
    mlx_image_t     *p_text[3];
    mlx_image_t     *bg;
}   t_game;

void    init_game(t_game *game);
void    init_window(t_game *game);
void    ft_exit(t_game *game);

/*              visual              */
void    print_minimap(t_game *game);

/*              UTILS TMP           */
void    print_player(t_player *player);
void    refresh_text(t_game *game);

/*              hooks               */
void    key(mlx_key_data_t keydata, void *param);
void    loop(void *param);
void    ft_close(void *param);

#endif