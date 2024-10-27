/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlibran- <rlibran-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 03:34:49 by rlibran-          #+#    #+#             */
/*   Updated: 2024/10/14 03:34:49 by rlibran-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// chat used: https://chatgpt.com/share/670db9d1-8738-800c-9d6e-0cfa894799d2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Colores para la salida en la terminal */
#define COLOR_GREEN "\x1b[32m"
#define COLOR_RED "\x1b[31m"
#define COLOR_RESET "\x1b[0m"

/* Prototipo de la función a testear */
char	**ft_split(char const *s, char c);

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

/* Implementación de simple_split para comparación */
char	**simple_split(const char *s, char delimiter)
{
	char **result;
	int count = 0;
	int i = 0, start = 0, end = 0;
	int j = 0;

	/* Contar el número de substrings */
	while (s[i])
	{
		while (s[i] == delimiter)
			i++;
		if (s[i] != '\0')
		{
			count++;
			while (s[i] != delimiter && s[i] != '\0')
				i++;
		}
	}

	/* Reservar memoria para el arreglo de substrings */
	result = (char **)malloc((count + 1) * sizeof(char *));
	if (!result)
		return (NULL);

	/* Extraer las substrings */
	i = 0;
	while (s[i])
	{
		while (s[i] == delimiter)
			i++;
		if (s[i] != '\0')
		{
			start = i;
			while (s[i] != delimiter && s[i] != '\0')
				i++;
			end = i;
			int len = end - start;
			result[j] = (char *)malloc((len + 1) * sizeof(char));
			if (!result[j])
			{
				/* Liberar memoria en caso de fallo */
				for (int k = 0; k < j; k++)
					free(result[k]);
				free(result);
				return (NULL);
			}
			strncpy(result[j], s + start, len);
			result[j][len] = '\0';
			j++;
		}
	}
	result[j] = NULL;
	return (result);
}

