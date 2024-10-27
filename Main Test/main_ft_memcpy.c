/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlibran- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:59:46 by rlibran-          #+#    #+#             */
/*   Updated: 2024/10/02 14:24:39 by rlibran-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>  // Para la función original memcpy

// Prototipo de la función ft_memcpy que está en ../ft_memcpy.c
void *ft_memcpy(void *dest, const void *src, size_t n);

// Función para imprimir un bloque de memoria como caracteres
void print_memory(const char *label, const char *buffer, size_t n)
{
    printf("%s: ", label);
    for (size_t i = 0; i < n; i++)
    {
        if (buffer[i] == '\0')
            printf("\\0 ");
        else
            printf("%c ", buffer[i]);
    }
    printf("\n");
}

int main(void)
{
    // Caso de prueba 1: Copiar una cadena de caracteres
    char src1[] = "Hello, World!";
    char dest1[20];
    ft_memcpy(dest1, src1, strlen(src1) + 1);  // +1 para copiar el terminador nulo
    print_memory("Prueba 1 (ft_memcpy):", dest1, 20);

    // Caso de prueba 2: Comparar con memcpy estándar
    char dest2[20];
    memcpy(dest2, src1, strlen(src1) + 1);
    print_memory("Prueba 2 (memcpy estándar):", dest2, 20);

    // Caso de prueba 3: Copiar en un bloque más pequeño
    char dest3[5];
    ft_memcpy(dest3, src1, 5);  // Solo copiar los primeros 5 caracteres
    print_memory("Prueba 3 (ft_memcpy, solo 5 caracteres):", dest3, 5);
    
    // Caso de prueba 3B: Copiar en un bloque más pequeño                        
    char dest4[5];                                                              
    memcpy(dest4, src1, 5);  // Solo copiar los primeros 5 caracteres        
    print_memory("Prueba 3 (memcpy, solo 5 caracteres):", dest4, 5);
    
    // Caso de prueba 4: Copiar con punteros nulos
    char *null_dest = NULL;
    char *null_src = NULL;
    printf("\nPrueba 4 (ft_memcpy con punteros nulos): ");
    if (ft_memcpy(null_dest, null_src, 5) == NULL)
        printf("Punteros nulos gestionados correctamente.\n");
    else
        printf("Error al gestionar punteros nulos.\n");

    // Caso de prueba 5: Superposición de bloques de memoria (fuente y destino)
    char src5[20] = "Overlapping test";
    ft_memcpy(src5 + 5, src5, 10);  // Copiar dentro del mismo buffer, con superposición
    print_memory("Prueba 5 (ft_memcpy, superposición):", src5, 20);

    // Caso de prueba 6: Copiar 0 bytes
    char src6[] = "Source";
    char dest6[10] = "Dest";
    ft_memcpy(dest6, src6, 0);  // No debería cambiar nada
    print_memory("Prueba 6 (ft_memcpy, copiar 0 bytes):", dest6, 10);

    return 0;
}

