/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:47:15 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/17 19:19:16 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
/*
int main()
{
    int i = 0;

    while (i < 130)
    {
        if (ft_isalnum(i))
        {
            write(1, "is alnum", 8);
        } else {
            write(1, "no alnum", 8);
        }
        i++;
    }

    write(1, "\n", 1);
    return 0;
}
*/