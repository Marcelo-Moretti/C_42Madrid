/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <mmoretti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:23:39 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/25 22:11:51 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	counter;
	size_t	temp;
	char	*buffer;

	counter = 0;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	temp = ft_strlen(s + start);
	if (temp > len)
		temp = len;
	buffer = (char *)ft_calloc(temp + 1, sizeof(char));
	if (!buffer)
		return (0);
	while (counter < len && s[counter + start])
	{
		buffer[counter] = s[counter + start];
		counter++;
	}
	return (buffer);
}

/*
void	write_string(const char *str)
{
	if (str) {
		write(1, str, strlen(str));
	} else {
		write(1, "(null)", 6);
	}
}

int	main(void)
{
	const char	*original = "Hola, mundo!";
	char		*subcadena;

	subcadena = ft_substr(original, 7, 5);
	write(1, "Subcadena (7, 5): ", 18);
	write_string(subcadena);
	write(1, "\n", 1);
	free(subcadena);
	subcadena = ft_substr(original, 0, 4);
	write(1, "Subcadena (0, 4): ", 18);
	write_string(subcadena);
	write(1, "\n", 1);
	free(subcadena);
	subcadena = ft_substr(original, 7, 20);
	write(1, "Subcadena (7, 20): ", 19);
	write_string(subcadena);
	write(1, "\n", 1);
	free(subcadena);
	subcadena = ft_substr(NULL, 0, 5);
	write(1, "Subcadena (NULL): ", 18);
	write_string(subcadena);
	write(1, "\n", 1);
	free(subcadena);
	subcadena = ft_substr(original, 0, 0);
	write(1, "Subcadena (0, 0): ", 18);
	write_string(subcadena);
	write(1, "\n", 1);
	free(subcadena);
	return (0);
}
*/