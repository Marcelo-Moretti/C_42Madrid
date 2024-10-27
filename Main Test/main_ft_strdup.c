/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlibran- <rlibran-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:05:39 by rlibran-          #+#    #+#             */
/*   Updated: 2024/10/13 17:05:39 by rlibran-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// chat used: https://chatgpt.com/share/670be41f-1a80-800c-a682-34bb4593a0b1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototipo de la función personalizada ft_strdup
char	*ft_strdup(const char *str);

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



// Función auxiliar para mostrar el resultado de la prueba
void	print_test_result(const char *input, const char *result_ft, const char *result_std)
{
	printf("Entrada: \"%s\"\n", input);
	printf("Resultado ft_strdup: \"%s\"\n", result_ft ? result_ft : "NULL");
	printf("Resultado strdup: \"%s\"\n", result_std ? result_std : "NULL");
	if (result_ft && result_std && strcmp(result_ft, result_std) == 0)
		printf("Test: \033[0;32m[OK]\033[0m\n\n"); // Verde para éxito
	else
		printf("Test: \033[0;31m[FAIL]\033[0m\n\n"); // Rojo para fallo
}

// Caso de prueba 1: Cadena vacía
void	test_case1(void)
{
	const char *input = "";
	char *result_ft = ft_strdup(input);
	char *result_std = strdup(input);
	print_test_result(input, result_ft, result_std);
	free(result_ft);
	free(result_std);
}

// Caso de prueba 2: Cadena normal
void	test_case2(void)
{
	const char *input = "Hola, mundo!";
	char *result_ft = ft_strdup(input);
	char *result_std = strdup(input);
	print_test_result(input, result_ft, result_std);
	free(result_ft);
	free(result_std);
}

// Caso de prueba 3: Cadena con caracteres especiales
void	test_case3(void)
{
	const char *input = "Line1\nLine2\tTabbed";
	char *result_ft = ft_strdup(input);
	char *result_std = strdup(input);
	print_test_result(input, result_ft, result_std);
	free(result_ft);
	free(result_std);
}

// Caso de prueba 4: Cadena larga
void	test_case4(void)
{
	const char *input = "Esta es una cadena muy larga para probar la función ft_strdup. " "Debe manejar cadenas de gran longitud sin problemas.";
	char *result_ft = ft_strdup(input);
	char *result_std = strdup(input);
	print_test_result(input, result_ft, result_std);
	free(result_ft);
	free(result_std);
}

// Caso de prueba 5: Cadena con caracteres nulos intermedios (no permitido en strdup)
void	test_case5(void)
{
	const char *input = "Hola\0Mundo"; // Este caso simula una cadena con un carácter nulo
	char *result_ft = ft_strdup(input);
	char *result_std = strdup(input); // strdup no copiará después del '\0'
	print_test_result(input, result_ft, result_std);
	free(result_ft);
	free(result_std);
}

// Caso de prueba 6: Entrada NULL
void	test_case6(void)
{
	const char *input = NULL;
	char *result_ft = ft_strdup(input);
	char *result_std = NULL; // strdup no maneja NULL, evitamos llamarla
	print_test_result("NULL", result_ft, result_std);
	free(result_ft); // Solo liberamos result_ft si no es NULL
}

// Caso de prueba 7: Cadena con solo espacios
void	test_case7(void)
{
	const char *input = "      ";
	char *result_ft = ft_strdup(input);
	char *result_std = strdup(input);
	print_test_result(input, result_ft, result_std);
	free(result_ft);
	free(result_std);
}

// Caso de prueba 8: Una sola letra
void	test_case8(void)
{
	const char *input = "A";
	char *result_ft = ft_strdup(input);
	char *result_std = strdup(input);
	print_test_result(input, result_ft, result_std);
	free(result_ft);
	free(result_std);
}

// Función principal que ejecuta todas las pruebas
int	main(void)
{
	printf("=== Iniciando pruebas para ft_strdup ===\n\n");

	// Ejecutamos todos los casos de prueba
	test_case1(); // Cadena vacía
	test_case2(); // Cadena normal
	test_case3(); // Cadena con caracteres especiales
	test_case4(); // Cadena larga
	test_case5(); // Cadena con caracteres nulos intermedios
	test_case6(); // Entrada NULL
	test_case7(); // Cadena con solo espacios
	test_case8(); // Una sola letra

	printf("=== Fin de las pruebas ===\n");

	return 0;
}