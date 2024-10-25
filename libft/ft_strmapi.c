/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:27:16 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/15 19:38:37 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	counter;
	char			*string;

	counter = 0;
	string = (char *)malloc(ft_strlen(s) + 1);
	if (string == NULL || f == NULL)
		return (NULL);
	while (s[counter] != '\0')
	{
		string[counter] = f(counter, s[counter]);
		counter++;
	}
	string[counter] = '\0';
	return (string);
}

/*
char to_upper(unsigned int index, char c)
{
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    return c;
}

int main()
{
    char *str = "hola mundo";
    char *result = ft_strmapi(str, to_upper);

    if (result != NULL) {
        write(1, result, ft_strlen(result));
        write(1, "\n", 1);
        free(result);
    } else {
        write(1, "Error al asignar memoria\n", 26);
    }

    return 0;
}
*/