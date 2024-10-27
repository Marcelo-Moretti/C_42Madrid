/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_substr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlibran- <rlibran-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:17:57 by rlibran-          #+#    #+#             */
/*   Updated: 2024/10/13 22:17:57 by rlibran-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Prototipo de la función ft_substr
char	*ft_substr(char const *s, unsigned int start, size_t len);

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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

char	*ft_strdup(const char *str)
{
	char	*dup;
	size_t	len;

	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	ft_memcpy(dup, str, len);
	dup[len] = '\0';
	return (dup);
}

// Función auxiliar para comparar resultados
void compare_results(char *result, const char *expected, const char *test_desc)
{
    printf("%s\n", test_desc);
    printf("Resultado ft_substr: \"%s\"\n", result);
    printf("Resultado esperado:  \"%s\"\n", expected);
    if (strcmp(result, expected) == 0)
        printf("Test PASADO OK\n");
    else
        printf("Test FALLADO KO\n");
    printf("--------------------------------------\n");
    free(result);
}

// Caso de prueba 1: Subcadena normal
void test_case1()
{
    char *s = "Hola Mundo";
    char *expected = "Mundo";
    char *result = ft_substr(s, 5, 5);
    compare_results(result, expected, "Caso 1: Subcadena normal (start = 5, len = 5)");
}

// Caso de prueba 2: Longitud mayor que el tamaño disponible
void test_case2()
{
    char *s = "Hola";
    char *expected = "la";
    char *result = ft_substr(s, 2, 10);
    compare_results(result, expected, "Caso 2: Longitud mayor que el tamaño disponible (start = 2, len = 10)");
}

// Caso de prueba 3: Índice de inicio mayor que la longitud de la cadena
void test_case3()
{
    char *s = "Hola";
    char *expected = "";
    char *result = ft_substr(s, 10, 5);
    compare_results(result, expected, "Caso 3: Índice de inicio mayor que la longitud (start = 10, len = 5)");
}

// Caso de prueba 4: Longitud es 0
void test_case4()
{
    char *s = "Hola";
    char *expected = "";
    char *result = ft_substr(s, 1, 0);
    compare_results(result, expected, "Caso 4: Longitud es 0 (start = 1, len = 0)");
}

// Caso de prueba 5: Cadena vacía
void test_case5()
{
    char *s = "";
    char *expected = "";
    char *result = ft_substr(s, 0, 5);
    compare_results(result, expected, "Caso 5: Cadena vacía (start = 0, len = 5)");
}

// Caso de prueba 6: Cadena con espacios y caracteres especiales
void test_case6()
{
    char *s = "  Hola\t\n Mundo";
    char *expected = "Hola\t\n";
    char *result = ft_substr(s, 2, 6);
    compare_results(result, expected, "Caso 6: Subcadena con espacios y caracteres especiales (start = 2, len = 6)");
}

// Caso de prueba 7: Subcadena desde el inicio de la cadena
void test_case7()
{
    char *s = "42Madrid";
    char *expected = "42";
    char *result = ft_substr(s, 0, 2);
    compare_results(result, expected, "Caso 7: Subcadena desde el inicio (start = 0, len = 2)");
}

// Función main que ejecuta los casos de prueba
int main(void)
{
    printf("=== Pruebas de la función ft_substr ===\n\n");
    test_case1();
    test_case2();
    test_case3();
    test_case4();
    test_case5();
    test_case6();
    test_case7();

    return 0;
}