/* Función para liberar memoria de un arreglo de strings */
void	free_split(char **split)
{
	int i = 0;
	if (!split)
		return;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

/* Función para comparar dos arreglos de strings */
int	compare_splits(char **split1, char **split2)
{
	int i = 0;

	if (!split1 && !split2)
		return (1);
	if (!split1 || !split2)
		return (0);
	while (split1[i] && split2[i])
	{
		if (strcmp(split1[i], split2[i]) != 0)
			return (0);
		i++;
	}
	if (split1[i] == NULL && split2[i] == NULL)
		return (1);
	return (0);
}

/* Función para imprimir un arreglo de strings */
void	print_split(char **split)
{
	int i = 0;
	printf("[");
	while (split && split[i])
	{
		printf("\"%s\"", split[i]);
		if (split[i + 1])
			printf(", ");
		i++;
	}
	printf("]");
}

/* Casos de prueba */

void	test_case1()
{
	const char *test_str = "hola,mundo,desde,C";
	char delimiter = ',';
	char **ft_result;
	char **simple_result;
	int pass;

	printf("Test Case 1:\n");
	printf("Input String: \"%s\"\n", test_str);
	printf("Delimiter: '%c'\n", delimiter);

	ft_result = ft_split(test_str, delimiter);
	simple_result = simple_split(test_str, delimiter);

	pass = compare_splits(ft_result, simple_result);

	printf("Expected Result: ");
	print_split(simple_result);
	printf("\nft_split Result:   ");
	print_split(ft_result);
	printf("\n");

	if (pass)
		printf(COLOR_GREEN "Test Passed\n" COLOR_RESET);
	else
		printf(COLOR_RED "Test Failed\n" COLOR_RESET);

	free_split(ft_result);
	free_split(simple_result);
	printf("\n");
}

void	test_case2()
{
	const char *test_str = ",,,hello,,world,,,C,,";
	char delimiter = ',';
	char **ft_result;
	char **simple_result;
	int pass;

	printf("Test Case 2:\n");
	printf("Input String: \"%s\"\n", test_str);
	printf("Delimiter: '%c'\n", delimiter);

	ft_result = ft_split(test_str, delimiter);
	simple_result = simple_split(test_str, delimiter);

	pass = compare_splits(ft_result, simple_result);

	printf("Expected Result: ");
	print_split(simple_result);
	printf("\nft_split Result:   ");
	print_split(ft_result);
	printf("\n");

	if (pass)
		printf(COLOR_GREEN "Test Passed\n" COLOR_RESET);
	else
		printf(COLOR_RED "Test Failed\n" COLOR_RESET);

	free_split(ft_result);
	free_split(simple_result);
	printf("\n");
}

void	test_case3()
{
	const char *test_str = "no_delimiters_here";
	char delimiter = ',';
	char **ft_result;
	char **simple_result;
	int pass;

	printf("Test Case 3:\n");
	printf("Input String: \"%s\"\n", test_str);
	printf("Delimiter: '%c'\n", delimiter);

	ft_result = ft_split(test_str, delimiter);
	simple_result = simple_split(test_str, delimiter);

	pass = compare_splits(ft_result, simple_result);

	printf("Expected Result: ");
	print_split(simple_result);
	printf("\nft_split Result:   ");
	print_split(ft_result);
	printf("\n");

	if (pass)
		printf(COLOR_GREEN "Test Passed\n" COLOR_RESET);
	else
		printf(COLOR_RED "Test Failed\n" COLOR_RESET);

	free_split(ft_result);
	free_split(simple_result);
	printf("\n");
}

void	test_case4()
{
	const char *test_str = "";
	char delimiter = ',';
	char **ft_result;
	char **simple_result;
	int pass;

	printf("Test Case 4:\n");
	printf("Input String: \"%s\"\n", test_str);
	printf("Delimiter: '%c'\n", delimiter);

	ft_result = ft_split(test_str, delimiter);
	simple_result = simple_split(test_str, delimiter);

	pass = compare_splits(ft_result, simple_result);

	printf("Expected Result: ");
	print_split(simple_result);
	printf("\nft_split Result:   ");
	print_split(ft_result);
	printf("\n");

	if (pass)
		printf(COLOR_GREEN "Test Passed\n" COLOR_RESET);
	else
		printf(COLOR_RED "Test Failed\n" COLOR_RESET);

	free_split(ft_result);
	free_split(simple_result);
	printf("\n");
}

void	test_case5()
{
	const char *test_str = "a,b,c,d,e,f,g";
	char delimiter = ',';
	char **ft_result;
	char **simple_result;
	int pass;

	printf("Test Case 5:\n");
	printf("Input String: \"%s\"\n", test_str);
	printf("Delimiter: '%c'\n", delimiter);

	ft_result = ft_split(test_str, delimiter);
	simple_result = simple_split(test_str, delimiter);

	pass = compare_splits(ft_result, simple_result);

	printf("Expected Result: ");
	print_split(simple_result);
	printf("\nft_split Result:   ");
	print_split(ft_result);
	printf("\n");

	if (pass)
		printf(COLOR_GREEN "Test Passed\n" COLOR_RESET);
	else
		printf(COLOR_RED "Test Failed\n" COLOR_RESET);

	free_split(ft_result);
	free_split(simple_result);
	printf("\n");
}

void	test_case6()
{
	const char *test_str = "   multiple   spaces   ";
	char delimiter = ' ';
	char **ft_result;
	char **simple_result;
	int pass;

	printf("Test Case 6:\n");
	printf("Input String: \"%s\"\n", test_str);
	printf("Delimiter: '%c'\n", delimiter);

	ft_result = ft_split(test_str, delimiter);
	simple_result = simple_split(test_str, delimiter);

	pass = compare_splits(ft_result, simple_result);

	printf("Expected Result: ");
	print_split(simple_result);
	printf("\nft_split Result:   ");
	print_split(ft_result);
	printf("\n");

	if (pass)
		printf(COLOR_GREEN "Test Passed\n" COLOR_RESET);
	else
		printf(COLOR_RED "Test Failed\n" COLOR_RESET);

	free_split(ft_result);
	free_split(simple_result);
	printf("\n");
}

void	test_case7()
{
	const char *test_str = "delimiter_at_end,";
	char delimiter = ',';
	char **ft_result;
	char **simple_result;
	int pass;

	printf("Test Case 7:\n");
	printf("Input String: \"%s\"\n", test_str);
	printf("Delimiter: '%c'\n", delimiter);

	ft_result = ft_split(test_str, delimiter);
	simple_result = simple_split(test_str, delimiter);

	pass = compare_splits(ft_result, simple_result);

	printf("Expected Result: ");
	print_split(simple_result);
	printf("\nft_split Result:   ");
	print_split(ft_result);
	printf("\n");

	if (pass)
		printf(COLOR_GREEN "Test Passed\n" COLOR_RESET);
	else
		printf(COLOR_RED "Test Failed\n" COLOR_RESET);

	free_split(ft_result);
	free_split(simple_result);
	printf("\n");
}

void	test_case8()
{
	const char *test_str = ",start_with_delimiter";
	char delimiter = ',';
	char **ft_result;
	char **simple_result;
	int pass;

	printf("Test Case 8:\n");
	printf("Input String: \"%s\"\n", test_str);
	printf("Delimiter: '%c'\n", delimiter);

	ft_result = ft_split(test_str, delimiter);
	simple_result = simple_split(test_str, delimiter);

	pass = compare_splits(ft_result, simple_result);

	printf("Expected Result: ");
	print_split(simple_result);
	printf("\nft_split Result:   ");
	print_split(ft_result);
	printf("\n");

	if (pass)
		printf(COLOR_GREEN "Test Passed\n" COLOR_RESET);
	else
		printf(COLOR_RED "Test Failed\n" COLOR_RESET);

	free_split(ft_result);
	free_split(simple_result);
	printf("\n");
}

void	test_case9()
{
	const char *test_str = "singleword";
	char delimiter = ' ';
	char **ft_result;
	char **simple_result;
	int pass;

	printf("Test Case 9:\n");
	printf("Input String: \"%s\"\n", test_str);
	printf("Delimiter: '%c'\n", delimiter);

	ft_result = ft_split(test_str, delimiter);
	simple_result = simple_split(test_str, delimiter);

	pass = compare_splits(ft_result, simple_result);

	printf("Expected Result: ");
	print_split(simple_result);
	printf("\nft_split Result:   ");
	print_split(ft_result);
	printf("\n");

	if (pass)
		printf(COLOR_GREEN "Test Passed\n" COLOR_RESET);
	else
		printf(COLOR_RED "Test Failed\n" COLOR_RESET);

	free_split(ft_result);
	free_split(simple_result);
	printf("\n");
}

void	test_case10()
{
	const char *test_str = "|||";
	char delimiter = '|';
	char **ft_result;
	char **simple_result;
	int pass;

	printf("Test Case 10:\n");
	printf("Input String: \"%s\"\n", test_str);
	printf("Delimiter: '%c'\n", delimiter);

	ft_result = ft_split(test_str, delimiter);
	simple_result = simple_split(test_str, delimiter);

	pass = compare_splits(ft_result, simple_result);

	printf("Expected Result: ");
	print_split(simple_result);
	printf("\nft_split Result:   ");
	print_split(ft_result);
	printf("\n");

	if (pass)
		printf(COLOR_GREEN "Test Passed\n" COLOR_RESET);
	else
		printf(COLOR_RED "Test Failed\n" COLOR_RESET);

	free_split(ft_result);
	free_split(simple_result);
	printf("\n");
}

void	test_case11()
{
	const char *test_str = "nonempty";
	char delimiter = '\0';
	char **ft_result;
	char **simple_result;
	int pass;

	printf("Test Case 11:\n");
	printf("Input String: \"%s\"\n", test_str);
	printf("Delimiter: '%c'\n", delimiter);

	ft_result = ft_split(test_str, delimiter);
	simple_result = simple_split(test_str, delimiter);

	pass = compare_splits(ft_result, simple_result);

	printf("Expected Result: ");
	print_split(simple_result);
	printf("\nft_split Result:   ");
	print_split(ft_result);
	printf("\n");

	if (pass)
		printf(COLOR_GREEN "Test Passed\n" COLOR_RESET);
	else
		printf(COLOR_RED "Test Failed\n" COLOR_RESET);

	free_split(ft_result);
	free_split(simple_result);
	printf("\n");
}

/* Función principal */
int	main(void)
{
	/* Lista de funciones de prueba */
	void (*test_cases[])() = {
		test_case1,
		test_case2,
		test_case3,
		test_case4,
		test_case5,
		test_case6,
		test_case7,
		test_case8,
		test_case9,
		test_case10,
		test_case11
	};
	int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

	printf("=== Testing ft_split ===\n\n");

	/* Ejecutar cada caso de prueba */
	for (int i = 0; i < num_tests; i++)
	{
		test_cases[i]();
	}

	printf("=== Testing Completed ===\n");
	return (0);
}