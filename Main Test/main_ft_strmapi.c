/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strmapi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlibran- <rlibran-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 04:25:00 by rlibran-          #+#    #+#             */
/*   Updated: 2024/10/16 04:25:00 by rlibran-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototipo de tu función ft_strmapi (implementación en otro archivo)
char    *ft_strmapi(char const *s, char (*f)(unsigned int, char));

// Función auxiliar ft_strlen (usada en ft_strmapi)
size_t  ft_strlen(const char *s)
{
    size_t  i = 0;
    while (s[i])
        i++;
    return (i);
}

// Implementación de simple_strmapi para comparar resultados
char    *simple_strmapi(char const *s, char (*f)(unsigned int, char))
{
    if (!s || !f)
        return NULL;

    size_t  len = strlen(s);
    char    *new_str = malloc(len + 1);
    if (!new_str)
        return NULL;

    for (size_t i = 0; i < len; i++)
        new_str[i] = f((unsigned int)i, s[i]);

    new_str[len] = '\0';
    return new_str;
}

// Funciones a utilizar con ft_strmapi
char    to_upper(unsigned int i, char c)
{
    (void)i;
    if (c >= 'a' && c <= 'z')
        return c - 32;
    return c;
}

char    increment_by_index(unsigned int i, char c)
{
    return c + i;
}

char    set_to_asterisk(unsigned int i, char c)
{
    (void)i;
    (void)c;
    return '*';
}

char    toggle_case(unsigned int i, char c)
{
    (void)i;
    if (c >= 'a' && c <= 'z')
        return c - 32;
    else if (c >= 'A' && c <= 'Z')
        return c + 32;
    else
        return c;
}

// Función para imprimir resultados con formato
void    print_test_result(int passed, const char *test_name)
{
    if (passed)
        printf("\033[0;32mTest %s pasado.\033[0m\n\n", test_name);
    else
        printf("\033[0;31mTest %s fallado.\033[0m\n\n", test_name);
}

// Casos de prueba
void    test_case1()
{
    printf("Test Case 1: Convertir a mayúsculas\n");
    char    *input = "hola mundo";
    printf("Cadena de entrada: \"%s\"\n", input);
    printf("Función aplicada: to_upper\n");

    char    *result_ft = ft_strmapi(input, to_upper);
    char    *result_simple = simple_strmapi(input, to_upper);

    printf("Resultado esperado: \"%s\"\n", result_simple);
    printf("Resultado ft_strmapi: \"%s\"\n", result_ft);

    int passed = (strcmp(result_ft, result_simple) == 0);
    print_test_result(passed, "Case 1");

    free(result_ft);
    free(result_simple);
}

void    test_case2()
{
    printf("Test Case 2: Incrementar cada carácter por su índice\n");
    char    *input = "abcde";
    printf("Cadena de entrada: \"%s\"\n", input);
    printf("Función aplicada: increment_by_index\n");

    char    *result_ft = ft_strmapi(input, increment_by_index);
    char    *result_simple = simple_strmapi(input, increment_by_index);

    printf("Resultado esperado: \"%s\"\n", result_simple);
    printf("Resultado ft_strmapi: \"%s\"\n", result_ft);

    int passed = (strcmp(result_ft, result_simple) == 0);
    print_test_result(passed, "Case 2");

    free(result_ft);
    free(result_simple);
}

void    test_case3()
{
    printf("Test Case 3: Cadena de entrada vacía\n");
    char    *input = "";
    printf("Cadena de entrada: \"%s\"\n", input);
    printf("Función aplicada: set_to_asterisk\n");

    char    *result_ft = ft_strmapi(input, set_to_asterisk);
    char    *result_simple = simple_strmapi(input, set_to_asterisk);

    printf("Resultado esperado: \"%s\"\n", result_simple);
    printf("Resultado ft_strmapi: \"%s\"\n", result_ft);

    int passed = (strcmp(result_ft, result_simple) == 0);
    print_test_result(passed, "Case 3");

    free(result_ft);
    free(result_simple);
}

void    test_case4()
{
    printf("Test Case 4: Función NULL\n");
    char    *input = "test";
    printf("Cadena de entrada: \"%s\"\n", input);
    printf("Función aplicada: NULL\n");

    char    *result_ft = ft_strmapi(input, NULL);
    char    *result_simple = simple_strmapi(input, NULL);

    printf("Resultado esperado: NULL\n");
    printf("Resultado ft_strmapi: %s\n", (result_ft == NULL) ? "NULL" : result_ft);

    int passed = (result_ft == NULL && result_simple == NULL);
    print_test_result(passed, "Case 4");
}

void    test_case5()
{
    printf("Test Case 5: Cadena de entrada NULL\n");
    char    *input = NULL;
    printf("Cadena de entrada: NULL\n");
    printf("Función aplicada: to_upper\n");

    char    *result_ft = ft_strmapi(input, to_upper);
    char    *result_simple = simple_strmapi(input, to_upper);

    printf("Resultado esperado: NULL\n");
    printf("Resultado ft_strmapi: %s\n", (result_ft == NULL) ? "NULL" : result_ft);

    int passed = (result_ft == NULL && result_simple == NULL);
    print_test_result(passed, "Case 5");
}

void    test_case6()
{
    printf("Test Case 6: Alternar mayúsculas y minúsculas\n");
    char    *input = "HeLLo WoRLd!";
    printf("Cadena de entrada: \"%s\"\n", input);
    printf("Función aplicada: toggle_case\n");

    char    *result_ft = ft_strmapi(input, toggle_case);
    char    *result_simple = simple_strmapi(input, toggle_case);

    printf("Resultado esperado: \"%s\"\n", result_simple);
    printf("Resultado ft_strmapi: \"%s\"\n", result_ft);

    int passed = (strcmp(result_ft, result_simple) == 0);
    print_test_result(passed, "Case 6");

    free(result_ft);
    free(result_simple);
}

void    test_case7()
{
    printf("Test Case 7: Caracteres no ASCII\n");
    char    *input = "áéíóú";
    printf("Cadena de entrada: \"%s\"\n", input);
    printf("Función aplicada: to_upper\n");

    char    *result_ft = ft_strmapi(input, to_upper);
    char    *result_simple = simple_strmapi(input, to_upper);

    printf("Resultado esperado: \"%s\"\n", result_simple);
    printf("Resultado ft_strmapi: \"%s\"\n", result_ft);

    int passed = (strcmp(result_ft, result_simple) == 0);
    print_test_result(passed, "Case 7");

    free(result_ft);
    free(result_simple);
}

void    test_case8()
{
    printf("Test Case 8: Cadena muy larga\n");
    char    *input = "Esta es una cadena muy larga para probar la función ft_strmapi y ver cómo maneja entradas extensas.";
    printf("Cadena de entrada: \"%s\"\n", input);
    printf("Función aplicada: increment_by_index\n");

    char    *result_ft = ft_strmapi(input, increment_by_index);
    char    *result_simple = simple_strmapi(input, increment_by_index);

    printf("Resultado esperado: \"%s\"\n", result_simple);
    printf("Resultado ft_strmapi: \"%s\"\n", result_ft);

    int passed = (strcmp(result_ft, result_simple) == 0);
    print_test_result(passed, "Case 8");

    free(result_ft);
    free(result_simple);
}

// Función principal
int     main(void)
{
    test_case1();
    test_case2();
    test_case3();
    test_case4();
    test_case5();
    test_case6();
    test_case7();
    test_case8();
    // Puedes agregar más casos de prueba si lo deseas
    return 0;
}
