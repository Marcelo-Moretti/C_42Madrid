/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlibran- <rlibran-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:01:21 by rlibran-          #+#    #+#             */
/*   Updated: 2024/09/21 16:01:28 by rlibran-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>  // Para la función original memset

// Prototipo de la función ft_memset que está en ../ft_memset.c
void *ft_memset(void *s, int c, size_t n);

int main(void)
{
    // Casos de prueba
    char buffer1[20] = "Hello, World!";
    char buffer2[20] = "Test buffer";
    char *null_ptr = NULL;

    // Pruebas con un buffer normal
    printf("Buffer original: %s\n", buffer1);
    ft_memset(buffer1, 'X', 5);
    printf("ft_memset resultado: %s\n", buffer1);

    // Comparación con memset estándar
    printf("\nComparación con memset estándar:\n");
    printf("Buffer antes: %s\n", buffer2);
    memset(buffer2, 'Y', 4);
    printf("memset resultado: %s\n", buffer2);

    // Prueba con puntero NULL
    printf("\nPrueba con NULL:\n");
    if (ft_memset(null_ptr, 'Z', 5) == NULL)
        printf("ft_memset correctamente gestionó un puntero NULL.\n");
    else
        printf("Error: ft_memset no gestionó correctamente el puntero NULL.\n");

    return 0;
}

