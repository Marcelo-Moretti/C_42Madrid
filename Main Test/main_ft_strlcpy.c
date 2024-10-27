/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strlcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlibran- <rlibran-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 23:49:54 by rlibran-          #+#    #+#             */
/*   Updated: 2024/10/08 13:56:14 by rlibran-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//chat used: https://chatgpt.com/share/67051c5c-40bc-800c-8402-a766af450dcf

// Prototipos de las funciones
size_t ft_strlcpy(char *dst, const char *src, size_t size);
size_t simple_strlcpy(char *dst, const char *src, size_t size);

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}


// Implementación de simple_strlcpy (simula strlcpy)
size_t simple_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i = 0;
	size_t src_length = 0;

	while (src[src_length] != '\0')
		src_length++;

	if (dstsize > 0)
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}

	return src_length;
}

// Función para comparar y ejecutar las pruebas
void test_strlcpy(const char *test_name, const char *src, size_t dstsize)
{
    char dest_ft[1000] = {0};
    char dest_simple[1000] = {0};

    size_t ret_ft = ft_strlcpy(dest_ft, src, dstsize);
    size_t ret_simple = simple_strlcpy(dest_simple, src, dstsize);

    printf("%s\n", test_name);
    printf("ft_strlcpy    : dest = '%s', return = %zu\n", dest_ft, ret_ft);
    printf("simple_strlcpy: dest = '%s', return = %zu\n", dest_simple, ret_simple);

    if (strcmp(dest_ft, dest_simple) == 0 && ret_ft == ret_simple)
        printf("Resultado: OK\n\n");
    else
        printf("Resultado: Error\n\n");
}

int main(void)
{
    // Test 1: Caso básico con tamaño adecuado
    char src1[] = "Hola mundo";
    test_strlcpy("Test 1: Caso básico con tamaño adecuado", src1, 20);

    // Test 2: dstsize es 0
    char src2[] = "Hola mundo";
    test_strlcpy("Test 2: dstsize es 0", src2, 0);

    // Test 3: dstsize menor que longitud de src
    char src3[] = "Hola mundo";
    test_strlcpy("Test 3: dstsize menor que longitud de src", src3, 5);

    // Test 4: src es una cadena vacía
    char src4[] = "";
    test_strlcpy("Test 4: src es una cadena vacía", src4, 10);

    // Test 5: dstsize es mayor que la longitud de src
    char src5[] = "Hola mundo";
    test_strlcpy("Test 5: dstsize es mayor que longitud de src", src5, 50);

    // Test 6: src y dst son el mismo puntero
    char buffer6[] = "Buffer compartido";
    test_strlcpy("Test 6: src y dst son el mismo puntero", buffer6, sizeof(buffer6));

    // Test 7: dstsize es 1 (solo espacio para el terminador nulo)
    char src7[] = "Hola mundo";
    test_strlcpy("Test 7: dstsize es 1", src7, 1);

    // Test 8: src contiene caracteres especiales
    char src8[] = "Linea1\nLinea2\tTabbed";
    test_strlcpy("Test 8: src contiene caracteres especiales", src8, 30);

    // Test 9: src es muy larga y dstsize es pequeño
    char src9[1000];
    memset(src9, 'A', 999);
    src9[999] = '\0';
    test_strlcpy("Test 9: src muy largo y dstsize pequeño", src9, 10);

    // Test 10: dstsize es exactamente strlen(src) + 1
    char src10[] = "Exacto";
    test_strlcpy("Test 10: dstsize es exactamente strlen(src) + 1", src10, strlen(src10) + 1);

    // Test 11: src con caracteres no ASCII
    char src11[] = "Cadena con acentos áéíóú";
    test_strlcpy("Test 11: src con caracteres no ASCII", src11, 50);

    // Test 12: src es muy grande y dstsize es suficiente
    char src12[1000];
    memset(src12, 'B', 999);
    src12[999] = '\0';
    test_strlcpy("Test 12: src muy grande y dstsize suficiente", src12, sizeof(src12));

    // Test 13: src es grande y dstsize es pequeño
    char src13[1000];
    memset(src13, 'C', 999);
    src13[999] = '\0';
    test_strlcpy("Test 13: src grande y dstsize pequeño", src13, 5);

    // Test 14: dstsize es mayor al máximo de size_t (hipotético)
    char src14[] = "Este es un test con tamaño muy grande";
    test_strlcpy("Test 14: dstsize grande", src14, (size_t)-1);

    // Test 15: src es pequeña, dstsize es muy grande
    char src15[] = "Cadena pequeña";
    test_strlcpy("Test 15: src pequeña y dstsize grande", src15, 500);

    return 0;
}

