/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <mmoretti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:24:49 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/25 22:04:16 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	trimmed = 0;
	while ((s1[start] != '\0') && (ft_strchr(set, s1[start]) != NULL))
		start++;
	while ((end != 0) && (ft_strchr(s1, set[end]) != NULL))
		end--;
	trimmed = ft_substr(s1, start, (end - start + 1));
	if (trimmed == NULL)
		return (NULL);
	return ((void *)(trimmed));
}
/*
void	ft_putstr(const char *s)
{
	if (s) {
		write(1, s, ft_strlen(s));
	}
}

int	main(void)
{
	const char	*testStr1 = "   Hello, World!   ";
	const char	*set1 = " ";
	const char	*result1 = ft_strtrim(testStr1, set1);
	const char	*testStr2 = "!@#Sample Text!@#";
	const char	*set2 = "!@#";
	const char	*result2 = ft_strtrim(testStr2, set2);
	const char	*testStr3 = "No trimming here.";
	const char	*set3 = "xyz";
	const char	*result3 = ft_strtrim(testStr3, set3);

	ft_putstr("Trimmed Result 1: '");
	ft_putstr(result1);
	ft_putstr("'\n");
	free((void *)result1);
	ft_putstr("Trimmed Result 2: '");
	ft_putstr(result2);
	ft_putstr("'\n");
	free((void *)result2);
	ft_putstr("Trimmed Result 3: '");
	ft_putstr(result3);
	ft_putstr("'\n");
	free((void *)result3);
	return (0);
}
*/