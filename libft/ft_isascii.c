/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:57:22 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/17 19:00:36 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
int main() 
{
    int i = 0;

    while (i < 130)
    {
        if (ft_isascii(i))
        {
            write(1, "is ascii", 8);
        } else {
            write(1, "no ascii", 8);
        }
        i++;
    }

    write(1, "\n", 1);
    return 0;
}
*/