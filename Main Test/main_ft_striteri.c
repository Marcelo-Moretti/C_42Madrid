/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_striteri.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlibran- <rlibran-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 21:24:11 by rlibran-          #+#    #+#             */
/*   Updated: 2024/10/16 21:24:11 by rlibran-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// chat used: https://chatgpt.com/share/671013ce-86a8-800c-aa5f-560fb1139e92
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definición de colores para la consola
#define RESET   "\033[0m"
#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"

// Prototipo de tu función ft_striteri (asumimos que está en otra librería)
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

// Prototipo de la función estándar equivalente
void	simple_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int i;

	if (!s || !f)
		return;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// Funciones auxiliares para las pruebas
void	to_uppercase(unsigned int i, char *c)
{
	(void)i; // No usamos 'i' en esta función
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

void	increment_char(unsigned int i, char *c)
{
	*c = *c + i;
}

void	set_X_on_even(unsigned int i, char *c)
{
	if (i % 2 == 0)
		*c = 'X';
}

// Casos de prueba

void	test_case1()
{
	char str1[] = "hola mundo";
	char str2[] = "hola mundo";

	printf("Test Case 1: Conversión a Mayúsculas\n");
	printf("Cadena Original: '%s'\n", str1);

	ft_striteri(str1, to_uppercase);
	simple_striteri(str2, to_uppercase);

	printf("Resultado ft_striteri: '%s'\n", str1);
	printf("Resultado simple_striteri: '%s'\n", str2);

	if (strcmp(str1, str2) == 0)
		printf(GREEN "Test Passed\n" RESET);
	else
		printf(RED "Test Failed\n" RESET);

	printf("\n");
}

void	test_case2()
{
	char str1[] = "abcdef";
	char str2[] = "abcdef";

	printf("Test Case 2: Incremento de Caracteres\n");
	printf("Cadena Original: '%s'\n", str1);

	ft_striteri(str1, increment_char);
	simple_striteri(str2, increment_char);

	printf("Resultado ft_striteri: '%s'\n", str1);
	printf("Resultado simple_striteri: '%s'\n", str2);

	if (strcmp(str1, str2) == 0)
		printf(GREEN "Test Passed\n" RESET);
	else
		printf(RED "Test Failed\n" RESET);

	printf("\n");
}

void	test_case3()
{
	char str1[] = "123456789";
	char str2[] = "123456789";

	printf("Test Case 3: Establecer 'X' en Posiciones Pares\n");
	printf("Cadena Original: '%s'\n", str1);

	ft_striteri(str1, set_X_on_even);
	simple_striteri(str2, set_X_on_even);

	printf("Resultado ft_striteri: '%s'\n", str1);
	printf("Resultado simple_striteri: '%s'\n", str2);

	if (strcmp(str1, str2) == 0)
		printf(GREEN "Test Passed\n" RESET);
	else
		printf(RED "Test Failed\n" RESET);

	printf("\n");
}

void	test_case4()
{
	char str1[] = "";
	char str2[] = "";

	printf("Test Case 4: Cadena Vacía\n");
	printf("Cadena Original: '%s'\n", str1);

	ft_striteri(str1, to_uppercase);
	simple_striteri(str2, to_uppercase);

	printf("Resultado ft_striteri: '%s'\n", str1);
	printf("Resultado simple_striteri: '%s'\n", str2);

	if (strcmp(str1, str2) == 0)
		printf(GREEN "Test Passed\n" RESET);
	else
		printf(RED "Test Failed\n" RESET);

	printf("\n");
}

void	test_case5()
{
	char str1[] = "¡Hola, Mundo!";
	char str2[] = "¡Hola, Mundo!";

	printf("Test Case 5: Caracteres Especiales\n");
	printf("Cadena Original: '%s'\n", str1);

	ft_striteri(str1, to_uppercase);
	simple_striteri(str2, to_uppercase);

	printf("Resultado ft_striteri: '%s'\n", str1);
	printf("Resultado simple_striteri: '%s'\n", str2);

	if (strcmp(str1, str2) == 0)
		printf(GREEN "Test Passed\n" RESET);
	else
		printf(RED "Test Failed\n" RESET);

	printf("\n");
}

void	test_case6()
{
	char str1[] = "abc\0def";
	char str2[] = "abc\0def";

	printf("Test Case 6: Nulo en Medio de la Cadena\n");
	printf("Cadena Original: 'abc\\0def'\n");

	ft_striteri(str1, to_uppercase);
	simple_striteri(str2, to_uppercase);

	printf("Resultado ft_striteri: 'abc\\0def'\n");
	printf("Resultado simple_striteri: 'abc\\0def'\n");

	if (memcmp(str1, str2, 7) == 0)
		printf(GREEN "Test Passed\n" RESET);
	else
		printf(RED "Test Failed\n" RESET);

	printf("\n");
}

void	test_case7()
{
	char str1[] = "12345!@#$%";
	char str2[] = "12345!@#$%";

	printf("Test Case 7: Cadena con Caracteres No Alfabéticos\n");
	printf("Cadena Original: '%s'\n", str1);

	ft_striteri(str1, to_uppercase);
	simple_striteri(str2, to_uppercase);

	printf("Resultado ft_striteri: '%s'\n", str1);
	printf("Resultado simple_striteri: '%s'\n", str2);

	if (strcmp(str1, str2) == 0)
		printf(GREEN "Test Passed\n" RESET);
	else
		printf(RED "Test Failed\n" RESET);

	printf("\n");
}

void	test_case8()
{
	char str1[] = "test";

	printf("Test Case 8: Función Nula\n");
	printf("Cadena Original: '%s'\n", str1);

	ft_striteri(str1, NULL);

	printf("Resultado ft_striteri: '%s'\n", str1);
	printf(GREEN "Test Passed (No debe modificar la cadena)\n" RESET);

	printf("\n");
}

void	test_case9()
{
	char *str1 = NULL;

	printf("Test Case 9: Cadena Nula\n");

	ft_striteri(str1, to_uppercase);

	printf(GREEN "Test Passed (No debe causar error)\n" RESET);

	printf("\n");
}

int	main(void)
{
	// Llamada a cada caso de prueba
	test_case1();
	test_case2();
	test_case3();
	test_case4();
	test_case5();
	test_case6();
	test_case7();
	test_case8();
	test_case9();

	return (0);
}
