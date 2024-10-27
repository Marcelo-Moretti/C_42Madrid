/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_isascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlibran- <rlibran-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 10:59:49 by rlibran-          #+#    #+#             */
/*   Updated: 2024/09/21 11:00:12 by rlibran-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>  // Para la función original isascii

// Prototipo de la función ft_isascii que vas a implementar
int ft_isascii(int c);

int main(void)
{
    int tests[] = {
        'A', 'Z', 'a', 'z', '0', '9',  // Caracteres ASCII
        '@', '[', '`', '{', '!', ' ',  // Otros caracteres ASCII imprimibles
        0, 127,                        // Límites de ASCII (0 y 127)
        -1, 128, 255,                  // Valores fuera del rango ASCII
        500, -500                      // Valores extremos fuera de rango
    };

    size_t i;

    // Recorrer los valores de prueba
    for (i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        int test_val = tests[i];
        int ft_result = ft_isascii(test_val);
        int original_result = isascii(test_val);

        // Mostrar los resultados
        printf("Test %d (ASCII: %c): ft_isascii: %d | isascii: %d\n",
               test_val, (test_val >= 32 && test_val <= 126) ? test_val : ' ',
               ft_result, original_result);
    }

    // Pruebas adicionales con valores específicos
    printf("\nPruebas con valores límite:\n");
    printf("Test -1: ft_isascii: %d | isascii: %d\n", ft_isascii(-1), isascii(-1));
    printf("Test 0: ft_isascii: %d | isascii: %d\n", ft_isascii(0), isascii(0));
    printf("Test 127: ft_isascii: %d | isascii: %d\n", ft_isascii(127), isascii(127));
    printf("Test 128: ft_isascii: %d | isascii: %d\n", ft_isascii(128), isascii(128));
    printf("Test 255: ft_isascii: %d | isascii: %d\n", ft_isascii(255), isascii(255));

    return 0;
}
