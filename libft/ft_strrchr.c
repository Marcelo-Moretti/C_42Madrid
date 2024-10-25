/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <mmoretti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:17:53 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/25 21:34:58 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	cc;

	i = ft_strlen(s);
	cc = (unsigned char)c;
	while (i >= 0)
	{
		if (s[i] == cc)
			return ((char *)s + i);
		i--;
	}
	return (0);
}

/*
int main()
{
    const char *str = "Hola, mundo!";
    int c = 'o';

    char *result = ft_strrchr(str, c);

    if (result != NULL) {
        write(1, result, ft_strlen(result));
        write(1, "\n", 1);
    } else {
        write(1, "No encontrado\n", 14);
    }

    return 0;
}
*/