/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <mmoretti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:12:04 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/28 18:33:10 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	counter;

	counter = 0;
	if (size == 0)
	{
		while (src[counter])
			counter++;
		return (counter);
	}
	while (counter < (size - 1) && src[counter] != '\0')
	{
		dest[counter] = src[counter];
		counter++;
	}
	if (counter < size)
		dest[counter] = '\0';
	while (src[counter])
		counter++;
	return (counter);
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
