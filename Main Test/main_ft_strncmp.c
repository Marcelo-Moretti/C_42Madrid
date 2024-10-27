/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strncmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlibran- <rlibran-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 02:43:44 by rlibran-          #+#    #+#             */
/*   Updated: 2024/10/12 02:43:44 by rlibran-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// chat used: https://chatgpt.com/share/6709ca17-bb9c-800c-b44b-3c403042a656
#include <stdio.h>
#include <string.h>

int ft_strncmp(const char *s1, const char *s2, size_t n);

int main(void)
{
    // Test 1: Cadenas idénticas, longitud menor que n
    char *test1_s1 = "Hola";
    char *test1_s2 = "Hola";
    size_t test1_n = 5;

    // Test 2: Cadenas idénticas, longitud igual a n
    char *test2_s1 = "Mundo";
    char *test2_s2 = "Mundo";
    size_t test2_n = 5;

    // Test 3: Cadenas idénticas, longitud mayor que n
    char *test3_s1 = "Programación";
    char *test3_s2 = "Programación";
    size_t test3_n = 6;

    // Test 4: Cadenas diferentes antes de n caracteres
    char *test4_s1 = "Hola";
    char *test4_s2 = "Holi";
    size_t test4_n = 4;

    // Test 5: Cadenas diferentes después de n caracteres
    char *test5_s1 = "Buenos días";
    char *test5_s2 = "Buenos tardes";
    size_t test5_n = 7;

    // Test 6: Una cadena es más corta que n
    char *test6_s1 = "ABC";
    char *test6_s2 = "ABCD";
    size_t test6_n = 10;

    // Test 7: Una o ambas cadenas están vacías
    char *test7_s1 = "";
    char *test7_s2 = "";
    size_t test7_n = 5;

    // Test 8: Cadenas con caracteres especiales
    char *test8_s1 = "Hola\n";
    char *test8_s2 = "Hola\t";
    size_t test8_n = 5;

    // Test 9: Cadenas con caracteres no ASCII
    char *test9_s1 = "áéíóú";
    char *test9_s2 = "áéíóú";
    size_t test9_n = 5;

    // Test 10: n es cero
    char *test10_s1 = "Test";
    char *test10_s2 = "Prueba";
    size_t test10_n = 0;

    // Array de tests
    struct {
        char *s1;
        char *s2;
        size_t n;
        char *description;
    } tests[] = {
        {test1_s1, test1_s2, test1_n, "Test 1: Cadenas idénticas, longitud menor que n"},
        {test2_s1, test2_s2, test2_n, "Test 2: Cadenas idénticas, longitud igual a n"},
        {test3_s1, test3_s2, test3_n, "Test 3: Cadenas idénticas, longitud mayor que n"},
        {test4_s1, test4_s2, test4_n, "Test 4: Cadenas diferentes antes de n caracteres"},
        {test5_s1, test5_s2, test5_n, "Test 5: Cadenas diferentes después de n caracteres"},
        {test6_s1, test6_s2, test6_n, "Test 6: Una cadena es más corta que n"},
        {test7_s1, test7_s2, test7_n, "Test 7: Una o ambas cadenas están vacías"},
        {test8_s1, test8_s2, test8_n, "Test 8: Cadenas con caracteres especiales"},
        {test9_s1, test9_s2, test9_n, "Test 9: Cadenas con caracteres no ASCII"},
        {test10_s1, test10_s2, test10_n, "Test 10: n es cero"},
    };

    // Iterar y ejecutar cada test
    for (int i = 0; i < 10; i++)
    {
        int result_ft = ft_strncmp(tests[i].s1, tests[i].s2, tests[i].n);
        int result_orig = strncmp(tests[i].s1, tests[i].s2, tests[i].n);

        printf("%s\n", tests[i].description);
        printf("s1: \"%s\"\n", tests[i].s1);
        printf("s2: \"%s\"\n", tests[i].s2);
        printf("n: %zu\n", tests[i].n);
        printf("Resultado ft_strncmp: %d\n", result_ft);
        printf("Resultado strncmp: %d\n", result_orig);
        if ((result_ft == 0 && result_orig == 0) || (result_ft < 0 && result_orig < 0) || (result_ft > 0 && result_orig > 0))
            printf("Test pasado OK\n");
        else
            printf("Test fallido KO\n");
        printf("-------------------------------------------------\n");
    }

    return 0;
}
