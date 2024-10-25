/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:18:45 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/14 20:14:47 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*string;
	size_t				counter;

	counter = 0;
	string = (const unsigned char *)s;
	while (counter < n)
	{
		if (string[counter] == (unsigned char)c)
			return ((void *)(string + counter));
		counter++;
	}
	return (NULL);
}
/*
int main()
{
	const char *str = "Hola Mundo!";
	char *result;

	result = ft_memchr(str, 'M', 12);

	if (result != NULL) {
		write(1, result, 8);
	} 
	else
	{
		write(1, "No encontrado\n", 15);
	}

	return 0;
}
*/