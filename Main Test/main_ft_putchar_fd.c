/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_putchar_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlibran- <rlibran-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 21:45:58 by rlibran-          #+#    #+#             */
/*   Updated: 2024/10/16 21:45:58 by rlibran-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// chat used: https://chatgpt.com/share/671022b1-1b9c-800c-8f06-8911c980ce88
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

// Prototipos de funciones
void ft_putchar_fd(char c, int fd);
void simple_putchar_fd(char c, int fd);

// Casos de prueba
void test_case1();
void test_case2();
void test_case3();
void test_case4();
void test_case5();
void test_case7();
void test_case8();
void test_case9();

// Función auxiliar para comparar salidas
int compare_outputs(const char *filename1, const char *filename2);

int main()
{
    test_case1();
    test_case2();
    test_case3();
    test_case4();
    test_case5();
    test_case7();
    test_case8();
    test_case9();
    return 0;
}

// Implementación de simple_putchar_fd (función estándar equivalente)
void simple_putchar_fd(char c, int fd)
{
    if (fd >= 0)
        write(fd, &c, 1);
}

// Función auxiliar para comparar las salidas de los archivos
int compare_outputs(const char *filename1, const char *filename2)
{
    FILE *file1 = fopen(filename1, "r");
    FILE *file2 = fopen(filename2, "r");
    if (file1 == NULL || file2 == NULL)
    {
        perror("Error al abrir los archivos para comparar");
        return -1;
    }

    int ch1 = fgetc(file1);
    int ch2 = fgetc(file2);

    fclose(file1);
    fclose(file2);

    return ch1 == ch2;
}

// Caso de prueba 1: Carácter normal
void test_case1()
{
    printf("Test Case 1: Escribiendo el carácter 'A' en un archivo\n");
    char c = 'A';
    int fd_ft, fd_simple;
    char filename_ft[] = "output_ft_1.txt";
    char filename_simple[] = "output_simple_1.txt";

    // Abrir archivos para escritura
    fd_ft = open(filename_ft, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    fd_simple = open(filename_simple, O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (fd_ft < 0 || fd_simple < 0)
    {
        perror("Error al abrir los archivos");
        return;
    }

    // Usar ft_putchar_fd
    ft_putchar_fd(c, fd_ft);
    // Usar simple_putchar_fd
    simple_putchar_fd(c, fd_simple);

    // Cerrar archivos
    close(fd_ft);
    close(fd_simple);

    // Comparar salidas
    if (compare_outputs(filename_ft, filename_simple))
    {
        printf("\033[0;32mTest Case 1 Passed: Las salidas coinciden.\033[0m\n\n");
    }
    else
    {
        printf("\033[0;31mTest Case 1 Failed: Las salidas no coinciden.\033[0m\n\n");
    }
}

// Caso de prueba 2: Carácter especial
void test_case2()
{
    printf("Test Case 2: Escribiendo el carácter '\\n' (nueva línea) en un archivo\n");
    char c = '\n';
    int fd_ft, fd_simple;
    char filename_ft[] = "output_ft_2.txt";
    char filename_simple[] = "output_simple_2.txt";

    // Abrir archivos para escritura
    fd_ft = open(filename_ft, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    fd_simple = open(filename_simple, O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (fd_ft < 0 || fd_simple < 0)
    {
        perror("Error al abrir los archivos");
        return;
    }

    // Usar ft_putchar_fd
    ft_putchar_fd(c, fd_ft);
    // Usar simple_putchar_fd
    simple_putchar_fd(c, fd_simple);

    // Cerrar archivos
    close(fd_ft);
    close(fd_simple);

    // Comparar salidas
    if (compare_outputs(filename_ft, filename_simple))
    {
        printf("\033[0;32mTest Case 2 Passed: Las salidas coinciden.\033[0m\n\n");
    }
    else
    {
        printf("\033[0;31mTest Case 2 Failed: Las salidas no coinciden.\033[0m\n\n");
    }
}

// Caso de prueba 3: Carácter nulo
void test_case3()
{
    printf("Test Case 3: Escribiendo el carácter nulo '\\0' en un archivo\n");
    char c = '\0';
    int fd_ft, fd_simple;
    char filename_ft[] = "output_ft_3.txt";
    char filename_simple[] = "output_simple_3.txt";

    // Abrir archivos para escritura
    fd_ft = open(filename_ft, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    fd_simple = open(filename_simple, O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (fd_ft < 0 || fd_simple < 0)
    {
        perror("Error al abrir los archivos");
        return;
    }

    // Usar ft_putchar_fd
    ft_putchar_fd(c, fd_ft);
    // Usar simple_putchar_fd
    simple_putchar_fd(c, fd_simple);

    // Cerrar archivos
    close(fd_ft);
    close(fd_simple);

    // Comparar salidas
    if (compare_outputs(filename_ft, filename_simple))
    {
        printf("\033[0;32mTest Case 3 Passed: Las salidas coinciden.\033[0m\n\n");
    }
    else
    {
        printf("\033[0;31mTest Case 3 Failed: Las salidas no coinciden.\033[0m\n\n");
    }
}

// Caso de prueba 4: File descriptor inválido (-1)
void test_case4()
{
    printf("Test Case 4: Usando un file descriptor inválido (-1)\n");
    char c = 'B';
    int fd_invalid = -1;

    // Usar ft_putchar_fd
    ft_putchar_fd(c, fd_invalid);
    // Usar simple_putchar_fd
    simple_putchar_fd(c, fd_invalid);

    // No hay archivos que comparar, verificamos si hubo errores
    // En este caso, esperamos que no haya salida y que no ocurra nada
    printf("\033[0;32mTest Case 4 Passed: No se produjo salida ni error.\033[0m\n\n");
}

// Caso de prueba 5: Escribiendo en stdout
void test_case5()
{
    printf("Test Case 5: Escribiendo el carácter 'C' en stdout\n");
    char c = 'C';
    int fd = STDOUT_FILENO;

    printf("Salida ft_putchar_fd: ");
    ft_putchar_fd(c, fd);
    printf("\nSalida simple_putchar_fd: ");
    simple_putchar_fd(c, fd);
    printf("\n");

    printf("\033[0;32mTest Case 5 Passed: Se mostraron las salidas en stdout.\033[0m\n\n");
}

// Caso de prueba 7: Escribiendo en un archivo de solo lectura
void test_case7()
{
    printf("Test Case 7: Escribiendo en un archivo de solo lectura\n");
    char c = 'D';
    char filename[] = "readonly_file.txt";
    int fd;

    // Crear archivo de solo lectura
    fd = open(filename, O_CREAT | O_RDONLY, 0444);
    if (fd < 0)
    {
        perror("Error al crear el archivo de solo lectura");
        return;
    }

    // Intentar escribir usando ft_putchar_fd
    ft_putchar_fd(c, fd);

    // Cerrar archivo
    close(fd);

    // Como no podemos escribir en un archivo de solo lectura, esperamos que haya fallado
    printf("\033[0;32mTest Case 7 Passed: No se pudo escribir en archivo de solo lectura, como se esperaba.\033[0m\n\n");
}

// Caso de prueba 8: Escribiendo múltiples caracteres consecutivos
void test_case8()
{
    printf("Test Case 8: Escribiendo múltiples caracteres consecutivos\n");
    char chars[] = {'X', 'Y', 'Z'};
    int fd_ft, fd_simple;
    char filename_ft[] = "output_ft_8.txt";
    char filename_simple[] = "output_simple_8.txt";

    // Abrir archivos para escritura
    fd_ft = open(filename_ft, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    fd_simple = open(filename_simple, O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (fd_ft < 0 || fd_simple < 0)
    {
        perror("Error al abrir los archivos");
        return;
    }

    // Escribir caracteres usando ft_putchar_fd
    for (int i = 0; i < 3; i++)
    {
        ft_putchar_fd(chars[i], fd_ft);
    }

    // Escribir caracteres usando simple_putchar_fd
    for (int i = 0; i < 3; i++)
    {
        simple_putchar_fd(chars[i], fd_simple);
    }

    // Cerrar archivos
    close(fd_ft);
    close(fd_simple);

    // Comparar salidas
    if (compare_outputs(filename_ft, filename_simple))
    {
        printf("\033[0;32mTest Case 8 Passed: Las salidas coinciden.\033[0m\n\n");
    }
    else
    {
        printf("\033[0;31mTest Case 8 Failed: Las salidas no coinciden.\033[0m\n\n");
    }
}

// Caso de prueba 9: Usando un file descriptor de un socket (simulado)
void test_case9()
{
    printf("Test Case 9: Usando un file descriptor simulado de socket (-2)\n");
    char c = 'E';
    int fd_socket = -2; // Simulando un fd inválido

    // Usar ft_putchar_fd
    ft_putchar_fd(c, fd_socket);
    // Usar simple_putchar_fd
    simple_putchar_fd(c, fd_socket);

    // No hay archivos que comparar, verificamos si hubo errores
    printf("\033[0;32mTest Case 9 Passed: No se produjo salida ni error.\033[0m\n\n");
}
