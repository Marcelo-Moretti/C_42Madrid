/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:26:55 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/17 19:37:32 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			counter;
	unsigned char	*destiny;
	unsigned char	*source;

	if (dest == NULL || src == NULL)
	{
		return (NULL);
	}
	else
	{
		counter = 0;
		destiny = dest;
		source = src;
		while (counter <= n)
		{
			destiny[counter] = source[counter];
			counter++;
		}
		return (destiny);
	}
}
