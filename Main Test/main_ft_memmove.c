/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_memmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlibran- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:02:29 by rlibran-          #+#    #+#             */
/*   Updated: 2024/10/02 17:26:01 by rlibran-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

//chat used: https://chatgpt.com/share/66fd640b-072c-800c-ae72-9cb58544dabc
//chat used: https://chatgpt.com/share/66fd65e0-cb88-800c-8dcb-7233a5774bd6

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

void    *ft_memmove(void *dest, const void *src, size_t n);

int main() {
    // Variables para comparar resultados
    int comparacion;

    // Test 1: Copia normal sin solapamiento
    printf("Test 1: Copia normal sin solapamiento\n");
    {
        char fuente[] = "Datos de prueba";
        char destino_ft[20];
        char destino_orig[20];

        ft_memmove(destino_ft, fuente, strlen(fuente) + 1);
        memmove(destino_orig, fuente, strlen(fuente) + 1);

        comparacion = strcmp(destino_ft, destino_orig);
        printf("Resultado ft_memmove: %s\n", destino_ft);
        printf("Resultado memmove:   %s\n", destino_orig);
        printf("Comparación: %s\n\n", comparacion == 0 ? "Iguales" : "Diferentes");
    }

    // Test 2: Copia con solapamiento (destino antes de fuente)
    printf("Test 2: Copia con solapamiento (destino antes de fuente)\n");
    {
        char buffer_ft[30] = "Solapamiento hacia adelante";
        char buffer_orig[30] = "Solapamiento hacia adelante";

        ft_memmove(buffer_ft, buffer_ft + 11, strlen(buffer_ft + 11) + 1);
        memmove(buffer_orig, buffer_orig + 11, strlen(buffer_orig + 11) + 1);

        comparacion = strcmp(buffer_ft, buffer_orig);
        printf("Resultado ft_memmove: %s\n", buffer_ft);
        printf("Resultado memmove:   %s\n", buffer_orig);
        printf("Comparación: %s\n\n", comparacion == 0 ? "Iguales" : "Diferentes");
    }

    // Test 3: Copia con solapamiento (destino después de fuente)
    printf("Test 3: Copia con solapamiento (destino después de fuente)\n");
    {
        char buffer_ft[30] = "Copiar con solapamiento";
        char buffer_orig[30] = "Copiar con solapamiento";

        ft_memmove(buffer_ft + 7, buffer_ft, strlen(buffer_ft) + 1);
        memmove(buffer_orig + 7, buffer_orig, strlen(buffer_orig) + 1);

        comparacion = strcmp(buffer_ft, buffer_orig);
        printf("Resultado ft_memmove: %s\n", buffer_ft + 7);
        printf("Resultado memmove:   %s\n", buffer_orig + 7);
        printf("Comparación: %s\n\n", comparacion == 0 ? "Iguales" : "Diferentes");
    }

    // Test 4: Copia de cero bytes
    printf("Test 4: Copia de cero bytes\n");
    {
        char fuente[] = "Texto original";
        char destino_ft[] = "Texto destino";
        char destino_orig[] = "Texto destino";

        ft_memmove(destino_ft, fuente, 0);
        memmove(destino_orig, fuente, 0);

        comparacion = strcmp(destino_ft, destino_orig);
        printf("Resultado ft_memmove: %s\n", destino_ft);
        printf("Resultado memmove:   %s\n", destino_orig);
        printf("Comparación: %s\n\n", comparacion == 0 ? "Iguales" : "Diferentes");
    }

    // Test 5: Copia dentro del mismo bloque (fuente y destino iguales)
    printf("Test 5: Copia dentro del mismo bloque (fuente y destino iguales)\n");
    {
        char buffer_ft[] = "Mismo bloque";
        char buffer_orig[] = "Mismo bloque";

        ft_memmove(buffer_ft, buffer_ft, strlen(buffer_ft) + 1);
        memmove(buffer_orig, buffer_orig, strlen(buffer_orig) + 1);

        comparacion = strcmp(buffer_ft, buffer_orig);
        printf("Resultado ft_memmove: %s\n", buffer_ft);
        printf("Resultado memmove:   %s\n", buffer_orig);
        printf("Comparación: %s\n\n", comparacion == 0 ? "Iguales" : "Diferentes");
    }

    // Test 6: Copia de datos binarios
    printf("Test 6: Copia de datos binarios\n");
    {
        int fuente[] = {1, 2, 3, 4, 5};
        int destino_ft[5];
        int destino_orig[5];

        ft_memmove(destino_ft, fuente, sizeof(fuente));
        memmove(destino_orig, fuente, sizeof(fuente));

        comparacion = memcmp(destino_ft, destino_orig, sizeof(fuente));
        printf("Resultado ft_memmove: ");
        for (int i = 0; i < 5; i++) {
            printf("%d ", destino_ft[i]);
        }
        printf("\nResultado memmove:   ");
        for (int i = 0; i < 5; i++) {
            printf("%d ", destino_orig[i]);
        }
        printf("\nComparación: %s\n\n", comparacion == 0 ? "Iguales" : "Diferentes");
    }

    // Test 7: Copia de una gran cantidad de datos
    printf("Test 7: Copia de una gran cantidad de datos\n");
    {
        size_t tamano = 1000000; // 1 millón de bytes
        char *fuente = malloc(tamano);
        char *destino_ft = malloc(tamano);
        char *destino_orig = malloc(tamano);

        memset(fuente, 'A', tamano);

        ft_memmove(destino_ft, fuente, tamano);
        memmove(destino_orig, fuente, tamano);

        comparacion = memcmp(destino_ft, destino_orig, tamano);
        printf("Comparación: %s\n\n", comparacion == 0 ? "Iguales" : "Diferentes");

        free(fuente);
        free(destino_ft);
        free(destino_orig);
    }

    // Test 8: Copia con punteros nulos
//    printf("Test 8: Copia con punteros nulos\n");
//    {
//        void *destino_ft = NULL;
//        void *fuente_ft = NULL;
//        void *destino_orig = NULL;
//        void *fuente_orig = NULL;
//
//        ft_memmove(destino_ft, fuente_ft, 5);
//        memmove(destino_orig, fuente_orig, 5); // Comportamiento indefinido en memmove
//
//        printf("Test completado. (Nota: memmove estándar puede causar comportamiento indefinido)\n\n");
//    }

    // Test 9: Copia con número de bytes mayor que el tamaño real de los datos
//    printf("Test 9: Copia con número de bytes mayor que el tamaño real de los datos\n");
//    {
//        char fuente[] = "Prueba";
//        char destino_ft[20];
//        char destino_orig[20];
//
//        ft_memmove(destino_ft, fuente, 10);
//        memmove(destino_orig, fuente, 10);
//
//        comparacion = memcmp(destino_ft, destino_orig, 10);
//        printf("Resultado ft_memmove: %s\n", destino_ft);
//        printf("Resultado memmove:   %s\n", destino_orig);
//        printf("Comparación de los primeros 10 bytes: %s\n\n", comparacion == 0 ? "Iguales" : "Diferentes");
//    }

    // Test 10: Copia de estructuras
    printf("Test 10: Copia de estructuras\n");
    {
        typedef struct {
            int id;
            char nombre[20];
            float salario;
        } Empleado;

        Empleado e1 = {1, "Juan Pérez", 50000.0};
        Empleado e2_ft;
        Empleado e2_orig;

        ft_memmove(&e2_ft, &e1, sizeof(Empleado));
        memmove(&e2_orig, &e1, sizeof(Empleado));

        comparacion = memcmp(&e2_ft, &e2_orig, sizeof(Empleado));
        printf("Resultado ft_memmove: ID=%d, Nombre=%s, Salario=%.2f\n", e2_ft.id, e2_ft.nombre, e2_ft.salario);
        printf("Resultado memmove:   ID=%d, Nombre=%s, Salario=%.2f\n", e2_orig.id, e2_orig.nombre, e2_orig.salario);
        printf("Comparación: %s\n\n", comparacion == 0 ? "Iguales" : "Diferentes");
    }

    // Test 11: Copia con destino y fuente siendo NULL
//    printf("Test 11: Copia con destino y fuente siendo NULL\n");
//    {
//        void *destino_ft = NULL;
//        void *fuente_ft = NULL;
//        void *destino_orig = NULL;
//        void *fuente_orig = NULL;
//
//        ft_memmove(destino_ft, fuente_ft, 5);
//        memmove(destino_orig, fuente_orig, 5); // Comportamiento indefinido en memmove
//
//        printf("Test completado. (Nota: memmove estándar puede causar comportamiento indefinido)\n\n");
//    }

    // Test 12: Copia con n menor o igual a 0
//    printf("Test 12: Copia con n menor o igual a 0\n");
//    {
//        char fuente[] = "Prueba";
//        char destino_ft[10] = "Destino";
//        char destino_orig[10] = "Destino";
//        ptrdiff_t n = -5;
//
//        ft_memmove(destino_ft, fuente, n);
//        memmove(destino_orig, fuente, n); // Comportamiento indefinido en memmove
//
//        comparacion = strcmp(destino_ft, destino_orig);
//        printf("Resultado ft_memmove: %s\n", destino_ft);
//        printf("Resultado memmove:   %s\n", destino_orig);
//        printf("Comparación: %s\n\n", comparacion == 0 ? "Iguales o comportamiento indefinido" : "Diferentes o comportamiento indefinido");
//    }

    // Test 13: Copia parcial de datos
    printf("Test 13: Copia parcial de datos\n");
    {
        char fuente[] = "Copiar parcialmente";
        char destino_ft[20];
        char destino_orig[20];

        ft_memmove(destino_ft, fuente, 6); // Copiamos solo "Copiar"
        memmove(destino_orig, fuente, 6);

        destino_ft[6] = '\0';    // Añadimos el terminador nulo
        destino_orig[6] = '\0';

        comparacion = strcmp(destino_ft, destino_orig);
        printf("Resultado ft_memmove: %s\n", destino_ft);
        printf("Resultado memmove:   %s\n", destino_orig);
        printf("Comparación: %s\n\n", comparacion == 0 ? "Iguales" : "Diferentes");
    }

    // Test 14: Copia con datos superpuestos y diferentes tipos de datos
    printf("Test 14: Copia con datos superpuestos y diferentes tipos de datos\n");
    {
        int datos_ft[] = {1, 2, 3, 4, 5, 6};
        int datos_orig[] = {1, 2, 3, 4, 5, 6};

        ft_memmove(&datos_ft[2], &datos_ft[0], 3 * sizeof(int));
        memmove(&datos_orig[2], &datos_orig[0], 3 * sizeof(int));

        comparacion = memcmp(datos_ft, datos_orig, sizeof(datos_ft));
        printf("Resultado ft_memmove: ");
        for (int i = 0; i < 6; i++) {
            printf("%d ", datos_ft[i]);
        }
        printf("\nResultado memmove:   ");
        for (int i = 0; i < 6; i++) {
            printf("%d ", datos_orig[i]);
        }
        printf("\nComparación: %s\n\n", comparacion == 0 ? "Iguales" : "Diferentes");
    }

    // Test 15: Copia con tipos de datos personalizados
    printf("Test 15: Copia con tipos de datos personalizados\n");
    {
        typedef struct {
            int id;
            char nombre[20];
        } Registro;

        Registro registros_ft[5] = {
            {1, "Uno"},
            {2, "Dos"},
            {3, "Tres"},
            {4, "Cuatro"},
            {5, "Cinco"}
        };
        Registro registros_orig[5] = {
            {1, "Uno"},
            {2, "Dos"},
            {3, "Tres"},
            {4, "Cuatro"},
            {5, "Cinco"}
        };

        ft_memmove(&registros_ft[1], &registros_ft[0], 2 * sizeof(Registro));
        memmove(&registros_orig[1], &registros_orig[0], 2 * sizeof(Registro));

        comparacion = memcmp(registros_ft, registros_orig, sizeof(registros_ft));
        printf("Resultado ft_memmove:\n");
        for (int i = 0; i < 5; i++) {
            printf("ID: %d, Nombre: %s\n", registros_ft[i].id, registros_ft[i].nombre);
        }
        printf("\nResultado memmove:\n");
        for (int i = 0; i < 5; i++) {
            printf("ID: %d, Nombre: %s\n", registros_orig[i].id, registros_orig[i].nombre);
        }
        printf("\nComparación: %s\n\n", comparacion == 0 ? "Iguales" : "Diferentes");
    }

    return 0;
}
