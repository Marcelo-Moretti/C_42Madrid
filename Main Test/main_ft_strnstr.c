/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strnstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlibran- <rlibran-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 23:49:57 by rlibran-          #+#    #+#             */
/*   Updated: 2024/10/12 23:49:57 by rlibran-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// chat used: https://chatgpt.com/share/670af3e1-37b4-800c-96ae-5f1bb50ccfc1
#include <stdio.h>
#include <string.h>

/* Prototipo de tu función ft_strnstr */
char	*ft_strnstr(const char *big, const char *little, size_t len);

/* Implementación de simple_strnstr */
char	*simple_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0') // Si "little" es una cadena vacía, retorna "big".
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < len) // Recorremos "big" hasta llegar a "len" o el final de la cadena.
	{
		j = 0;
		// Comparamos caracteres de "big" con "little", asegurándonos de no exceder "len".
		while (big[i + j] == little[j] && (i + j) < len)
		{
			if (little[j + 1] == '\0') // Si llegamos al final de "little", hemos encontrado una coincidencia.
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (NULL); // Si no se encuentra "little" en "big", retorna NULL.
}

/* Funciones de casos de prueba */
void	test_case1(void);
void	test_case2(void);
void	test_case3(void);
void	test_case4(void);
void	test_case5(void);
void	test_case6(void);
void	test_case7(void);
void	test_case8(void);
void	test_case9(void);
void	test_case10(void);

int	main(void)
{
	printf("Pruebas de ft_strnstr:\n\n");
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

/* Caso de prueba 1: needle es una cadena vacía */
void	test_case1(void)
{
	const char	haystack[] = "Hola Mundo";
	const char	needle[] = "";
	size_t		len = 5;
	char		*result_ft;
	char		*result_std;

	printf("Caso 1: needle es una cadena vacía\n");
	printf("haystack: \"%s\", needle: \"%s\", len: %zu\n", haystack, needle, len);

	result_ft = ft_strnstr(haystack, needle, len);
	result_std = simple_strnstr(haystack, needle, len);

	printf("Resultado ft_strnstr: \"%s\"\n", result_ft);
	printf("Resultado strnstr: \"%s\"\n", result_std);

	if (result_ft == result_std)
		printf("Test 1: OK\n\n");
	else
		printf("Test 1: FALLO\n\n");
}

/* Caso de prueba 2: needle no está en haystack */
void	test_case2(void)
{
	const char	haystack[] = "Hola Mundo";
	const char	needle[] = "42";
	size_t		len = 10;
	char		*result_ft;
	char		*result_std;

	printf("Caso 2: needle no está en haystack\n");
	printf("haystack: \"%s\", needle: \"%s\", len: %zu\n", haystack, needle, len);

	result_ft = ft_strnstr(haystack, needle, len);
	result_std = simple_strnstr(haystack, needle, len);

	printf("Resultado ft_strnstr: \"%s\"\n", result_ft);
	printf("Resultado strnstr: \"%s\"\n", result_std);

	if (result_ft == result_std)
		printf("Test 2: OK\n\n");
	else
		printf("Test 2: FALLO\n\n");
}

/* Caso de prueba 3: needle al principio de haystack */
void	test_case3(void)
{
	const char	haystack[] = "Hola Mundo";
	const char	needle[] = "Hola";
	size_t		len = 4;
	char		*result_ft;
	char		*result_std;

	printf("Caso 3: needle al principio de haystack\n");
	printf("haystack: \"%s\", needle: \"%s\", len: %zu\n", haystack, needle, len);

	result_ft = ft_strnstr(haystack, needle, len);
	result_std = simple_strnstr(haystack, needle, len);

	printf("Resultado ft_strnstr: \"%s\"\n", result_ft);
	printf("Resultado strnstr: \"%s\"\n", result_std);

	if (result_ft == result_std)
		printf("Test 3: OK\n\n");
	else
		printf("Test 3: FALLO\n\n");
}

/* Caso de prueba 4: needle al final de haystack */
void	test_case4(void)
{
	const char	haystack[] = "Hola Mundo";
	const char	needle[] = "Mundo";
	size_t		len = 10;
	char		*result_ft;
	char		*result_std;

	printf("Caso 4: needle al final de haystack\n");
	printf("haystack: \"%s\", needle: \"%s\", len: %zu\n", haystack, needle, len);

	result_ft = ft_strnstr(haystack, needle, len);
	result_std = simple_strnstr(haystack, needle, len);

	printf("Resultado ft_strnstr: \"%s\"\n", result_ft);
	printf("Resultado strnstr: \"%s\"\n", result_std);

	if (result_ft == result_std)
		printf("Test 4: OK\n\n");
	else
		printf("Test 4: FALLO\n\n");
}

/* Caso de prueba 5: len menor que posición de needle */
void	test_case5(void)
{
	const char	haystack[] = "Hola Mundo";
	const char	needle[] = "Mundo";
	size_t		len = 5;
	char		*result_ft;
	char		*result_std;

	printf("Caso 5: len menor que posición de needle\n");
	printf("haystack: \"%s\", needle: \"%s\", len: %zu\n", haystack, needle, len);

	result_ft = ft_strnstr(haystack, needle, len);
	result_std = simple_strnstr(haystack, needle, len);

	printf("Resultado ft_strnstr: \"%s\"\n", result_ft);
	printf("Resultado strnstr: \"%s\"\n", result_std);

	if (result_ft == result_std)
		printf("Test 5: OK\n\n");
	else
		printf("Test 5: FALLO\n\n");
}

/* Caso de prueba 6: len es 0 */
void	test_case6(void)
{
	const char	haystack[] = "Hola Mundo";
	const char	needle[] = "Hola";
	size_t		len = 0;
	char		*result_ft;
	char		*result_std;

	printf("Caso 6: len es 0\n");
	printf("haystack: \"%s\", needle: \"%s\", len: %zu\n", haystack, needle, len);

	result_ft = ft_strnstr(haystack, needle, len);
	result_std = simple_strnstr(haystack, needle, len);

	printf("Resultado ft_strnstr: \"%s\"\n", result_ft);
	printf("Resultado strnstr: \"%s\"\n", result_std);

	if (result_ft == result_std)
		printf("Test 6: OK\n\n");
	else
		printf("Test 6: FALLO\n\n");
}

/* Caso de prueba 7: needle más largo que haystack */
void	test_case7(void)
{
	const char	haystack[] = "Hola";
	const char	needle[] = "Hola Mundo";
	size_t		len = 10;
	char		*result_ft;
	char		*result_std;

	printf("Caso 7: needle más largo que haystack\n");
	printf("haystack: \"%s\", needle: \"%s\", len: %zu\n", haystack, needle, len);

	result_ft = ft_strnstr(haystack, needle, len);
	result_std = simple_strnstr(haystack, needle, len);

	printf("Resultado ft_strnstr: \"%s\"\n", result_ft);
	printf("Resultado strnstr: \"%s\"\n", result_std);

	if (result_ft == result_std)
		printf("Test 7: OK\n\n");
	else
		printf("Test 7: FALLO\n\n");
}

/* Caso de prueba 8: caracteres repetidos en haystack */
void	test_case8(void)
{
	const char	haystack[] = "aaaaabaaaaa";
	const char	needle[] = "baaaa";
	size_t		len = 10;
	char		*result_ft;
	char		*result_std;

	printf("Caso 8: caracteres repetidos en haystack\n");
	printf("haystack: \"%s\", needle: \"%s\", len: %zu\n", haystack, needle, len);

	result_ft = ft_strnstr(haystack, needle, len);
	result_std = simple_strnstr(haystack, needle, len);

	printf("Resultado ft_strnstr: \"%s\"\n", result_ft);
	printf("Resultado strnstr: \"%s\"\n", result_std);

	if (result_ft == result_std)
		printf("Test 8: OK\n\n");
	else
		printf("Test 8: FALLO\n\n");
}

/* Caso de prueba 9: buscar un carácter único */
void	test_case9(void)
{
	const char	haystack[] = "abcdefg";
	const char	needle[] = "e";
	size_t		len = 7;
	char		*result_ft;
	char		*result_std;

	printf("Caso 9: buscar un carácter único\n");
	printf("haystack: \"%s\", needle: \"%s\", len: %zu\n", haystack, needle, len);

	result_ft = ft_strnstr(haystack, needle, len);
	result_std = simple_strnstr(haystack, needle, len);

	printf("Resultado ft_strnstr: \"%s\"\n", result_ft);
	printf("Resultado strnstr: \"%s\"\n", result_std);

	if (result_ft == result_std)
		printf("Test 9: OK\n\n");
	else
		printf("Test 9: FALLO\n\n");
}

/* Caso de prueba 10: needle igual a haystack */
void	test_case10(void)
{
	const char	haystack[] = "Hola Mundo";
	const char	needle[] = "Hola Mundo";
	size_t		len = 20;
	char		*result_ft;
	char		*result_std;

	printf("Caso 10: needle igual a haystack\n");
	printf("haystack: \"%s\", needle: \"%s\", len: %zu\n", haystack, needle, len);

	result_ft = ft_strnstr(haystack, needle, len);
	result_std = simple_strnstr(haystack, needle, len);

	printf("Resultado ft_strnstr: \"%s\"\n", result_ft);
	printf("Resultado strnstr: \"%s\"\n", result_std);

	if (result_ft == result_std)
		printf("Test 10: OK\n\n");
	else
		printf("Test 10: FALLO\n\n");
}