/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <mmoretti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:12:38 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/25 22:07:42 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_size;
	size_t	src_size;
	size_t	total_size;
	size_t	diff_size;

	if ((dst == NULL) || (src == NULL))
		return (0);
	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	total_size = dst_size + src_size;
	diff_size = size - src_size - 1;
	if (dst_size >= size)
		return (size + src_size);
	while (*src != '\0' && total_size > 0)
	{
		dst[dst_size++] = *src++;
		diff_size--;
	}
	dst[dst_size] = '\0';
	return (total_size);
}
/*
int main()
{
    char dst[20] = "Hola";
    const char *src = " mundo!";
    size_t size = sizeof(dst);

    size_t result = ft_strlcat(dst, src, size);

    write(1, dst, ft_strlen(dst));
    write(1, "\n", 1);

    char result_str[20];
    int len = snprintf(result_str, sizeof(result_str), "Total: %zu\n", result);
    write(1, result_str, len);

    return 0;
}
*/