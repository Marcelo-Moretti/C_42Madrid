/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:14:12 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/14 19:38:56 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int i)
{
	if (i >= 'A' && i <= 'Z')
		return (i + 32);
	return (i);
}

/*
int main()
{
    char test_str[] = "Hola Mundo! ABC XYZ";
    char result[sizeof(test_str)];
    size_t index = 0;

    while (test_str[index] != '\0') {
        result[index] = ft_tolower(test_str[index]);
        index++;
    }
    result[index] = '\0';

    write(1, result, sizeof(result) - 1);

    return 0;
}
*/