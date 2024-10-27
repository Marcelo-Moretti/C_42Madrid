/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlibran- <rlibran-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:20:52 by rlibran-          #+#    #+#             */
/*   Updated: 2024/10/11 17:20:52 by rlibran-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// chat used: https://chatgpt.com/share/67094836-26c4-800c-b106-898df08735bb
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str); // Declaración de tu función ft_atoi

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	main(void)
{
	char	*tests[] = {
		"42",
		"123456",
		"0",
		"-42",
		"-123456",
		"   42",
		"\t\n\r\v\f42",
		"+",
		"-",
		"++42",
		"--42",
		"+-42",
		"-+42",
		"42abc",
		"abc42",
		"42 24",
		"2147483647",
		"-2147483648",
		"",
		// (char *)NULL, // Descomenta esta línea para probar con NULL (con precaución)
		"- 42",
		" +42",
		"\n42",
		"\v\f42",
		"99999999999999999999",
		"-99999999999999999999",
		NULL // Fin del array de pruebas
	};
	int	i;
	int	ft_result;
	int	orig_result;

	i = 0;
	while (tests[i])
	{
		ft_result = ft_atoi(tests[i]);
		orig_result = atoi(tests[i]);
		if (ft_result == orig_result)
			printf("Prueba %2d: OK     | Entrada: \"%s\"\n", i + 1, tests[i]);
		else
		{
			printf("Prueba %2d: ERROR  | Entrada: \"%s\"\n", i + 1, tests[i]);
			printf("  ft_atoi: %d\n", ft_result);
			printf("  atoi   : %d\n", orig_result);
		}
		i++;
	}
	return (0);
}
