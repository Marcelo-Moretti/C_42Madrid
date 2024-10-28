/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <mmoretti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:12:38 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/28 17:50:36 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	counter_one;
	size_t	counter_two;

	counter_one = 0;
	counter_two = 0;
	while (dst[counter_one] && counter_one < size)
		counter_one++;
	while (src[counter_two] && (counter_one + counter_two + 1) < size)
	{
		dst[counter_one + counter_two] = src[counter_two];
		counter_two++;
	}
	if (counter_one < size)
		dst[counter_one + counter_two] = '\0';
	return (counter_one + ft_strlen(src));
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