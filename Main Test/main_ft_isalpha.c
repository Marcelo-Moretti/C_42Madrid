/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_isalpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlibran- <rlibran-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:36:32 by rlibran-          #+#    #+#             */
/*   Updated: 2024/09/18 14:41:24 by rlibran-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>  // Para la función original isalpha

// Declaración manual de la función ft_isalpha
int ft_isalpha(int c);

int main(void)
{
    char tests[] = {'A', 'Z', 'a', 'z', '0', '9', '@', '[', '`', '{', ' ', '!', '~', -1, 128, 255, 65, 122};
    size_t i;
    
    // Recorrer los caracteres de prueba
    for (i = 0; i < sizeof(tests)/sizeof(tests[0]); i++)
    {
        char test_char = tests[i];
        // Comparar ft_isalpha con isalpha
        printf("Test '%c' (ASCII %d): ft_isalpha: %d | isalpha: %d\n", test_char, test_char, ft_isalpha(test_char), isalpha(test_char));
    }

    return 0;
}