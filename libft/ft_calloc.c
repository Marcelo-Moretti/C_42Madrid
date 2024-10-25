/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <mmoretti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:22:07 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/25 17:57:34 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	bytes;
	void	*pointer;

	if (nmemb == 0 || size == 0)
		return (NULL);
	bytes = nmemb * size;
	pointer = (void *)malloc(bytes);
	if (pointer == NULL)
		return (NULL);
	else
		ft_bzero(pointer, bytes);
	return (pointer);
}
/*
void write_number(int num) {
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

int main() {
    size_t num_elements = 5;
    int *array;

    array = (int *)ft_calloc(num_elements, sizeof(int));

    if (array == NULL) {
        write(1, "Error al asignar memoria\n", 25);
        return 1; // Manejo de error
    }

    for (size_t i = 0; i < num_elements; i++) {
        write_number(array[i]);
        write(1, "\n", 1);
    }

    free(array);

    return 0;
}
*/