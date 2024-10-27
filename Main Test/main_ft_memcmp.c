/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_memcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlibran- <rlibran-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:35:00 by rlibran-          #+#    #+#             */
/*   Updated: 2024/10/12 20:35:00 by rlibran-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// chat used: https://chatgpt.com/share/670ac2c0-9638-800c-9d7c-8a4ab12568e0
#include <stdio.h>
#include <string.h>

// Prototipo de ft_memcmp (asumimos que está implementada en otro archivo)
int ft_memcmp(const void *s1, const void *s2, size_t n);

// Prototipos de funciones de casos de prueba
void test_case1(void);
void test_case2(void);
void test_case3(void);
void test_case4(void);
void test_case5(void);
void test_case6(void);
void test_case7(void);
void test_case8(void);
void test_case9(void);
void test_case10(void);

int main(void)
{
    printf("Probando la función ft_memcmp...\n\n");

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

    return 0;
}

// Caso de prueba 1: Memorias idénticas
void test_case1(void)
{
    const char s1[] = "Hola Mundo";
    const char s2[] = "Hola Mundo";
    size_t n = strlen(s1);

    printf("Caso de Prueba 1: Memorias idénticas\n");
    printf("s1: \"%s\"\n", s1);
    printf("s2: \"%s\"\n", s2);
    printf("n: %zu\n", n);

    int result_ft = ft_memcmp(s1, s2, n);
    int result_std = memcmp(s1, s2, n);

    printf("Resultado ft_memcmp: %d\n", result_ft);
    printf("Resultado memcmp   : %d\n", result_std);

    if ((result_ft == result_std))
        printf("Caso de Prueba 1: ¡Éxito!\n\n");
    else
        printf("Caso de Prueba 1: ¡Fallo!\n\n");
}

// Caso de prueba 2: Diferencia en el primer byte
void test_case2(void)
{
    const char s1[] = "hola";
    const char s2[] = "Hola";
    size_t n = 4;

    printf("Caso de Prueba 2: Diferencia en el primer byte\n");
    printf("s1: \"%s\"\n", s1);
    printf("s2: \"%s\"\n", s2);
    printf("n: %zu\n", n);

    int result_ft = ft_memcmp(s1, s2, n);
    int result_std = memcmp(s1, s2, n);

    printf("Resultado ft_memcmp: %d\n", result_ft);
    printf("Resultado memcmp   : %d\n", result_std);

    if ((result_ft == result_std))
        printf("Caso de Prueba 2: ¡Éxito!\n\n");
    else
        printf("Caso de Prueba 2: ¡Fallo!\n\n");
}

// Caso de prueba 3: Diferencia en un byte intermedio
void test_case3(void)
{
    const char s1[] = "abcd";
    const char s2[] = "abed";
    size_t n = 4;

    printf("Caso de Prueba 3: Diferencia en un byte intermedio\n");
    printf("s1: \"%s\"\n", s1);
    printf("s2: \"%s\"\n", s2);
    printf("n: %zu\n", n);

    int result_ft = ft_memcmp(s1, s2, n);
    int result_std = memcmp(s1, s2, n);

    printf("Resultado ft_memcmp: %d\n", result_ft);
    printf("Resultado memcmp   : %d\n", result_std);

    if ((result_ft == result_std))
        printf("Caso de Prueba 3: ¡Éxito!\n\n");
    else
        printf("Caso de Prueba 3: ¡Fallo!\n\n");
}

// Caso de prueba 4: Diferencia en el último byte
void test_case4(void)
{
    const char s1[] = "abcde";
    const char s2[] = "abcdx";
    size_t n = 5;

    printf("Caso de Prueba 4: Diferencia en el último byte\n");
    printf("s1: \"%s\"\n", s1);
    printf("s2: \"%s\"\n", s2);
    printf("n: %zu\n", n);

    int result_ft = ft_memcmp(s1, s2, n);
    int result_std = memcmp(s1, s2, n);

    printf("Resultado ft_memcmp: %d\n", result_ft);
    printf("Resultado memcmp   : %d\n", result_std);

    if ((result_ft == result_std))
        printf("Caso de Prueba 4: ¡Éxito!\n\n");
    else
        printf("Caso de Prueba 4: ¡Fallo!\n\n");
}

// Caso de prueba 5: n es cero
void test_case5(void)
{
    const char s1[] = "abc";
    const char s2[] = "xyz";
    size_t n = 0;

    printf("Caso de Prueba 5: n es cero\n");
    printf("s1: \"%s\"\n", s1);
    printf("s2: \"%s\"\n", s2);
    printf("n: %zu\n", n);

    int result_ft = ft_memcmp(s1, s2, n);
    int result_std = memcmp(s1, s2, n);

    printf("Resultado ft_memcmp: %d\n", result_ft);
    printf("Resultado memcmp   : %d\n", result_std);

    if ((result_ft == result_std))
        printf("Caso de Prueba 5: ¡Éxito!\n\n");
    else
        printf("Caso de Prueba 5: ¡Fallo!\n\n");
}

// Caso de prueba 6: Arrays de enteros
void test_case6(void)
{
    int arr1[] = {1, 2, 3};
    int arr2[] = {1, 2, 4};
    size_t n = sizeof(int) * 3;

    printf("Caso de Prueba 6: Arrays de enteros\n");
    printf("arr1: {1, 2, 3}\n");
    printf("arr2: {1, 2, 4}\n");
    printf("n: %zu bytes\n", n);

    int result_ft = ft_memcmp(arr1, arr2, n);
    int result_std = memcmp(arr1, arr2, n);

    printf("Resultado ft_memcmp: %d\n", result_ft);
    printf("Resultado memcmp   : %d\n", result_std);

    if ((result_ft == result_std))
        printf("Caso de Prueba 6: ¡Éxito!\n\n");
    else
        printf("Caso de Prueba 6: ¡Fallo!\n\n");
}

// Caso de prueba 7: Memorias con bytes negativos
void test_case7(void)
{
    char s1[] = { -1, 0, 1 };
    char s2[] = { -1, 0, 1 };
    size_t n = 3;

    printf("Caso de Prueba 7: Memorias con bytes negativos\n");
    printf("s1: { -1, 0, 1 }\n");
    printf("s2: { -1, 0, 1 }\n");
    printf("n: %zu\n", n);

    int result_ft = ft_memcmp(s1, s2, n);
    int result_std = memcmp(s1, s2, n);

    printf("Resultado ft_memcmp: %d\n", result_ft);
    printf("Resultado memcmp   : %d\n", result_std);

    if ((result_ft == result_std))
        printf("Caso de Prueba 7: ¡Éxito!\n\n");
    else
        printf("Caso de Prueba 7: ¡Fallo!\n\n");
}

// Caso de prueba 8: Memorias vacías
void test_case8(void)
{
    const char s1[] = "";
    const char s2[] = "";
    size_t n = 0;

    printf("Caso de Prueba 8: Memorias vacías\n");
    printf("s1: \"%s\"\n", s1);
    printf("s2: \"%s\"\n", s2);
    printf("n: %zu\n", n);

    int result_ft = ft_memcmp(s1, s2, n);
    int result_std = memcmp(s1, s2, n);

    printf("Resultado ft_memcmp: %d\n", result_ft);
    printf("Resultado memcmp   : %d\n", result_std);

    if (result_ft == result_std)
        printf("Caso de Prueba 8: ¡Éxito!\n\n");
    else
        printf("Caso de Prueba 8: ¡Fallo!\n\n");
}

// Caso de prueba 9: Punteros nulos (comportamiento indefinido)
void test_case9(void)
{
    const char *s1 = NULL;
    const char *s2 = NULL;
    size_t n = 5;

    printf("Caso de Prueba 9: Punteros nulos\n");
    printf("s1: NULL\n");
    printf("s2: NULL\n");
    printf("n: %zu\n", n);

    printf("Nota: Este caso puede causar un fallo de segmentación.\n");

    // Evitar fallo verificando punteros nulos
    if (s1 == NULL || s2 == NULL)
    {
        printf("No se puede realizar memcmp con punteros nulos.\n\n");
        return;
    }

    int result_ft = ft_memcmp(s1, s2, n);
    int result_std = memcmp(s1, s2, n);

    printf("Resultado ft_memcmp: %d\n", result_ft);
    printf("Resultado memcmp   : %d\n", result_std);

    if (result_ft == result_std)
        printf("Caso de Prueba 9: ¡Éxito!\n\n");
    else
        printf("Caso de Prueba 9: ¡Fallo!\n\n");
}

// Caso de prueba 10: Comparación parcial
void test_case10(void)
{
    const char s1[] = "abcdef";
    const char s2[] = "abcxyz";
    size_t n = 3;

    printf("Caso de Prueba 10: Comparación parcial\n");
    printf("s1: \"%s\"\n", s1);
    printf("s2: \"%s\"\n", s2);
    printf("n: %zu\n", n);

    int result_ft = ft_memcmp(s1, s2, n);
    int result_std = memcmp(s1, s2, n);

    printf("Resultado ft_memcmp: %d\n", result_ft);
    printf("Resultado memcmp   : %d\n", result_std);

    if (result_ft == result_std)
        printf("Caso de Prueba 10: ¡Éxito!\n\n");
    else
        printf("Caso de Prueba 10: ¡Fallo!\n\n");
}
