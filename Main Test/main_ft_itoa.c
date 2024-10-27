/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlibran- <rlibran-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 02:32:06 by rlibran-          #+#    #+#             */
/*   Updated: 2024/10/16 02:32:06 by rlibran-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// chat used: https://chatgpt.com/share/670f142e-42e8-800c-9248-aaf3441d8375
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Prototipo de ft_itoa (asumimos que su implementación está en otro archivo) */
char    *ft_itoa(int n);

/* Implementación de simple_itoa para comparar resultados */
char    *simple_itoa(int n)
{
    char    *str;
    long    nbr;
    int     len;
    int     sign;

    nbr = n;
    sign = (nbr < 0) ? -1 : 1;
    len = (nbr <= 0) ? 1 : 0;
    nbr *= sign;
    long temp_nbr = nbr;
    while (temp_nbr > 0)
    {
        temp_nbr /= 10;
        len++;
    }
    str = (char *)malloc(len + 1);
    if (!str)
        return (NULL);
    str[len] = '\0';
    if (nbr == 0)
        str[0] = '0';
    while (nbr > 0)
    {
        str[--len] = (nbr % 10) + '0';
        nbr /= 10;
    }
    if (sign == -1)
        str[0] = '-';
    return (str);
}

/* Función para imprimir mensajes en colores */
void    print_result(int test_number, int passed, const char *input, const char *expected, const char *got)
{
    if (passed)
        printf("\033[0;32m"); // Verde para éxito
    else
        printf("\033[0;31m"); // Rojo para fallo
    printf("Test %d: ", test_number);
    if (passed)
        printf("PASSED\n");
    else
        printf("FAILED\n");
    printf("\033[0m"); // Reset de color
    printf("  Input: %s\n", input);
    printf("  Expected: %s\n", expected);
    printf("  Got: %s\n\n", got);
}

/* Caso de prueba 1: Número positivo pequeño */
void    test_case1()
{
    int     n = 42;
    char    *result_ft = ft_itoa(n);
    char    *result_simple = simple_itoa(n);
    int     passed = strcmp(result_ft, result_simple) == 0;
    print_result(1, passed, "42", result_simple, result_ft);
    free(result_ft);
    free(result_simple);
}

/* Caso de prueba 2: Número negativo pequeño */
void    test_case2()
{
    int     n = -42;
    char    *result_ft = ft_itoa(n);
    char    *result_simple = simple_itoa(n);
    int     passed = strcmp(result_ft, result_simple) == 0;
    print_result(2, passed, "-42", result_simple, result_ft);
    free(result_ft);
    free(result_simple);
}

/* Caso de prueba 3: Cero */
void    test_case3()
{
    int     n = 0;
    char    *result_ft = ft_itoa(n);
    char    *result_simple = simple_itoa(n);
    int     passed = strcmp(result_ft, result_simple) == 0;
    print_result(3, passed, "0", result_simple, result_ft);
    free(result_ft);
    free(result_simple);
}

/* Caso de prueba 4: Valor máximo de int */
void    test_case4()
{
    int     n = 2147483647;
    char    *result_ft = ft_itoa(n);
    char    *result_simple = simple_itoa(n);
    int     passed = strcmp(result_ft, result_simple) == 0;
    print_result(4, passed, "2147483647", result_simple, result_ft);
    free(result_ft);
    free(result_simple);
}

/* Caso de prueba 5: Valor mínimo de int */
void    test_case5()
{
    int     n = -2147483648;
    char    *result_ft = ft_itoa(n);
    char    *result_simple = simple_itoa(n);
    int     passed = strcmp(result_ft, result_simple) == 0;
    print_result(5, passed, "-2147483648", result_simple, result_ft);
    free(result_ft);
    free(result_simple);
}

/* Caso de prueba 6: Número positivo grande */
void    test_case6()
{
    int     n = 123456789;
    char    *result_ft = ft_itoa(n);
    char    *result_simple = simple_itoa(n);
    int     passed = strcmp(result_ft, result_simple) == 0;
    print_result(6, passed, "123456789", result_simple, result_ft);
    free(result_ft);
    free(result_simple);
}

/* Caso de prueba 7: Número negativo grande */
void    test_case7()
{
    int     n = -987654321;
    char    *result_ft = ft_itoa(n);
    char    *result_simple = simple_itoa(n);
    int     passed = strcmp(result_ft, result_simple) == 0;
    print_result(7, passed, "-987654321", result_simple, result_ft);
    free(result_ft);
    free(result_simple);
}

/* Caso de prueba 8: Número positivo de un dígito */
void    test_case8()
{
    int     n = 7;
    char    *result_ft = ft_itoa(n);
    char    *result_simple = simple_itoa(n);
    int     passed = strcmp(result_ft, result_simple) == 0;
    print_result(8, passed, "7", result_simple, result_ft);
    free(result_ft);
    free(result_simple);
}

/* Caso de prueba 9: Número negativo de un dígito */
void    test_case9()
{
    int     n = -3;
    char    *result_ft = ft_itoa(n);
    char    *result_simple = simple_itoa(n);
    int     passed = strcmp(result_ft, result_simple) == 0;
    print_result(9, passed, "-3", result_simple, result_ft);
    free(result_ft);
    free(result_simple);
}

/* Caso de prueba 10: Número positivo con ceros iniciales (no aplicable en int) */
void    test_case10()
{
    int     n = 000123;
    char    *result_ft = ft_itoa(n);
    char    *result_simple = simple_itoa(n);
    int     passed = strcmp(result_ft, result_simple) == 0;
    print_result(10, passed, "000123", result_simple, result_ft);
    free(result_ft);
    free(result_simple);
}

/* Función main para ejecutar los casos de prueba */
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
    test_case9();
    test_case10();
    return (0);
}
