/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:44:01 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/17 18:55:57 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
int main()
{
    int i = 0;

    while (i < 130)
    {
        if (ft_isdigit(i))
        {
            write(1, "is digit", 8);
        } else {
            write(1, "no digit", 8);
        }
        i++;
    }

    write(1, "\n", 1);
    return 0;
}
*/