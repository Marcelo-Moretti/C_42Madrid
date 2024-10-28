/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <mmoretti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:27:36 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/28 19:45:39 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	counter;

	counter = 0;
	while (s[counter] != '\0')
	{
		f(counter, s + counter);
		counter++;
	}
}
/*
void print_char(unsigned int index, char *c)
{
    write(1, "Index: ", 7);
    char idx_str[3];
    int len = snprintf(idx_str, sizeof(idx_str), "%u ", index);
    write(1, idx_str, len);
    write(1, c, 1);
    write(1, "\n", 1);
}

int main() {
    char str[] = "Hola";
    ft_striteri(str, print_char);
    return 0;
}
}*/