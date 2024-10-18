/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:13:28 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/17 19:36:41 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memset(void *s, int c, size_t n)
{
	int				counter;
	unsigned char	*string;

	while (s != NULL)
	{
		counter = 0;
		string = s;
		while (counter <= n)
		{
			string[counter] = c;
			counter++;
		}
	}
	return (string);
}
/*
int	main(void)
{
	size_t	size;
	char	character;
	int		pointer[20];
	int		intero;

	intero = 257;
	size = 7;
	character = 'A';
	write(1, ft_memset(&intero, 0, 1), ft_strlen(string));
	write(1, intero, ft_strlen(string));
	write(1, ft_memset(pointer, character, size), ft_strlen(string));
	write(1, memset(pointer + 1, 190, 3), ft_strlen(string));
	write(1, ft_memset(pointer, character, 0), ft_strlen(string));
	write(1, ft_memset(pointer, '\0', size), ft_strlen(string));
	write(1, ft_memset(pointer, '7', size), ft_strlen(string));
	write(1, memset(NULL, character, size), ft_strlen(string));
}
*/