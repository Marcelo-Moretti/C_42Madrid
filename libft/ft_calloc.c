/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <mmoretti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:22:07 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/28 20:30:56 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	bytes;
	void	*pointer;

	bytes = nmemb * size;
	pointer = malloc(bytes);
	if (pointer == NULL)
		return (NULL);
	else
		ft_bzero(pointer, bytes);
	return (pointer);
}
