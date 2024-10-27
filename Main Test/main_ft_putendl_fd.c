/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_putendl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlibran- <rlibran-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 00:06:37 by rlibran-          #+#    #+#             */
/*   Updated: 2024/10/17 00:06:37 by rlibran-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define RESET   "\033[0m"
#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"

void	ft_putendl_fd(char *s, int fd);
void	simple_ft_putendl_fd(char *s, int fd);
void	print_test_result(int test_number, int result);
int		compare_files(const char *file1, const char *file2);
void	test_case1();
void	test_case2();
void	test_case3();
void	test_case4();
void	test_case5();
void	test_case6();
void	test_case7();

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s && fd >= 0)
		write(fd, s, ft_strlen(s));
}

void	simple_ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

void	print_test_result(int test_number, int result)
{
	if (result)
		printf(GREEN "Test %d passed\n" RESET, test_number);
	else
		printf(RED "Test %d failed\n" RESET, test_number);
}

int	compare_files(const char *file1, const char *file2)
{
	FILE *fp1 = fopen(file1, "rb");
	FILE *fp2 = fopen(file2, "rb");
	int ch1, ch2;
	int result = 1;

	if (fp1 == NULL || fp2 == NULL)
	{
		perror("Error opening files for comparison");
		result = 0;
	}
	else
	{
		do
		{
			ch1 = fgetc(fp1);
			ch2 = fgetc(fp2);
			if (ch1 != ch2)
			{
				result = 0;
				break;
			}
		} while (ch1 != EOF && ch2 != EOF);

		if (ch1 != ch2)
			result = 0;
	}

	if (fp1)
		fclose(fp1);
	if (fp2)
		fclose(fp2);

	return result;
}

/* Caso de prueba 1: Cadena normal */
void	test_case1()
{
	int fd1, fd2;
	char *filename1 = "test_ft_1.txt";
	char *filename2 = "test_simple_1.txt";
	char *test_string = "Hola, mundo!";
	int result;

	/* Abrir archivos */
	fd1 = open(filename1, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	fd2 = open(filename2, O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if (fd1 < 0 || fd2 < 0)
	{
		perror("Error opening files");
		exit(EXIT_FAILURE);
	}

	/* Llamar a las funciones */
	ft_putendl_fd(test_string, fd1);
	simple_ft_putendl_fd(test_string, fd2);

	/* Cerrar archivos */
	close(fd1);
	close(fd2);

	/* Comparar archivos */
	result = compare_files(filename1, filename2);

	/* Imprimir resultado */
	printf("Test Case 1: Cadena: \"%s\"\n", test_string);
	print_test_result(1, result);

	/* Eliminar archivos temporales */
	unlink(filename1);
	unlink(filename2);
}

/* Caso de prueba 2: Cadena vacía */
void	test_case2()
{
	int fd1, fd2;
	char *filename1 = "test_ft_2.txt";
	char *filename2 = "test_simple_2.txt";
	char *test_string = "";
	int result;

	fd1 = open(filename1, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	fd2 = open(filename2, O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if (fd1 < 0 || fd2 < 0)
	{
		perror("Error opening files");
		exit(EXIT_FAILURE);
	}

	ft_putendl_fd(test_string, fd1);
	simple_ft_putendl_fd(test_string, fd2);

	close(fd1);
	close(fd2);

	result = compare_files(filename1, filename2);

	printf("Test Case 2: Cadena vacía\n");
	print_test_result(2, result);

	unlink(filename1);
	unlink(filename2);
}

/* Caso de prueba 3: Cadena con caracteres especiales */
void	test_case3()
{
	int fd1, fd2;
	char *filename1 = "test_ft_3.txt";
	char *filename2 = "test_simple_3.txt";
	char *test_string = "Línea 1\nLínea 2\tCon tabulación\rRetorno de carro";
	int result;

	fd1 = open(filename1, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	fd2 = open(filename2, O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if (fd1 < 0 || fd2 < 0)
	{
		perror("Error opening files");
		exit(EXIT_FAILURE);
	}

	ft_putendl_fd(test_string, fd1);
	simple_ft_putendl_fd(test_string, fd2);

	close(fd1);
	close(fd2);

	result = compare_files(filename1, filename2);

	printf("Test Case 3: Cadena con caracteres especiales: \"%s\"\n", test_string);
	print_test_result(3, result);

	unlink(filename1);
	unlink(filename2);
}

/* Caso de prueba 4: Cadena nula */
void	test_case4()
{
	int fd1, fd2;
	char *filename1 = "test_ft_4.txt";
	char *filename2 = "test_simple_4.txt";
	char *test_string = NULL;
	int result;

	fd1 = open(filename1, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	fd2 = open(filename2, O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if (fd1 < 0 || fd2 < 0)
	{
		perror("Error opening files");
		exit(EXIT_FAILURE);
	}

	ft_putendl_fd(test_string, fd1);
	simple_ft_putendl_fd(test_string, fd2);

	close(fd1);
	close(fd2);

	result = compare_files(filename1, filename2);

	printf("Test Case 4: Cadena nula\n");
	print_test_result(4, result);

	unlink(filename1);
	unlink(filename2);
}

/* Caso de prueba 5: Cadena larga */
void	test_case5()
{
	int fd1, fd2;
	char *filename1 = "test_ft_5.txt";
	char *filename2 = "test_simple_5.txt";
	int result;
	char test_string[1001];

	/* Generar una cadena de 1000 caracteres 'A' */
	memset(test_string, 'A', 1000);
	test_string[1000] = '\0';

	fd1 = open(filename1, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	fd2 = open(filename2, O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if (fd1 < 0 || fd2 < 0)
	{
		perror("Error opening files");
		exit(EXIT_FAILURE);
	}

	ft_putendl_fd(test_string, fd1);
	simple_ft_putendl_fd(test_string, fd2);

	close(fd1);
	close(fd2);

	result = compare_files(filename1, filename2);

	printf("Test Case 5: Cadena larga de 1000 caracteres\n");
	print_test_result(5, result);

	unlink(filename1);
	unlink(filename2);
}

/* Caso de prueba 6: Descriptor de archivo inválido */
void	test_case6()
{
	char *test_string = "Probando fd inválido";
	int result = 1;

	/* Llamar a las funciones con fd inválido */
	ft_putendl_fd(test_string, -1);
	simple_ft_putendl_fd(test_string, -1);

	/* No hay archivos que comparar, asumimos que si no hay errores en tiempo de ejecución, la prueba pasa */
	printf("Test Case 6: Descriptor de archivo inválido\n");
	print_test_result(6, result);
}

/* Caso de prueba 7: Cadena con caracteres no imprimibles */
void	test_case7()
{
	int fd1, fd2;
	char *filename1 = "test_ft_7.txt";
	char *filename2 = "test_simple_7.txt";
	char test_string[] = {0x01, 0x02, 0x03, 0x04, '\0'};
	int result;

	fd1 = open(filename1, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	fd2 = open(filename2, O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if (fd1 < 0 || fd2 < 0)
	{
		perror("Error opening files");
		exit(EXIT_FAILURE);
	}

	ft_putendl_fd(test_string, fd1);
	simple_ft_putendl_fd(test_string, fd2);

	close(fd1);
	close(fd2);

	result = compare_files(filename1, filename2);

	printf("Test Case 7: Cadena con caracteres no imprimibles\n");
	print_test_result(7, result);

	unlink(filename1);
	unlink(filename2);
}

/* Función main completa */
int	main()
{
	test_case1();
	test_case2();
	test_case3();
	test_case4();
	test_case5();
	test_case6();
	test_case7();

	return 0;
}
