/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strrchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlibran- <rlibran-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:32:31 by rlibran-          #+#    #+#             */
/*   Updated: 2024/10/11 22:32:31 by rlibran-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// chat used: https://chatgpt.com/share/67099b64-3a3c-800c-89c7-7e31180bbf09

#include <stdio.h>
#include <string.h>

// Declaración de ft_strrchr para poder usarla
char    *ft_strrchr(const char *s, int c);

// Función main con los tests
int     main(void)
{
    // Variables para los tests
    const char  *str;
    int         c;
    char        *result_ft;
    char        *result_original;

    // Test 1: Carácter presente múltiples veces
    str = "Hello World!";
    c = 'o';
    printf("Test 1 - Multiple occurrences:\n");
    printf("String:          \"%s\"\n", str);
    printf("Character:       '%c'\n", c);
    result_ft = ft_strrchr(str, c);
    result_original = strrchr(str, c);
    printf("ft_strrchr:      \"%s\"\n", result_ft);
    printf("strrchr:         \"%s\"\n", result_original);
    printf("Result:          %s\n\n", result_ft == result_original ? "PASS" : "FAIL");

    // Test 2: Carácter presente una sola vez
    str = "42 Madrid";
    c = 'M';
    printf("Test 2 - Single occurrence:\n");
    printf("String:          \"%s\"\n", str);
    printf("Character:       '%c'\n", c);
    result_ft = ft_strrchr(str, c);
    result_original = strrchr(str, c);
    printf("ft_strrchr:      \"%s\"\n", result_ft);
    printf("strrchr:         \"%s\"\n", result_original);
    printf("Result:          %s\n\n", result_ft == result_original ? "PASS" : "FAIL");

    // Test 3: Carácter no presente
    str = "Testing";
    c = 'z';
    printf("Test 3 - Character not present:\n");
    printf("String:          \"%s\"\n", str);
    printf("Character:       '%c'\n", c);
    result_ft = ft_strrchr(str, c);
    result_original = strrchr(str, c);
    printf("ft_strrchr:      %p\n", result_ft);
    printf("strrchr:         %p\n", result_original);
    printf("Result:          %s\n\n", result_ft == result_original ? "PASS" : "FAIL");

    // Test 4: Carácter nulo '\0'
    str = "End of string";
    c = '\0';
    printf("Test 4 - Null character search:\n");
    printf("String:          \"%s\"\n", str);
    printf("Character:       '\\0'\n");
    result_ft = ft_strrchr(str, c);
    result_original = strrchr(str, c);
    printf("ft_strrchr:      %p\n", result_ft);
    printf("strrchr:         %p\n", result_original);
    printf("Result:          %s\n\n", result_ft == result_original ? "PASS" : "FAIL");

    // Test 5: Cadena vacía
    str = "";
    c = 'a';
    printf("Test 5 - Empty string:\n");
    printf("String:          \"%s\"\n", str);
    printf("Character:       '%c'\n", c);
    result_ft = ft_strrchr(str, c);
    result_original = strrchr(str, c);
    printf("ft_strrchr:      %p\n", result_ft);
    printf("strrchr:         %p\n", result_original);
    printf("Result:          %s\n\n", result_ft == result_original ? "PASS" : "FAIL");

    // Test 6: Carácter al inicio de la cadena
    str = "First character";
    c = 'F';
    printf("Test 6 - Character at start:\n");
    printf("String:          \"%s\"\n", str);
    printf("Character:       '%c'\n", c);
    result_ft = ft_strrchr(str, c);
    result_original = strrchr(str, c);
    printf("ft_strrchr:      \"%s\"\n", result_ft);
    printf("strrchr:         \"%s\"\n", result_original);
    printf("Result:          %s\n\n", result_ft == result_original ? "PASS" : "FAIL");

    // Test 7: Carácter al final de la cadena
    str = "Last character.";
    c = '.';
    printf("Test 7 - Character at end:\n");
    printf("String:          \"%s\"\n", str);
    printf("Character:       '%c'\n", c);
    result_ft = ft_strrchr(str, c);
    result_original = strrchr(str, c);
    printf("ft_strrchr:      \"%s\"\n", result_ft);
    printf("strrchr:         \"%s\"\n", result_original);
    printf("Result:          %s\n\n", result_ft == result_original ? "PASS" : "FAIL");

    // Test 8: Carácter es un espacio
    str = "Space in the middle";
    c = ' ';
    printf("Test 8 - Space character:\n");
    printf("String:          \"%s\"\n", str);
    printf("Character:       ' '\n");
    result_ft = ft_strrchr(str, c);
    result_original = strrchr(str, c);
    printf("ft_strrchr:      \"%s\"\n", result_ft);
    printf("strrchr:         \"%s\"\n", result_original);
    printf("Result:          %s\n\n", result_ft == result_original ? "PASS" : "FAIL");

    // Test 9: Carácter no imprimible
    str = "Non-printable:\n";
    c = '\n';
    printf("Test 9 - Non-printable character:\n");
    printf("String:          \"Non-printable:\\n\"\n");
    printf("Character:       '\\n'\n");
    result_ft = ft_strrchr(str, c);
    result_original = strrchr(str, c);
    printf("ft_strrchr:      %p\n", result_ft);
    printf("strrchr:         %p\n", result_original);
    printf("Result:          %s\n\n", result_ft == result_original ? "PASS" : "FAIL");

    // Test 10: Cadena con caracteres repetidos consecutivos
    str = "aaabbbccc";
    c = 'b';
    printf("Test 10 - Consecutive repeated characters:\n");
    printf("String:          \"%s\"\n", str);
    printf("Character:       '%c'\n", c);
    result_ft = ft_strrchr(str, c);
    result_original = strrchr(str, c);
    printf("ft_strrchr:      \"%s\"\n", result_ft);
    printf("strrchr:         \"%s\"\n", result_original);
    printf("Result:          %s\n", result_ft == result_original ? "PASS" : "FAIL");

    return (0);
}
