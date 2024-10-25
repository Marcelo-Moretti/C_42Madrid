/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:13:17 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/17 19:42:50 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int i)
{
	if (i >= 'a' && i <= 'z')
		return (i - 32);
	return (i);
}

/*
int main()
{
    char test_str[] = "hola mundo! abc xyz";
    char result[sizeof(test_str)];
    size_t index = 0;

    while (test_str[index] != '\0') {
        result[index] = ft_toupper(test_str[index]);
        index++;
    }
    result[index] = '\0';

    write(1, result, sizeof(result) - 1);

    return 0;
}
*/