/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:20:00 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/17 19:13:27 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
/*
int main() {
    int i = 0;

    while (i < 130)
    {
        if (ft_isalpha(i))
        {
            write(1, "is alpha", 8);
        } else {
            write(1, "no alpha", 8);
        }
        i++;
    }

    write(1, "\n", 1);
    return 0;
}
*/