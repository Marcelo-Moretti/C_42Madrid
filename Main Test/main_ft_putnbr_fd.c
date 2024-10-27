/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_putnbr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlibran- <rlibran-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 02:52:12 by rlibran-          #+#    #+#             */
/*   Updated: 2024/10/17 02:52:12 by rlibran-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putnbr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tu_nombre <tu_correo@student.42madrid.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: YYYY/MM/DD HH:MM:SS by tu_nombre         #+#    #+#             */
/*   Updated: YYYY/MM/DD HH:MM:SS by tu_nombre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// chat used: https://chatgpt.com/share/671066eb-6f7c-800c-a9b0-276acd262025
#include <stdio.h>      // Para printf, sprintf
#include <string.h>     // Para strcmp
#include <unistd.h>     // Para write, close, dup2
#include <fcntl.h>      // Para open
#include <stdlib.h>     // Para malloc, free, exit
#include <sys/types.h>
#include <sys/stat.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

/* Prototipo de tu función ft_putnbr_fd */
void    ft_putnbr_fd(int n, int fd);

/* Implementación de ft_putchar_fd */
void    ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

/* Implementación de simple_putnbr_fd */
void    simple_putnbr_fd(int n, int fd)
{
    char    c;

    if (n == -2147483648)
    {
        write(fd, "-2147483648", 11);
        return ;
    }
    if (n < 0)
    {
        write(fd, "-", 1);
        n = -n;
    }
    if (n >= 10)
        simple_putnbr_fd(n / 10, fd);
    c = n % 10 + '0';
    write(fd, &c, 1);
}

/* Función para capturar la salida de una función que escribe en fd */
char    *capture_output(void (*func)(int, int), int n)
{
    int     pipefd[2];
    pid_t   pid;
    char    buffer[100];
    ssize_t bytes_read;
    char    *output;

    if (pipe(pipefd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0)
    {
        /* Proceso hijo: redirigir stdout a pipe y ejecutar la función */
        close(pipefd[0]);              // Cerrar lectura
        dup2(pipefd[1], STDOUT_FILENO); // Redirigir stdout
        func(n, STDOUT_FILENO);        // Ejecutar la función
        close(pipefd[1]);              // Cerrar escritura
        exit(EXIT_SUCCESS);
    }
    else
    {
        /* Proceso padre: leer la salida de la función */
        close(pipefd[1]);              // Cerrar escritura
        bytes_read = read(pipefd[0], buffer, sizeof(buffer) - 1);
        if (bytes_read == -1)
        {
            perror("read");
            exit(EXIT_FAILURE);
        }
        buffer[bytes_read] = '\0';     // Asegurar terminación de cadena
        output = strdup(buffer);       // Copiar salida
        close(pipefd[0]);              // Esperar al hijo
        return (output);
    }
}

/* Caso de prueba 1: Número positivo */
void    test_case1(void)
{
    int     n = 12345;
    char    *output_ft;
    char    *output_simple;

    printf("Test Case 1: Número positivo\n");
    printf("Parámetro: %d\n", n);
    output_ft = capture_output(ft_putnbr_fd, n);
    output_simple = capture_output(simple_putnbr_fd, n);
    if (strcmp(output_ft, output_simple) == 0)
        printf(GREEN "Resultado: PASSED\n" RESET);
    else
    {
        printf(RED "Resultado: FAILED\n" RESET);
        printf("Esperado: %s\n", output_simple);
        printf("Obtenido: %s\n", output_ft);
    }
    free(output_ft);
    free(output_simple);
    printf("\n");
}

/* Caso de prueba 2: Número negativo */
void    test_case2(void)
{
    int     n = -54321;
    char    *output_ft;
    char    *output_simple;

    printf("Test Case 2: Número negativo\n");
    printf("Parámetro: %d\n", n);
    output_ft = capture_output(ft_putnbr_fd, n);
    output_simple = capture_output(simple_putnbr_fd, n);
    if (strcmp(output_ft, output_simple) == 0)
        printf(GREEN "Resultado: PASSED\n" RESET);
    else
    {
        printf(RED "Resultado: FAILED\n" RESET);
        printf("Esperado: %s\n", output_simple);
        printf("Obtenido: %s\n", output_ft);
    }
    free(output_ft);
    free(output_simple);
    printf("\n");
}

/* Caso de prueba 3: Cero */
void    test_case3(void)
{
    int     n = 0;
    char    *output_ft;
    char    *output_simple;

    printf("Test Case 3: Cero\n");
    printf("Parámetro: %d\n", n);
    output_ft = capture_output(ft_putnbr_fd, n);
    output_simple = capture_output(simple_putnbr_fd, n);
    if (strcmp(output_ft, output_simple) == 0)
        printf(GREEN "Resultado: PASSED\n" RESET);
    else
    {
        printf(RED "Resultado: FAILED\n" RESET);
        printf("Esperado: %s\n", output_simple);
        printf("Obtenido: %s\n", output_ft);
    }
    free(output_ft);
    free(output_simple);
    printf("\n");
}

/* Caso de prueba 4: Número mínimo entero */
void    test_case4(void)
{
    int     n = -2147483648;
    char    *output_ft;
    char    *output_simple;

    printf("Test Case 4: Mínimo entero\n");
    printf("Parámetro: %d\n", n);
    output_ft = capture_output(ft_putnbr_fd, n);
    output_simple = capture_output(simple_putnbr_fd, n);
    if (strcmp(output_ft, output_simple) == 0)
        printf(GREEN "Resultado: PASSED\n" RESET);
    else
    {
        printf(RED "Resultado: FAILED\n" RESET);
        printf("Esperado: %s\n", output_simple);
        printf("Obtenido: %s\n", output_ft);
    }
    free(output_ft);
    free(output_simple);
    printf("\n");
}

/* Caso de prueba 5: Número máximo entero */
void    test_case5(void)
{
    int     n = 2147483647;
    char    *output_ft;
    char    *output_simple;

    printf("Test Case 5: Máximo entero\n");
    printf("Parámetro: %d\n", n);
    output_ft = capture_output(ft_putnbr_fd, n);
    output_simple = capture_output(simple_putnbr_fd, n);
    if (strcmp(output_ft, output_simple) == 0)
        printf(GREEN "Resultado: PASSED\n" RESET);
    else
    {
        printf(RED "Resultado: FAILED\n" RESET);
        printf("Esperado: %s\n", output_simple);
        printf("Obtenido: %s\n", output_ft);
    }
    free(output_ft);
    free(output_simple);
    printf("\n");
}

/* Función main */
int     main(void)
{
    printf("=== Iniciando pruebas para ft_putnbr_fd ===\n\n");
    test_case1();
    test_case2();
    test_case3();
    test_case4();
    test_case5();
    printf("=== Pruebas finalizadas ===\n");
    return (0);
}
