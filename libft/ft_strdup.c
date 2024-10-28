/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <mmoretti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:22:56 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/28 19:02:31 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	counter;
	size_t	length;
	char	*string;

	counter = 0;
	length = ft_strlen(s);
	string = (char *)malloc(sizeof(*string) * (length + 1));
	if (!string)
		return (NULL);
	while (counter < length)
	{
		string[counter] = s[counter];
		counter++;
	}
	string[counter] = '\0';
	return (string);
}

/*
void	write_string(const char *str) {
	if (str) {
		write(1, str, strlen(str));
	} else {
		write(1, "(null)\n", 7);
	}
}

int	main(void) {
	const char *original1 = "Hola, mundo!";
	const char *original2 = NULL;
	char *copia1;
	char *copia2;

	copia1 = ft_strdup(original1);
	write(1, "Original: ", 10);
	write_string(original1);
	write(1, "\nCopia: ", 8);
	write_string(copia1);
	write(1, "\n", 1);

	copia2 = ft_strdup(original2);
	write(1, "Original: (null)\nCopia: ", 25);
	write_string(copia2);
	write(1, "\n", 1);

	free(copia1);
	free(copia2);

	return (0);
}
*/