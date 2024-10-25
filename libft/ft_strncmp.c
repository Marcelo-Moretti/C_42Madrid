/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <mmoretti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:18:14 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/25 18:22:17 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, char *s2, size_t n)
{
	size_t	counter;

	counter = 0;
	while (counter < n)
	{
		if (s1[counter] == '\0' && s2[counter] == '\0')
			return (0);
		if (s1[counter] == '\0')
			return (-1);
		if (s2[counter] == '\0')
			return (1);
		if (s1[counter] != s2[counter])
			return ((unsigned char)s1[counter] - (unsigned char)s2[counter]);
		counter++;
	}
	return (0);
}

/*
int main()
{
    const char *str1 = "Hola";
    const char *str2 = "Holb";
    size_t n = 4;

    int result = ft_strncmp(str1, str2, n);

    if (result == 0) {
        write(1, "Las cadenas son iguales\n", 24);
    } else if (result < 0) {
        write(1, "s1 es menor que s2\n", 20);
    } else {
        write(1, "s1 es mayor que s2\n", 20);
    }

    return 0;
}
*/