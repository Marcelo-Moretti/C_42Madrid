/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_isalnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlibran- <rlibran-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:10:51 by rlibran-          #+#    #+#             */
/*   Updated: 2024/09/20 18:13:09 by rlibran-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>  // Para la función original isalnum

// Prototipos de las funciones ft_ que estás comparando
int	ft_isdigit(int c);
int	ft_isalpha(int c);
int ft_isalnum(int c);

int main(void)
{
    char tests[] = {
        'A', 'Z', 'a', 'z', '0', '9', // Caracteres alfanuméricos
        '@', '[', '`', '{', '!', ' ', // Caracteres no alfanuméricos
        0, -1, 128, 255,              // Valores fuera del rango ASCII imprimible
    };

    size_t i;
    
    // Recorrer los caracteres de prueba
    for (i = 0; i < sizeof(tests)/sizeof(tests[0]); i++)
    {
        char test_char = tests[i];
        int ft_result = ft_isalnum(test_char);
        int original_result = isalnum(test_char);

        // Mostrar los resultados
        printf("Test '%c' (ASCII %d): ft_isalnum: %d | isalnum: %d\n", 
                test_char, test_char, ft_result, original_result);
    }

    // Pruebas adicionales con valores límite
    printf("\nPruebas con valores límite:\n");

    printf("Test 0 (NULL): ft_isalnum: %d | isalnum: %d\n", 
            ft_isalnum(0), isalnum(0));

    printf("Test -1 (fuera de rango negativo): ft_isalnum: %d | isalnum: %d\n", 
            ft_isalnum(-1), isalnum(-1));

    printf("Test 128 (fuera de rango ASCII): ft_isalnum: %d | isalnum: %d\n", 
            ft_isalnum(128), isalnum(128));

    printf("Test 255 (fuera de rango ASCII): ft_isalnum: %d | isalnum: %d\n", 
            ft_isalnum(255), isalnum(255));

    return 0;
}
