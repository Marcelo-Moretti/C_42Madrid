/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlibran- <rlibran-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 02:31:27 by rlibran-          #+#    #+#             */
/*   Updated: 2024/10/24 16:49:53 by rlibran-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>

// Prototipo de ft_calloc (asumimos que está en libft.h)
void *ft_calloc(size_t nmemb, size_t size);

// Implementación corregida de ft_bzero
void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}

// Función para comparar los resultados de ft_calloc con calloc
int compare_results(void *ft_result, void *std_result, size_t nmemb, size_t size)
{
    if (ft_result == NULL && std_result == NULL)
        return 1;
    if (ft_result == NULL || std_result == NULL)
        return 0;
    // Comparar el contenido de los bloques de memoria
    return memcmp(ft_result, std_result, nmemb * size) == 0;
}

// Definición de los códigos de color ANSI
#define COLOR_RED "\033[31m"
#define COLOR_GREEN "\033[32m"
#define COLOR_RESET "\033[0m"

// Casos de prueba
void test_case1()
{
    size_t nmemb = 5;
    size_t size = sizeof(int);
    printf("\nTest 1: nmemb = %zu, size = %zu (Caso normal)\n", nmemb, size);
    // Llamar a ft_calloc y calloc
    int *ft_ptr = (int *)ft_calloc(nmemb, size);
    int *std_ptr = (int *)calloc(nmemb, size);
    // Verificar si los bloques de memoria son iguales
    if (compare_results(ft_ptr, std_ptr, nmemb, size))
        printf(COLOR_GREEN "Test 1 PASSED" COLOR_RESET "\n");
    else
        printf(COLOR_RED "Test 1 FAILED" COLOR_RESET "\n");
    // Liberar memoria
    free(ft_ptr);
    free(std_ptr);
}

void test_case2()
{
    size_t nmemb = 0;
    size_t size = sizeof(int);
    printf("\nTest 2: nmemb = %zu, size = %zu (nmemb es 0)\n", nmemb, size);
    int *ft_ptr = (int *)ft_calloc(nmemb, size);
    int *std_ptr = (int *)calloc(nmemb, size);
    printf("ft_ptr: %p, std_ptr: %p\n", (void *)ft_ptr, (void *)std_ptr);
    if (compare_results(ft_ptr, std_ptr, nmemb, size))
        printf(COLOR_GREEN "Test 2 PASSED" COLOR_RESET "\n");
    else
        printf(COLOR_RED "Test 2 FAILED" COLOR_RESET "\n");
    free(ft_ptr);
    free(std_ptr);
}

void test_case3()
{
    size_t nmemb = 5;
    size_t size = 0;
    printf("\nTest 3: nmemb = %zu, size = %zu (size es 0)\n", nmemb, size);
    int *ft_ptr = (int *)ft_calloc(nmemb, size);
    int *std_ptr = (int *)calloc(nmemb, size);
    printf("ft_ptr: %p, std_ptr: %p\n", (void *)ft_ptr, (void *)std_ptr);
    if (compare_results(ft_ptr, std_ptr, nmemb, size))
        printf(COLOR_GREEN "Test 3 PASSED" COLOR_RESET "\n");
    else
        printf(COLOR_RED "Test 3 FAILED" COLOR_RESET "\n");
    free(ft_ptr);
    free(std_ptr);
}

void test_case4()
{
    size_t nmemb = SIZE_MAX;
    size_t size = sizeof(int);
    printf("\nTest 4: nmemb = SIZE_MAX, size = %zu (esperado: desbordamiento)\n", size);
    int *ft_ptr = (int *)ft_calloc(nmemb, size);
    int *std_ptr = (int *)calloc(nmemb, size);
    if (ft_ptr == NULL && std_ptr == NULL)
        printf(COLOR_GREEN "Test 4 PASSED" COLOR_RESET "\n");
    else
        printf(COLOR_RED "Test 4 FAILED" COLOR_RESET "\n");
    free(ft_ptr);
    free(std_ptr);
}

void test_case5()
{
    size_t nmemb = 10;
    size_t size = sizeof(char);
    printf("\nTest 5: nmemb = %zu, size = %zu (char array)\n", nmemb, size);
    char *ft_ptr = (char *)ft_calloc(nmemb, size);
    char *std_ptr = (char *)calloc(nmemb, size);
    if (compare_results(ft_ptr, std_ptr, nmemb, size))
        printf(COLOR_GREEN "Test 5 PASSED" COLOR_RESET "\n");
    else
        printf(COLOR_RED "Test 5 FAILED" COLOR_RESET "\n");
    free(ft_ptr);
    free(std_ptr);
}

void test_case6()
{
    size_t size = 1024;
    size_t nmemb = SIZE_MAX / size;
    printf("\nTest 6: nmemb = SIZE_MAX / %zu, size = %zu (condición límite)\n", size, size);
    void *ft_ptr = ft_calloc(nmemb, size);
    void *std_ptr = calloc(nmemb, size);
    if ((ft_ptr == NULL && std_ptr == NULL) || compare_results(ft_ptr, std_ptr, nmemb, size))
        printf(COLOR_GREEN "Test 6 PASSED" COLOR_RESET "\n");
    else
        printf(COLOR_RED "Test 6 FAILED" COLOR_RESET "\n");
    free(ft_ptr);
    free(std_ptr);
}

void test_case7()
{
    size_t nmemb = 1;
    size_t size = SIZE_MAX;
    printf("\nTest 7: nmemb = %zu, size = SIZE_MAX (esperado: posible fallo por tamaño excesivo)\n", nmemb);
    void *ft_ptr = ft_calloc(nmemb, size);
    void *std_ptr = calloc(nmemb, size);
    if (ft_ptr == NULL && std_ptr == NULL)
        printf(COLOR_GREEN "Test 7 PASSED" COLOR_RESET "\n");
    else if (ft_ptr != NULL && std_ptr != NULL && compare_results(ft_ptr, std_ptr, nmemb, size))
        printf(COLOR_GREEN "Test 7 PASSED" COLOR_RESET "\n");
    else
        printf(COLOR_RED "Test 7 FAILED" COLOR_RESET "\n");
    free(ft_ptr);
    free(std_ptr);
}

void test_case8()
{
    size_t nmemb = 1000000;
    size_t size = 1000;
    printf("\nTest 8: nmemb = %zu, size = %zu (asignación grande)\n", nmemb, size);
    void *ft_ptr = ft_calloc(nmemb, size);
    void *std_ptr = calloc(nmemb, size);
    if ((ft_ptr == NULL && std_ptr == NULL) || compare_results(ft_ptr, std_ptr, nmemb, size))
        printf(COLOR_GREEN "Test 8 PASSED" COLOR_RESET "\n");
    else
        printf(COLOR_RED "Test 8 FAILED" COLOR_RESET "\n");
    free(ft_ptr);
    free(std_ptr);
}

// Función main que ejecuta todos los casos de prueba
int main(void)
{
    printf("Iniciando pruebas de ft_calloc...\n");
    test_case1(); // Caso normal
    test_case2(); // Caso con nmemb = 0
    test_case3(); // Caso con size = 0
    test_case4(); // Caso de desbordamiento
    test_case5(); // Caso con char array
    test_case6(); // Condición límite
    test_case7(); // Caso con size = SIZE_MAX
    test_case8(); // Asignación grande
    // Agrega más casos de prueba aquí según sea necesario
    return 0;
}
