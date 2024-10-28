/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <mmoretti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:03:24 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/28 17:58:14 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	while (s[counter])
		counter++;
	return (counter);
}
/*
int main()
{
    const char	*test_str;
    size_t		length;

	test_str = "Hola, mundo!";
    length = ft_strlen(test_str);

    write(1, length, ft_strlen(length));

    return 0;
}
*/