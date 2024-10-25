/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <mmoretti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:13:28 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/25 17:41:53 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			counter;
	unsigned char	*string;

	counter = 0;
	string = s;
	while (counter < n)
	{
		string[counter] = c;
		counter++;
	}
	return (string);
}
/*
int main()
{
    char	buffer[10];
    int		i;

	i = 0;
    while (i < 10)
	{
        buffer[i] = 'X';
        i++;
    }

    ft_memset(buffer, 'A', 5);

    write(1, buffer, 10);

    return 0;
}
*/