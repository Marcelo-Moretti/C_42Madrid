/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <mmoretti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:14:58 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/25 21:34:30 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	cc;

	i = 0;
	cc = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *)s + i);
		i++;
	}
	if (cc == 0)
		return ((char *)s + i);
	return (0);
}
/*
int main() {
    const char *str = "Hola, mundo!";
    char c = 'm';
    char *result = ft_strchr(str, c);

    if (result) {
        write(1, "Encontrado: ", 12);
        write(1, result, 1);
        write(1, "\n", 1);
    } else {
        write(1, "No encontrado\n", 14);
    }

    return 0;
}
*/