/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlibran- <rlibran-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:03:42 by rlibran-          #+#    #+#             */
/*   Updated: 2024/10/10 20:03:42 by rlibran-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// chat used: https://chatgpt.com/share/67081a5d-ed40-800c-b5c2-ca699377385b

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t simple_strlcat(char *dst, const char *src, size_t dstsize)
{
    size_t dst_len;
    size_t src_len;
    size_t i;

    dst_len = 0;
    while (dst_len < dstsize && dst[dst_len] != '\0')
        dst_len++;

    src_len = 0;
    while (src[src_len] != '\0')
        src_len++;

    if (dst_len == dstsize)
        return (dstsize + src_len);

    i = 0;
    while ((dst_len + i + 1) < dstsize && src[i] != '\0')
    {
        dst[dst_len + i] = src[i];
        i++;
    }

    if (dst_len + i < dstsize)
        dst[dst_len + i] = '\0';

    return (dst_len + src_len);
}


size_t ft_strlen(const char *s)
{
    size_t len;

    len = 0;
    while (s[len] != '\0')
        len++;
    return (len);
}

size_t ft_strlcat(char *dst, const char *src, size_t dstsize);

int main(void)
{
    char dst[50];
    char dst_ft[50];
    const char *src_original = " world!";
    const char *src;
    size_t dstsize;
    size_t ret;
    size_t ret_ft;
    int test_passed;
    int total_tests = 9;
    int passed_tests = 0;

    // Caso 1: Concatenación normal
    printf("Caso 1: Concatenación normal\n");
    strcpy(dst, "Hello");
    strcpy(dst_ft, "Hello");
    src = src_original;
    dstsize = sizeof(dst);
    ret = simple_strlcat(dst, src, dstsize);
    ret_ft = ft_strlcat(dst_ft, src, dstsize);
    test_passed = (ret == ret_ft) && (strcmp(dst, dst_ft) == 0);
    printf("Resultado: %s\n", test_passed ? "OK" : "KO");
    if (test_passed) passed_tests++;
    printf("Original: %s (ret: %zu)\nMi función: %s (ret: %zu)\n\n",
           dst, ret, dst_ft, ret_ft);

    // Caso 2: dstsize menor que la longitud de dst
    printf("Caso 2: dstsize menor que la longitud de dst\n");
    strcpy(dst, "Hello");
    strcpy(dst_ft, "Hello");
    src = src_original;
    dstsize = 3;
    ret = simple_strlcat(dst, src, dstsize);
    ret_ft = ft_strlcat(dst_ft, src, dstsize);
    test_passed = (ret == ret_ft) && (strcmp(dst, dst_ft) == 0);
    printf("Resultado: %s\n", test_passed ? "OK" : "KO");
    if (test_passed) passed_tests++;
    printf("Original: %s (ret: %zu)\nMi función: %s (ret: %zu)\n\n",
           dst, ret, dst_ft, ret_ft);

    // Caso 3: dstsize es cero
    printf("Caso 3: dstsize es cero\n");
    strcpy(dst, "Hello");
    strcpy(dst_ft, "Hello");
    src = src_original;
    dstsize = 0;
    ret = simple_strlcat(dst, src, dstsize);
    ret_ft = ft_strlcat(dst_ft, src, dstsize);
    test_passed = (ret == ret_ft) && (strcmp(dst, dst_ft) == 0);
    printf("Resultado: %s\n", test_passed ? "OK" : "KO");
    if (test_passed) passed_tests++;
    printf("Original: %s (ret: %zu)\nMi función: %s (ret: %zu)\n\n",
           dst, ret, dst_ft, ret_ft);

    // Caso 4: dst vacío
    printf("Caso 4: dst vacío\n");
    strcpy(dst, "");
    strcpy(dst_ft, "");
    src = src_original;
    dstsize = sizeof(dst);
    ret = simple_strlcat(dst, src, dstsize);
    ret_ft = ft_strlcat(dst_ft, src, dstsize);
    test_passed = (ret == ret_ft) && (strcmp(dst, dst_ft) == 0);
    printf("Resultado: %s\n", test_passed ? "OK" : "KO");
    if (test_passed) passed_tests++;
    printf("Original: %s (ret: %zu)\nMi función: %s (ret: %zu)\n\n",
           dst, ret, dst_ft, ret_ft);

    // Caso 5: src vacío
    printf("Caso 5: src vacío\n");
    strcpy(dst, "Hello");
    strcpy(dst_ft, "Hello");
    src = "";
    dstsize = sizeof(dst);
    ret = simple_strlcat(dst, src, dstsize);
    ret_ft = ft_strlcat(dst_ft, src, dstsize);
    test_passed = (ret == ret_ft) && (strcmp(dst, dst_ft) == 0);
    printf("Resultado: %s\n", test_passed ? "OK" : "KO");
    if (test_passed) passed_tests++;
    printf("Original: %s (ret: %zu)\nMi función: %s (ret: %zu)\n\n",
           dst, ret, dst_ft, ret_ft);

    // Caso 6: dst y src vacíos
    printf("Caso 6: dst y src vacíos\n");
    strcpy(dst, "");
    strcpy(dst_ft, "");
    src = "";
    dstsize = sizeof(dst);
    ret = simple_strlcat(dst, src, dstsize);
    ret_ft = ft_strlcat(dst_ft, src, dstsize);
    test_passed = (ret == ret_ft) && (strcmp(dst, dst_ft) == 0);
    printf("Resultado: %s\n", test_passed ? "OK" : "KO");
    if (test_passed) passed_tests++;
    printf("Original: '%s' (ret: %zu)\nMi función: '%s' (ret: %zu)\n\n",
           dst, ret, dst_ft, ret_ft);

    // Caso 7: dstsize es exactamente dst_len + src_len + 1
    printf("Caso 7: dstsize es exactamente dst_len + src_len + 1\n");
    strcpy(dst, "Hello");
    strcpy(dst_ft, "Hello");
    src = src_original;
    dstsize = ft_strlen(dst) + ft_strlen(src) + 1;
    ret = simple_strlcat(dst, src, dstsize);
    ret_ft = ft_strlcat(dst_ft, src, dstsize);
    test_passed = (ret == ret_ft) && (strcmp(dst, dst_ft) == 0);
    printf("Resultado: %s\n", test_passed ? "OK" : "KO");
    if (test_passed) passed_tests++;
    printf("Original: %s (ret: %zu)\nMi función: %s (ret: %zu)\n\n",
           dst, ret, dst_ft, ret_ft);

    // Caso 8: dstsize es dst_len + n, donde n < src_len
    printf("Caso 8: dstsize es dst_len + n, donde n < src_len\n");
    strcpy(dst, "Hello");
    strcpy(dst_ft, "Hello");
    src = src_original;
    dstsize = ft_strlen(dst) + 3; // n = 3
    ret = simple_strlcat(dst, src, dstsize);
    ret_ft = ft_strlcat(dst_ft, src, dstsize);
    test_passed = (ret == ret_ft) && (strcmp(dst, dst_ft) == 0);
    printf("Resultado: %s\n", test_passed ? "OK" : "KO");
    if (test_passed) passed_tests++;
    printf("Original: %s (ret: %zu)\nMi función: %s (ret: %zu)\n\n",
           dst, ret, dst_ft, ret_ft);

    // Caso 9: Cadenas con caracteres no imprimibles
    printf("Caso 9: Cadenas con caracteres no imprimibles\n");
    strcpy(dst, "Hello");
    strcpy(dst_ft, "Hello");
    char non_printable_src[] = " \n\tworld!";
    src = non_printable_src;
    dstsize = sizeof(dst);
    ret = simple_strlcat(dst, src, dstsize);
    ret_ft = ft_strlcat(dst_ft, src, dstsize);
    test_passed = (ret == ret_ft) && (strcmp(dst, dst_ft) == 0);
    printf("Resultado: %s\n", test_passed ? "OK" : "KO");
    if (test_passed) passed_tests++;
    printf("Original: %s (ret: %zu)\nMi función: %s (ret: %zu)\n",
           dst, ret, dst_ft, ret_ft);

    // Resumen de pruebas
    printf("\nResumen de pruebas: %d/%d pasadas.\n", passed_tests, total_tests);

    return 0;
}
