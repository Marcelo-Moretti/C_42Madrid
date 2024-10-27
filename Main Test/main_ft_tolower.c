/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_tolower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlibran- <rlibran-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:15:18 by rlibran-          #+#    #+#             */
/*   Updated: 2024/09/21 15:15:27 by rlibran-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>  // Para la función original tolower

// Prototipo de la función ft_tolower que está en ../ft_tolower.c
int ft_tolower(int c);

int main(void)
{
    // Casos de prueba
    int tests[] = {
        'A', 'Z', 'a', 'z', 'B', 'b',     // Letras mayúsculas y minúsculas
        '0', '9',                         // Números
        '!', '@', '[', ']',               // Caracteres especiales
        123, 98, 97,                      // Valores alrededor de los límites de ASCII
        0, -1, 128, 255                   // Valores fuera del rango ASCII estándar
    };

    size_t i;

    // Recorrer los valores de prueba
    for (i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        int test_val = tests[i];
        int ft_result = ft_tolower(test_val);
        int original_result = tolower(test_val);

        // Mostrar los resultados
        printf("Test '%c' (ASCII %d): ft_tolower: %d | tolower: %d\n", 
               test_val, test_val, ft_result, original_result);
    }

    return 0;
}

