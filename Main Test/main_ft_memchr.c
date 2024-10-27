/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_memchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlibran- <rlibran-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:50:05 by rlibran-          #+#    #+#             */
/*   Updated: 2024/10/12 16:50:05 by rlibran-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// chat used: https://chatgpt.com/share/670a9e05-7364-800c-9ec6-b1761df9d3a5
// main.c
#include <stdio.h>
#include <string.h>

// Prototipo de tu función ft_memchr
void    *ft_memchr(const void *s, int c, size_t n);

// Declaraciones de las pruebas
void test_case1();
void test_case2();
void test_case3();
void test_case4();
void test_case5();
void test_case6();
void test_case7();
void test_case8();
void test_case9();
void test_case10();
void test_case11();
void test_case12();

int main(void)
{
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
    test_case11();
    test_case12();
    return 0;
}

void test_case1()
{
    char s[] = "Hola Mundo";
    int c = 'M';
    size_t n = 10;
    void *result_ft = ft_memchr(s, c, n);
    void *result_orig = memchr(s, c, n);

    printf("Caso 1:\n");
    printf("s: \"%s\", c: '%c', n: %zu\n", s, c, n);
    printf("ft_memchr: %s\n", (char *)result_ft);
    printf("memchr:    %s\n", (char *)result_orig);
    printf("Resultado: %s\n\n", result_ft == result_orig ? "OK" : "KO");
}

void test_case2()
{
    char s[] = "Hola";
    int c = 'H';
    size_t n = 4;
    void *result_ft = ft_memchr(s, c, n);
    void *result_orig = memchr(s, c, n);

    printf("Caso 2:\n");
    printf("s: \"%s\", c: '%c', n: %zu\n", s, c, n);
    printf("ft_memchr: %s\n", (char *)result_ft);
    printf("memchr:    %s\n", (char *)result_orig);
    printf("Resultado: %s\n\n", result_ft == result_orig ? "OK" : "KO");
}

void test_case3()
{
    char s[] = "Hola";
    int c = 'a';
    size_t n = 4;
    void *result_ft = ft_memchr(s, c, n);
    void *result_orig = memchr(s, c, n);

    printf("Caso 3:\n");
    printf("s: \"%s\", c: '%c', n: %zu\n", s, c, n);
    printf("ft_memchr: %s\n", (char *)result_ft);
    printf("memchr:    %s\n", (char *)result_orig);
    printf("Resultado: %s\n\n", result_ft == result_orig ? "OK" : "KO");
}

void test_case4()
{
    char s[] = "Hola";
    int c = 'z';
    size_t n = 4;
    void *result_ft = ft_memchr(s, c, n);
    void *result_orig = memchr(s, c, n);

    printf("Caso 4:\n");
    printf("s: \"%s\", c: '%c', n: %zu\n", s, c, n);
    printf("ft_memchr: %p\n", result_ft);
    printf("memchr:    %p\n", result_orig);
    printf("Resultado: %s\n\n", result_ft == result_orig ? "OK" : "KO");
}

void test_case5()
{
    char s[] = "Hola";
    int c = 'H';
    size_t n = 0;
    void *result_ft = ft_memchr(s, c, n);
    void *result_orig = memchr(s, c, n);

    printf("Caso 5:\n");
    printf("s: \"%s\", c: '%c', n: %zu\n", s, c, n);
    printf("ft_memchr: %p\n", result_ft);
    printf("memchr:    %p\n", result_orig);
    printf("Resultado: %s\n\n", result_ft == result_orig ? "OK" : "KO");
}

void test_case6()
{
    char s[] = "Hola\0Mundo";
    int c = '\0';
    size_t n = 10;
    void *result_ft = ft_memchr(s, c, n);
    void *result_orig = memchr(s, c, n);

    printf("Caso 6:\n");
    printf("s: \"Hola\\0Mundo\", c: '\\0', n: %zu\n", n);
    printf("ft_memchr: %p\n", result_ft);
    printf("memchr:    %p\n", result_orig);
    printf("Resultado: %s\n\n", result_ft == result_orig ? "OK" : "KO");
}

void test_case7()
{
    unsigned char s[] = {0x00, 0x01, 0xFF, 0x7F};
    int c = 0xFF;
    size_t n = 4;
    void *result_ft = ft_memchr(s, c, n);
    void *result_orig = memchr(s, c, n);

    printf("Caso 7:\n");
    printf("s: {0x00, 0x01, 0xFF, 0x7F}, c: 0x%X, n: %zu\n", c, n);
    printf("ft_memchr: %p\n", result_ft);
    printf("memchr:    %p\n", result_orig);
    printf("Resultado: %s\n\n", result_ft == result_orig ? "OK" : "KO");
}

void test_case8()
{
    char s[] = "Hola";
    int c = 300; // 300 % 256 = 44 (',')
    size_t n = 4;
    void *result_ft = ft_memchr(s, c, n);
    void *result_orig = memchr(s, c, n);

    printf("Caso 8:\n");
    printf("s: \"%s\", c: %d, n: %zu\n", s, c, n);
    printf("ft_memchr: %p\n", result_ft);
    printf("memchr:    %p\n", result_orig);
    printf("Resultado: %s\n", result_ft == result_orig ? "OK" : "KO");
    printf("Nota: (unsigned char)300 = %d\n\n", (unsigned char)c);
}

void test_case9()
{
    char s[] = "Hola";
    int c = 'a';
    size_t n = 10;
    void *result_ft = ft_memchr(s, c, n);
    void *result_orig = memchr(s, c, n);

    printf("Caso 9:\n");
    printf("s: \"%s\", c: '%c', n: %zu\n", s, c, n);
    printf("ft_memchr: %s\n", (char *)result_ft);
    printf("memchr:    %s\n", (char *)result_orig);
    printf("Resultado: %s\n\n", result_ft == result_orig ? "OK" : "KO");
}

void test_case10()
{
    int s[] = {1, 2, 3, 4};
    int c = ((unsigned char *)&s[1])[0]; // Primer byte del entero 2
    size_t n = sizeof(int) * 4;
    void *result_ft = ft_memchr(s, c, n);
    void *result_orig = memchr(s, c, n);

    printf("Caso 10:\n");
    printf("s: {1, 2, 3, 4}, c: %d, n: %zu\n", c, n);
    printf("ft_memchr: %p\n", result_ft);
    printf("memchr:    %p\n", result_orig);
    printf("Resultado: %s\n\n", result_ft == result_orig ? "OK" : "KO");
}

void test_case11()
{
    char s[] = "aaaaaa";
    int c = 'a';
    size_t n = 6;
    void *result_ft = ft_memchr(s, c, n);
    void *result_orig = memchr(s, c, n);

    printf("Caso 11:\n");
    printf("s: \"%s\", c: '%c', n: %zu\n", s, c, n);
    printf("ft_memchr: %s\n", (char *)result_ft);
    printf("memchr:    %s\n", (char *)result_orig);
    printf("Resultado: %s\n\n", result_ft == result_orig ? "OK" : "KO");
}

void test_case12()
{
    signed char s[] = {-1, -2, -3, -4};
    int c = -3;
    size_t n = 4;
    void *result_ft = ft_memchr(s, c, n);
    void *result_orig = memchr(s, c, n);

    printf("Caso 12:\n");
    printf("s: {-1, -2, -3, -4}, c: %d, n: %zu\n", c, n);
    printf("ft_memchr: %p\n", result_ft);
    printf("memchr:    %p\n", result_orig);
    printf("Resultado: %s\n", result_ft == result_orig ? "OK" : "KO");
    printf("Nota: (unsigned char)c = %u\n\n", (unsigned char)c);
}
