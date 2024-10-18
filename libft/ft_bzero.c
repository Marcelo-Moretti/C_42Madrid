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

#include <libft.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			counter;
	unsigned char	*string;

	while (s != NULL)
	{
		counter = 0;
		string = s;
		while (counter <= n)
		{
			string[counter] = 0;
			counter++;
		}
		return (string);
	}
}

/*
int main(void)
{
	char array[20]="hola estrella";
	int array_int[7]= {-1,5,200,13,1,11,10};
	size_t numberof;
	int i;

	numberof = 5;
	ft_bzero(array, numberof);
	ft_bzero(array_int, 1);	
	i = 0;
	while (i < 7)
	{
		printf("[%d]\n", array_int[i]);
		i++;
	}
}
*/