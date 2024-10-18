/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:21:50 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/17 20:17:21 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 == NULL || s1[0] == '\0')
		return ((char *)s2);
	while (s2[i] != '\0' && i < n)
	{
		if (s2[i] == s1[j])
		{
			while (s2[i + j] == s1[j] && i + j < n)
			{
				if (s1[j + 1] == '\0')
					return ((char *)s2 + i);
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}
