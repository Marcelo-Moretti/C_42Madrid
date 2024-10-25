/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:21:52 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/17 19:56:13 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	counter;
	int	negative;
	int	result;

	counter = 0;
	negative = 1;
	result = 0;
	while (nptr[counter] == ' ' || (nptr[counter] >= 9 && nptr[counter] <= 13))
		counter++;
	if (nptr[counter] == '-' || nptr[counter] == '+')
	{
		if (nptr[counter] == '-')
			negative *= -1;
		counter++;
	}
	while (nptr[counter] != '\0' && ft_isdigit(nptr[counter]))
	{
		result = (result * 10) + ((nptr[counter] - '0'));
		counter++;
	}
	return (result * negative);
}
/*
void write_number(int num)
{
    char buffer[12];
    int len = 0;
    
    if (num < 0) {
        write(1, "-", 1);
        num = -num;
    }
    
    if (num == 0) {
        buffer[len++] = '0';
    } else {
        while (num > 0) {
            buffer[len++] = (num % 10) + '0';
            num /= 10;
        }
    }

    while (len > 0) {
        write(1, &buffer[--len], 1);
    }
}

int main()
{
    const char *test1 = "   -42";
    const char *test2 = "123";
    const char *test3 = "   +456";
    const char *test4 = "   -123abc";

    write(1, "Resultado de ft_atoi:\n", 23);
    write_number(ft_atoi(test1));
    write(1, "\n", 1);
    write_number(ft_atoi(test2));
    write(1, "\n", 1);
    write_number(ft_atoi(test3));
    write(1, "\n", 1);
    write_number(ft_atoi(test4));
    write(1, "\n", 1);

    return 0;
}
*/
