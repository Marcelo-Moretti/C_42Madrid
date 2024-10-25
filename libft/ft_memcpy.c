/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <mmoretti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:26:55 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/25 20:25:34 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				counter;
	unsigned char		*destiny;
	const unsigned char	*source;

	counter = 0;
	if (dest == NULL || src == NULL)
		return (NULL);
	destiny = (unsigned char *)dest;
	source = (unsigned char *)src;
	while (counter < n)
	{
		destiny[counter] = source[counter];
		counter++;
	}
	return (destiny);
}

/*
int main()
{
    char src[] = "Hola";
    char dest[10];

    ft_memcpy(dest, src, 5);

    write(1, dest, 5);

    return 0;
}
*/