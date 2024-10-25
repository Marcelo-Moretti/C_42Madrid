/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:00:34 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/17 19:10:56 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*
int main()
{
    int i = 0;

    while (i < 130)
    {
        if (ft_isprint(i))
        {
            write(1, "is printable", 12);
        } else {
            write(1, "no printable", 12);
        }
        i++;
    }
    
    write(1, "\n", 1);
    return 0;
}
*/