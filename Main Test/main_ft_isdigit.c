/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlibran- <rlibran-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:19:30 by rlibran-          #+#    #+#             */
/*   Updated: 2024/09/20 17:38:59 by rlibran-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <limits.h> // Para INT_MIN y INT_MAX

int ft_isdigit(int c);

int main(void)
{
    // Pruebas de caracteres que son dígitos
    char test_digits[] = {'0', '1', '5', '9'};
    char test_non_digits[] = {'a', 'Z', '@', ' ', '\n', '-', '!', '9' + 1};  // Caracteres que no son dígitos

    // Probar con dígitos
    printf("Pruebas con dígitos:\n");
    for (size_t i = 0; i < sizeof(test_digits); i++) { // Cambiado a size_t
        char c = test_digits[i];
        printf("Test con '%c': ft_isdigit = %d, isdigit = %d\n", c, ft_isdigit(c), isdigit(c));
    }

    // Probar con no dígitos
    printf("\nPruebas con caracteres que no son dígitos:\n");
    for (size_t i = 0; i < sizeof(test_non_digits); i++) { // Cambiado a size_t
        char c = test_non_digits[i];
        printf("Test con '%c': ft_isdigit = %d, isdigit = %d\n", c, ft_isdigit(c), isdigit(c));
    }

    // Pruebas con valores extremos (caracteres no imprimibles)
    printf("\nPruebas con caracteres no imprimibles (ASCII extendido):\n");
    for (int i = 0; i <= 255; i++) {
        if (i < '0' || i > '9') { // Solo testear los que no son dígitos
            printf("Test con ASCII %d: ft_isdigit = %d, isdigit = %d\n", i, ft_isdigit(i), isdigit(i));
        }
    }

    // Pruebas con los valores límite de int (**Fuera del rango de valores ASCII**)
    printf("\nPruebas con valores límite de int:\n");
    printf("Test con INT_MIN (%d): ft_isdigit = %d, isdigit = %d\n", INT_MIN, ft_isdigit(INT_MIN), isdigit(INT_MIN));
    printf("Test con INT_MAX (%d): ft_isdigit = %d, isdigit = %d\n", INT_MAX, ft_isdigit(INT_MAX), isdigit(INT_MAX));

    return 0;
}
