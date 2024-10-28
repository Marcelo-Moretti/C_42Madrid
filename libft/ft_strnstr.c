/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <mmoretti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:21:50 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/28 19:31:19 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*little)
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			j++;
			if (little[j] == '\0')
				return ((char *)big + i);
		}
		i++;
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

int	main(void)
{
	const char	*big = "Hola, mundo!";
	const char	*little = "mun";
	size_t		len;
	char		*result;

	len = 10;
	result = ft_strnstr(big, little, len);
	if (result != NULL) {
		write(1, result, ft_strlen(result));
		write(1, "\n", 1);
	} else {
		write(1, "No encontrado\n", 14);
	}
	return (0);
}
*/