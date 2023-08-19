/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:44:16 by dgoubin           #+#    #+#             */
/*   Updated: 2023/08/19 14:05:18 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define BUFFER_SIZE 50

void    ft_freetab(char **tab);
int     ft_strlen(char *str);
void    ft_printab(char **tab);

/*               GNL                 */
char	*get_next_line(int fd);
void	gnl_endingbuf(char *str);
char	*gnl_clearbuf(char *str, char *res);
char	*gnl_get_line(char *buf, int fd);
int	    check_isnl(char *str);

char	*gnl_strdup_untilnl(char *str, int boolnl);
char	*gnl_strcat(char *src, char *dest);
int	    gnl_strlen(char *str, int boolnl);

#endif