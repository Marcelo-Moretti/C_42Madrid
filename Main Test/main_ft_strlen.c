/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlibran- <rlibran-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:40:50 by rlibran-          #+#    #+#             */
/*   Updated: 2024/09/21 14:44:46 by rlibran-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>  // Para la función original strlen

// Prototipo de la función ft_strlen que vas a implementar
size_t ft_strlen(const char *s);

int main(void)
{
    // Casos de prueba
    const char *tests[] = {
        "Hola",                    // String normal
        "",                        // String vacío
        "1234567890",              // Números
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ",  // Letras mayúsculas
        "abcdefghijklmnopqrstuvwxyz",  // Letras minúsculas
        "!@#$%^&*()",              // Caracteres especiales
        " ",                       // Espacio
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit.",  // String largo
        "\n\t\r",                  // Secuencias de escape
        NULL                       // Caso especial de puntero nulo
    };

    size_t i;

    // Recorrer los valores de prueba, incluyendo NULL
    for (i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (tests[i] == NULL)
        {
            printf("Test NULL: ft_strlen: no aplica | strlen: segfault (no se puede probar con strlen)\n");
        }
        else
        {
            size_t ft_result = ft_strlen(tests[i]);
            size_t original_result = strlen(tests[i]);

            // Mostrar los resultados
            printf("Test \"%s\": ft_strlen: %zu | strlen: %zu\n", tests[i], ft_result, original_result);
        }
    }

    return 0;
}

