/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 08:13:41 by saozcan           #+#    #+#             */
/*   Updated: 2022/01/12 21:04:00 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strrchr(const char *str, int c)
{
    int    len;

    len = ft_strlen(str);
    while (len >= 0)
    {
        if (str[len] == (char)c)
            return ((char *)(str + len));
        len--;
    }
    if (str[len] == (char)c)
        return ((char *)(str + len));
    return (NULL);
}
