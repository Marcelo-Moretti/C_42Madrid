/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:03:24 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/17 19:52:06 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlen(const char *s)
{
	int	counter;

	counter = 0;
	while (s[counter] != '\0')
	{
		counter++;
	}
	return (counter);
}
/*
int main(void)
{
	char	str1;
	char	str2;

	str1 = 'hello ';
	str2 = 'world!!!!';
	write(1, ft_strlen(str1), ft_strlen(str1));
	write(1, ft_strlen(str2), ft_strlen(str2));
	return (0);
}
*/