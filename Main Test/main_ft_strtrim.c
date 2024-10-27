/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strtrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlibran- <rlibran-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 02:11:27 by rlibran-          #+#    #+#             */
/*   Updated: 2024/10/14 02:11:27 by rlibran-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Prototipo de la función a probar
char	*ft_strtrim(char const *s1, char const *set);

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
	dup = (char *)malloc((len + 1));
	if (!dup)
		return (NULL);
	ft_memcpy(dup, str, len);
	dup[len] = '\0';
	return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return ((char *)s);
}

// Función de referencia: simple_strtrim
char	*simple_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && strchr(set, s1[start]))
		start++;
	end = strlen(s1);
	while (end > start && strchr(set, s1[end - 1]))
		end--;
	trimmed = (char *)malloc(end - start + 1);
	if (!trimmed)
		return (NULL);
	i = 0;
	while (start < end)
		trimmed[i++] = s1[start++];
	trimmed[i] = '\0';
	return (trimmed);
}

// Códigos de colores ANSI
#define COLOR_GREEN "\033[0;32m"
#define COLOR_RED   "\033[0;31m"
#define COLOR_RESET "\033[0m"

// Función para comparar dos cadenas y determinar si son iguales
int	compare_strings(const char *s1, const char *s2)
{
	if (s1 == NULL && s2 == NULL)
		return (1);
	if (s1 == NULL || s2 == NULL)
		return (0);
	return (strcmp(s1, s2) == 0);
}

// Función para imprimir el resultado de una prueba
void	print_test_result(int passed, const char *test_name)
{
	if (passed)
		printf(COLOR_GREEN "✔ %s PASSED\n" COLOR_RESET, test_name);
	else
		printf(COLOR_RED "✖ %s FAILED\n" COLOR_RESET, test_name);
}

// Caso de Prueba 1: Trim espacios al inicio y al final
void	test_case1(void)
{
	const char	*input = "   Hola Mundo   ";
	const char	*set = " ";
	const char	*expected = "Hola Mundo";
	char		*result_ft;
	char		*result_ref;

	result_ft = ft_strtrim(input, set);
	result_ref = simple_strtrim(input, set);
	int	passed = compare_strings(result_ft, result_ref);

	printf("Test Case 1: Trim espacios al inicio y al final\n");
	printf("Input: \"%s\"\n", input);
	printf("Set de caracteres a eliminar: \"%s\"\n", set);
	printf("Esperado: \"%s\"\n", expected);
	printf("ft_strtrim: \"%s\"\n", result_ft);
	printf("simple_strtrim: \"%s\"\n", result_ref);
	print_test_result(passed, "Test Case 1");
	free(result_ft);
	free(result_ref);
	printf("\n");
}

// Caso de Prueba 2: Trim múltiples tipos de espacios (espacios, tabulaciones y saltos de línea)
void	test_case2(void)
{
	const char	*input = "\t\n  Hola Mundo \n\t";
	const char	*set = " \t\n";
	const char	*expected = "Hola Mundo";
	char		*result_ft;
	char		*result_ref;

	result_ft = ft_strtrim(input, set);
	result_ref = simple_strtrim(input, set);
	int	passed = compare_strings(result_ft, result_ref);

	printf("Test Case 2: Trim múltiples tipos de espacios (espacios, tabulaciones y saltos de línea)\n");
	printf("Input: \"%s\"\n", input);
	printf("Set de caracteres a eliminar: \"%s\"\n", set);
	printf("Esperado: \"%s\"\n", expected);
	printf("ft_strtrim: \"%s\"\n", result_ft);
	printf("simple_strtrim: \"%s\"\n", result_ref);
	print_test_result(passed, "Test Case 2");
	free(result_ft);
	free(result_ref);
	printf("\n");
}

// Caso de Prueba 3: Trim caracteres que no están presentes
void	test_case3(void)
{
	const char	*input = "Hola Mundo";
	const char	*set = "xyz";
	const char	*expected = "Hola Mundo";
	char		*result_ft;
	char		*result_ref;

	result_ft = ft_strtrim(input, set);
	result_ref = simple_strtrim(input, set);
	int	passed = compare_strings(result_ft, result_ref);

	printf("Test Case 3: Trim caracteres que no están presentes\n");
	printf("Input: \"%s\"\n", input);
	printf("Set de caracteres a eliminar: \"%s\"\n", set);
	printf("Esperado: \"%s\"\n", expected);
	printf("ft_strtrim: \"%s\"\n", result_ft);
	printf("simple_strtrim: \"%s\"\n", result_ref);
	print_test_result(passed, "Test Case 3");
	free(result_ft);
	free(result_ref);
	printf("\n");
}

// Caso de Prueba 4: Trim toda la cadena
void	test_case4(void)
{
	const char	*input = "*****";
	const char	*set = "*";
	const char	*expected = "";
	char		*result_ft;
	char		*result_ref;

	result_ft = ft_strtrim(input, set);
	result_ref = simple_strtrim(input, set);
	int	passed = compare_strings(result_ft, result_ref);

	printf("Test Case 4: Trim toda la cadena\n");
	printf("Input: \"%s\"\n", input);
	printf("Set de caracteres a eliminar: \"%s\"\n", set);
	printf("Esperado: \"%s\"\n", expected);
	printf("ft_strtrim: \"%s\"\n", result_ft);
	printf("simple_strtrim: \"%s\"\n", result_ref);
	print_test_result(passed, "Test Case 4");
	free(result_ft);
	free(result_ref);
	printf("\n");
}

// Caso de Prueba 5: Cadena vacía
void	test_case5(void)
{
	const char	*input = "";
	const char	*set = " ";
	const char	*expected = "";
	char		*result_ft;
	char		*result_ref;

	result_ft = ft_strtrim(input, set);
	result_ref = simple_strtrim(input, set);
	int	passed = compare_strings(result_ft, result_ref);

	printf("Test Case 5: Cadena vacía\n");
	printf("Input: \"%s\"\n", input);
	printf("Set de caracteres a eliminar: \"%s\"\n", set);
	printf("Esperado: \"%s\"\n", expected);
	printf("ft_strtrim: \"%s\"\n", result_ft);
	printf("simple_strtrim: \"%s\"\n", result_ref);
	print_test_result(passed, "Test Case 5");
	free(result_ft);
	free(result_ref);
	printf("\n");
}

// Caso de Prueba 6: Cadena con solo caracteres a eliminar
void	test_case6(void)
{
	const char	*input = "~~~";
	const char	*set = "~";
	const char	*expected = "";
	char		*result_ft;
	char		*result_ref;

	result_ft = ft_strtrim(input, set);
	result_ref = simple_strtrim(input, set);
	int	passed = compare_strings(result_ft, result_ref);

	printf("Test Case 6: Cadena con solo caracteres a eliminar\n");
	printf("Input: \"%s\"\n", input);
	printf("Set de caracteres a eliminar: \"%s\"\n", set);
	printf("Esperado: \"%s\"\n", expected);
	printf("ft_strtrim: \"%s\"\n", result_ft);
	printf("simple_strtrim: \"%s\"\n", result_ref);
	print_test_result(passed, "Test Case 6");
	free(result_ft);
	free(result_ref);
	printf("\n");
}

// Caso de Prueba 7: Cadena sin caracteres a eliminar
void	test_case7(void)
{
	const char	*input = "HolaMundo";
	const char	*set = "";
	const char	*expected = "HolaMundo";
	char		*result_ft;
	char		*result_ref;

	result_ft = ft_strtrim(input, set);
	result_ref = simple_strtrim(input, set);
	int	passed = compare_strings(result_ft, result_ref);

	printf("Test Case 7: Cadena sin caracteres a eliminar\n");
	printf("Input: \"%s\"\n", input);
	printf("Set de caracteres a eliminar: \"%s\"\n", set);
	printf("Esperado: \"%s\"\n", expected);
	printf("ft_strtrim: \"%s\"\n", result_ft);
	printf("simple_strtrim: \"%s\"\n", result_ref);
	print_test_result(passed, "Test Case 7");
	free(result_ft);
	free(result_ref);
	printf("\n");
}

// Caso de Prueba 8: Trim con caracteres especiales
void	test_case8(void)
{
	const char	*input = "\n\t@Hola@Mundo@\t\n";
	const char	*set = "@\t\n";
	const char	*expected = "Hola@Mundo";
	char		*result_ft;
	char		*result_ref;

	result_ft = ft_strtrim(input, set);
	result_ref = simple_strtrim(input, set);
	int	passed = compare_strings(result_ft, result_ref);

	printf("Test Case 8: Trim con caracteres especiales\n");
	printf("Input: \"%s\"\n", input);
	printf("Set de caracteres a eliminar: \"%s\"\n", set);
	printf("Esperado: \"%s\"\n", expected);
	printf("ft_strtrim: \"%s\"\n", result_ft);
	printf("simple_strtrim: \"%s\"\n", result_ref);
	print_test_result(passed, "Test Case 8");
	free(result_ft);
	free(result_ref);
	printf("\n");
}

// Caso de Prueba 9: Trim con caracteres no imprimibles
void	test_case9(void)
{
	const char	*input = "\x01\x02Hola Mundo\x03\x04";
	const char	*set = "\x01\x02\x03\x04";
	const char	*expected = "Hola Mundo";
	char		*result_ft;
	char		*result_ref;

	result_ft = ft_strtrim(input, set);
	result_ref = simple_strtrim(input, set);
	int	passed = compare_strings(result_ft, result_ref);

	printf("Test Case 9: Trim con caracteres no imprimibles\n");
	printf("Input: \"\\x01\\x02Hola Mundo\\x03\\x04\"\n");
	printf("Set de caracteres a eliminar: \"\\x01\\x02\\x03\\x04\"\n");
	printf("Esperado: \"%s\"\n", expected);
	printf("ft_strtrim: \"%s\"\n", result_ft);
	printf("simple_strtrim: \"%s\"\n", result_ref);
	print_test_result(passed, "Test Case 9");
	free(result_ft);
	free(result_ref);
	printf("\n");
}

// Caso de Prueba 10: Trim en una cadena muy larga
void	test_case10(void)
{
	// Crear una cadena larga con espacios al inicio y al final
	char	input[1001];
	char	set[] = " ";
	char	*expected;
	char	*result_ft;
	char	*result_ref;
	int		i;

	// Llenar la cadena con 500 espacios, 1 carácter 'A', y 500 espacios
	for (i = 0; i < 500; i++)
		input[i] = ' ';
	input[500] = 'A';
	for (i = 501; i < 1000; i++)
		input[i] = ' ';
	input[1000] = '\0';

	// Esperado es "A"
	expected = "A";

	result_ft = ft_strtrim(input, set);
	result_ref = simple_strtrim(input, set);
	int	passed = compare_strings(result_ft, result_ref);

	printf("Test Case 10: Trim en una cadena muy larga\n");
	printf("Input: \"[500 espacios]A[500 espacios]\"\n");
	printf("Set de caracteres a eliminar: \"%s\"\n", set);
	printf("Esperado: \"%s\"\n", expected);
	printf("ft_strtrim: \"%s\"\n", result_ft);
	printf("simple_strtrim: \"%s\"\n", result_ref);
	print_test_result(passed, "Test Case 10");
	free(result_ft);
	free(result_ref);
	printf("\n");
}

// Función main que ejecuta todos los casos de prueba
int	main(void)
{
	printf("===== Pruebas para ft_strtrim =====\n\n");
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
	printf("===== Fin de las pruebas =====\n");
	return (0);
}
