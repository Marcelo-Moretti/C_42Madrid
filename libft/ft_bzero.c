/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:22:24 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/17 19:02:08 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			counter;
	unsigned char	*string;

	counter = 0;
	string = s;
	while (counter < n)
	{
		string[counter] = 0;
		counter++;
	}
}
/*
int main()
{
	char	buffer[10];
	int		i = 0;

	while (i < 10) {
		buffer[i] = 'A' + i;
		i++;
	}

	ft_bzero(buffer, 5);

	write(1, buffer, 10);

	return (0);
}
*/