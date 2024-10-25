/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <mmoretti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:12:04 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/25 21:31:54 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (dest == NULL || src == NULL)
		return (0);
	i = 0;
	while (i < (size - 1) && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	while (src[i])
		i++;
	return (i);
}
/*int	main(void)
{
	char		dest[10];
	const char	*src = "Hola Mundo!";
	size_t		len;

	len = ft_strlcpy(dest, src, 0);
	//write(1, dest, len < sizeof(dest) ? len : sizeof(dest) - 1);
	//write(1, "\n", 1);
	printf("%s\n%zu\n", dest, len);
	return (0);
}*/
