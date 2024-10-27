/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlibran- <rlibran-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:59:45 by rlibran-          #+#    #+#             */
/*   Updated: 2024/10/13 22:59:45 by rlibran-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Prototipo de la función a probar */
char    *ft_strjoin(char const *s1, char const *s2);

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	while (dest == src || !n)
		return (dest);
	while (n > i)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/* Prototipos de funciones de prueba */
void    test_case1(void);
void    test_case2(void);
void    test_case3(void);
void    test_case4(void);
void    test_case5(void);
void    test_case6(void);
void    test_case7(void);
void    test_case8(void);
void    test_case9(void);
void    test_case10(void);

/* Función auxiliar para imprimir resultados */
void    print_result(int test_number, const char *result, const char *expected);

/* Implementación de los casos de prueba */
void    test_case1(void)
{
    char    *s1 = "Hola";
    char    *s2 = " Mundo";
    char    *expected = "Hola Mundo";
    char    *result;

    result = ft_strjoin(s1, s2);
    print_result(1, result, expected);
    free(result);
}

void    test_case2(void)
{
    char    *s1 = "";
    char    *s2 = "Mundo";
    char    *expected = "Mundo";
    char    *result;

    result = ft_strjoin(s1, s2);
    print_result(2, result, expected);
    free(result);
}

void    test_case3(void)
{
    char    *s1 = "Hola";
    char    *s2 = "";
    char    *expected = "Hola";
    char    *result;

    result = ft_strjoin(s1, s2);
    print_result(3, result, expected);
    free(result);
}

void    test_case4(void)
{
    char    *s1 = "";
    char    *s2 = "";
    char    *expected = "";
    char    *result;

    result = ft_strjoin(s1, s2);
    print_result(4, result, expected);
    free(result);
}

void    test_case5(void)
{
    char    *s1 = "12345";
    char    *s2 = "67890";
    char    *expected = "1234567890";
    char    *result;

    result = ft_strjoin(s1, s2);
    print_result(5, result, expected);
    free(result);
}

void    test_case6(void)
{
    char    *s1 = "Cadenas";
    char    *s2 = " de prueba con espacios ";
    char    *expected = "Cadenas de prueba con espacios ";
    char    *result;

    result = ft_strjoin(s1, s2);
    print_result(6, result, expected);
    free(result);
}

void    test_case7(void)
{
    char    *s1 = "SpecialChars!@#$%^&*()";
    char    *s2 = "+=-[]{}|;:',.<>/?`~";
    char    *expected = "SpecialChars!@#$%^&*()+=-[]{}|;:',.<>/?`~";
    char    *result;

    result = ft_strjoin(s1, s2);
    print_result(7, result, expected);
    free(result);
}

void    test_case8(void)
{
    char    *s1 = "123";
    char    *s2 = "4567890";
    char    *expected = "1234567890";
    char    *result;

    result = ft_strjoin(s1, s2);
    print_result(8, result, expected);
    free(result);
}

void    test_case9(void)
{
    char    *s1 = "Line1\n";
    char    *s2 = "Line2\nLine3";
    char    *expected = "Line1\nLine2\nLine3";
    char    *result;

    result = ft_strjoin(s1, s2);
    print_result(9, result, expected);
    free(result);
}

void    test_case10(void)
{
    char    *s1 = NULL;
    char    *s2 = "No hay primero";
    char    *expected = NULL;
    char    *result;

    result = ft_strjoin(s1, s2);
    print_result(10, result, expected);
    /* No llamar a free porque result es NULL */
}

/* Implementación de la función auxiliar para imprimir resultados */
void    print_result(int test_number, const char *result, const char *expected)
{
    if (result == NULL && expected == NULL)
    {
        printf("Test %d: OK (Ambos resultados son NULL)\n", test_number);
        return;
    }
    if (result == NULL || expected == NULL)
    {
        printf("Test %d: FAIL (Uno de los resultados es NULL)\n", test_number);
        if (result != NULL)
            printf("  Resultado obtenido: \"%s\"\n", result);
        if (expected != NULL)
            printf("  Resultado esperado: \"%s\"\n", expected);
        return;
    }
    if (strcmp(result, expected) == 0)
        printf("Test %d: OK\n", test_number);
    else
    {
        printf("Test %d: FAIL\n", test_number);
        printf("  Resultado obtenido: \"%s\"\n", result);
        printf("  Resultado esperado: \"%s\"\n", expected);
    }
}

/* Función principal */
int     main(void)
{
    printf("Iniciando pruebas para ft_strjoin...\n\n");
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
    printf("\nPruebas completadas.\n");
    return (0);
}