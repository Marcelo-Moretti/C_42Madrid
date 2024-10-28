/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <mmoretti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:35:07 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/28 19:27:47 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	length;

	length = 0;
	if (!dest && !src)
		return (NULL);
	if (src < dest)
	{
		length = n;
		while (length > 0)
		{
			length--;
			((unsigned char *)dest)[length] = ((unsigned char *)src)[length];
		}
	}
	else
	{
		length = 0;
		while (length < n)
		{
			((unsigned char *)dest)[length] = ((unsigned char *)src)[length];
			length++;
		}
	}
	return (dest);
}

/*
int main()
{
    char buffer[20] = "Hola Mundo!";

    ft_memmove(buffer + 5, buffer, 10);

    write(1, buffer, 15);

    return 0;
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	*lastd;
	unsigned char	*lasts;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!dst && !src)
		return (0);
	if (d < s)
		while (len--)
			*d++ = *s++;
	else
	{
		lasts = s + (len - 1);
		lastd = d + (len - 1);
		while (len--)
			*lastd-- = *lasts--;
	}
	return (dst);
}

*/