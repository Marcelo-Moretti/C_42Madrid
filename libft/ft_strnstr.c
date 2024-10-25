/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <mmoretti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:21:50 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/25 22:12:22 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	counter;

	counter = 0;
	if (big == NULL || len == 0)
		return (NULL);
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (counter < len && big[counter] != 0)
	{
		if (ft_strncmp((char *)&big[counter], (char *)little, \
		ft_strlen(little)) == 0)
		{
			if (counter + ft_strlen(little) > len)
				return (0);
			return ((char *)&big[counter]);
		}
		counter++;
	}
	return (NULL);
}

/*
		if (ft_strncmp((char *)&haystack[aux], (char *)needle, 
		ft_strlen(needle)) == 0)
		{
			if (aux + ft_strlen(needle) > len)
				return (0);
			return ((char *)&haystack[aux]);

int main()
{
    const char *big = "Hola, mundo!";
    const char *little = "mun";
    size_t len = 10;

    char *result = ft_strnstr(big, little, len);

    if (result != NULL) {
        write(1, result, ft_strlen(result));
        write(1, "\n", 1);
    } else {
        write(1, "No encontrado\n", 14);
    }

    return 0;
}
*/