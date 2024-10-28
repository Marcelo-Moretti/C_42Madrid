/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <mmoretti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:24:49 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/28 18:59:31 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*string;

	string = 0;
	if (s1 != 0 && set != 0)
	{
		i = 0;
		j = ft_strlen(s1);
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (s1[j - 1] && ft_strchr(set, s1[j - 1]) && j > i)
			j--;
		string = (char *)malloc(sizeof(char) * (j - i + 1));
		if (string)
			ft_strlcpy(string, &s1[i], j - i + 1);
	}
	return (string);
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