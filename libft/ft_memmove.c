/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <mmoretti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:35:07 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/25 21:31:03 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*destiny;
	unsigned char	*source;
	unsigned char	*lastd;
	unsigned char	*lasts;
	size_t			length;

	destiny = (unsigned char *)dest;
	source = (unsigned char *)src;
	length = n;
	if (!dest && !src)
		return (0);
	if (destiny < source)
		while (length--)
			*destiny++ = *source++;
	else
	{
		lasts = source + (length - 1);
		lastd = destiny + (length - 1);
		while (length--)
			*lastd-- = *lasts--;
	}
	return (destiny);
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