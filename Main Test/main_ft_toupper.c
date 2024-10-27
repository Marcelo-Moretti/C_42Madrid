/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_toupper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlibran- <rlibran-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:00:51 by rlibran-          #+#    #+#             */
/*   Updated: 2024/09/21 15:00:59 by rlibran-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>  // Para la función original toupper

// Prototipo de la función ft_toupper que vas a implementar
int ft_toupper(int c);

int main(void)
{
    // Casos de prueba
    int tests[] = {
        'a', 'z', 'A', 'Z', 'b', 'B',     // Letras minúsculas y mayúsculas
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
        int ft_result = ft_toupper(test_val);
        int original_result = toupper(test_val);

        // Mostrar los resultados
        printf("Test '%c' (ASCII %d): ft_toupper: %d | toupper: %d\n", 
               test_val, test_val, ft_result, original_result);
    }

    return 0;
}

