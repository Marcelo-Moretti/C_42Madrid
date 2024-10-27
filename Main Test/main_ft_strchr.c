/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlibran- <rlibran-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:26:25 by rlibran-          #+#    #+#             */
/*   Updated: 2024/10/11 18:26:25 by rlibran-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// chat used: https://chatgpt.com/share/67095986-c578-800c-ad30-ddcf9ad1e123
#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c);

int     main(void)
{
    const char  *tests[] = {
        "Hola, mundo",
        "Hola, mundo",
        "Hola, mundo",
        "Hola, mundo",
        "Hola, mundo",
        "",
        "¡Hola, mundo!",
        "Olá, mundo"
    };
    int         chars_to_find[] = {
        'm',    // Caso 1
        'H',    // Caso 2
        'o',    // Caso 3
        'z',    // Caso 4
        '\0',   // Caso 5
        'a'    // Caso 6

    };
    int         num_tests = sizeof(tests) / sizeof(tests[0]);
    int         i;
    char        *result_ft;
    char        *result_orig;

    for (i = 0; i < num_tests; i++)
    {
        result_ft = ft_strchr(tests[i], chars_to_find[i]);
        result_orig = strchr(tests[i], chars_to_find[i]);

        printf("Prueba %d:\n", i + 1);
        printf("Cadena: \"%s\"\n", tests[i]);
        printf("Carácter a buscar: '%c' (%d)\n", chars_to_find[i], chars_to_find[i]);

        if (result_ft == result_orig)
            printf("Resultado: \033[0;32mCorrecto\033[0m\n");
        else if ((result_ft && result_orig) && (strcmp(result_ft, result_orig) == 0))
            printf("Resultado: \033[0;32mCorrecto\033[0m\n");
        else
            printf("Resultado: \033[0;31mIncorrecto\033[0m\n");

        printf("ft_strchr devuelve: %s\n", result_ft ? result_ft : "NULL");
        printf("strchr    devuelve: %s\n", result_orig ? result_orig : "NULL");
        printf("-------------------------------\n");
    }
    return (0);
}