/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:19:44 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/14 20:21:20 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*string1;
	const unsigned char	*string2;
	size_t				counter;

	counter = 0;
	string1 = (const unsigned char *)s1;
	string2 = (const unsigned char *)s2;
	while (counter < n)
	{
		if (string1[counter] != string2[counter])
			return (string1[counter] - string2[counter]);
		counter++;
	}
	return (0);
}
/*
int main()
{
    char str1[] = "Hola";
    char str2[] = "Hola!";
    
    int result = ft_memcmp(str1, str2, 5);
    if (result == 0) {
        write(1, "Iguales\n", 8);
    } else if (result < 0) {
        write(1, "str1 es menor\n", 15);
    } else {
        write(1, "str1 es mayor\n", 15);
    }

    return 0;
}
*/