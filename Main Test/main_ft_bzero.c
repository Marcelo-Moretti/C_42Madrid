/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlibran- <rlibran-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 12:38:31 by rlibran-          #+#    #+#             */
/*   Updated: 2024/09/22 13:10:51 by rlibran-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>  // Para la función original bzero

// Prototipo de la función ft_bzero que está en ../ft_bzero.c
void ft_bzero(void *s, size_t n);

// Función para imprimir los bytes en hexadecimal
void print_memory(const char *buffer, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (buffer[i] == '\0')
            printf("\\0 ");
        else
            printf("%c ", buffer[i]);
    }
    printf("\n");
}

int main(void)
{
    // Casos de prueba
    char buffer1[20] = "Hello, World!";
    char buffer2[20] = "Test buffer";
    char *null_ptr = NULL;  // Puntero NULL para la prueba

    // Pruebas normales con ft_bzero
    printf("Buffer original: ");
    print_memory(buffer1, 20);
    ft_bzero(buffer1, 5);
    printf("ft_bzero resultado (primeros 5 bytes a 0): ");
    print_memory(buffer1, 20);

    // Comparación con bzero estándar
    printf("\nComparación con bzero estándar:\n");
    printf("Buffer antes: ");
    print_memory(buffer2, 20);
    bzero(buffer2, 4);
    printf("bzero resultado (primeros 4 bytes a 0): ");
    print_memory(buffer2, 20);

    // Prueba con puntero NULL
    printf("\nPrueba con puntero NULL (no debe hacer nada):\n");
    ft_bzero(null_ptr, 5);
    printf("ft_bzero con NULL: Función no debe modificar nada ni fallar.\n");

    return 0;
}

