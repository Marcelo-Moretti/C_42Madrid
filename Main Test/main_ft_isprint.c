/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_isprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlibran- <rlibran-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:17:15 by rlibran-          #+#    #+#             */
/*   Updated: 2024/09/21 11:25:58 by rlibran-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>  // Para la función original isprint

// Prototipo de la función ft_isprint que vas a implementar
int ft_isprint(int c);

int main(void)
{
    int tests[] = {
        'A', 'Z', 'a', 'z', '0', '9',  // Caracteres imprimibles (letras y dígitos)
        '@', '[', '`', '{', '!', ' ',  // Otros caracteres imprimibles
        0, 31, 32, 127,                // Límites de caracteres no imprimibles e imprimibles
        -1, 128, 255,                  // Valores fuera del rango ASCII imprimible
        500, -500                      // Valores extremos fuera de rango
    };

    size_t i;

    // Recorrer los valores de prueba
    for (i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        int test_val = tests[i];
        int ft_result = ft_isprint(test_val);
        int original_result = isprint(test_val);

        // Mostrar los resultados
        printf("Test %d (ASCII: %c): ft_isprint: %d | isprint: %d\n",
               test_val, (test_val >= 32 && test_val <= 126) ? test_val : ' ',
               ft_result, original_result);
    }

    // Pruebas adicionales con valores límite
    printf("\nPruebas con valores límite:\n");
    printf("Test -1: ft_isprint: %d | isprint: %d\n", ft_isprint(-1), isprint(-1));
    printf("Test 0: ft_isprint: %d | isprint: %d\n", ft_isprint(0), isprint(0));
    printf("Test 31: ft_isprint: %d | isprint: %d\n", ft_isprint(31), isprint(31));
    printf("Test 32: ft_isprint: %d | isprint: %d\n", ft_isprint(32), isprint(32));  // Imprimible
    printf("Test 127: ft_isprint: %d | isprint: %d\n", ft_isprint(127), isprint(127)); // No imprimible
    printf("Test 255: ft_isprint: %d | isprint: %d\n", ft_isprint(255), isprint(255));

    return 0;
}

