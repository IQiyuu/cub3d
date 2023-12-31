/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 14:02:01 by dgoubin           #+#    #+#             */
/*   Updated: 2023/08/19 14:06:06 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_printab(char **tab)
{
    int n;

    n = 0;
    while (tab[n])
        printf("%s\n", tab[n++]);
}