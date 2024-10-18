/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:35:07 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/17 19:37:57 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	length;

	if (dest == NULL || src == NULL)
	{
		return (NULL);
	}
	if (dest < src)
	{
		length = 0;
		while (length < n)
		{
			((unsigned char *)dest)[length] = ((unsigned char *)src)[length];
			length++;
		}
	}
	else
	{
		length = n;
		while (length > 0)
		{
			length--;
			((unsigned char *)dest)[length] = ((unsigned char *)src)[length];
		}
	}
	return (dest);
}
