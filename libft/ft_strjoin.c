/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:24:04 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/15 16:41:09 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_counter;
	int		s2_counter;
	char	*string;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_counter = 0;
	s2_counter = 0;
	string = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (string == NULL)
		return (NULL);
	while (s1[s1_counter] != '\0')
	{
		string[s1_counter] = s1[s1_counter];
		s1_counter++;
	}
	while (s2[s2_counter] != '\0')
	{
		string[s1_counter + s2_counter] = s2[s2_counter];
		s2_counter++;
	}
	string[s1_counter + s2_counter] = '\0';
	return (string);
}
/*int main() {
    char *s1 = "Hola, ";
    char *s2 = "mundo!\n";
    char *result = ft_strjoin(s1, s2);
    
    if (result != NULL) {
        write(1, result, strlen(result));
        free(result);
    } else {
        char *error_msg = "Error al unir las cadenas.\n";
        write(2, error_msg, strlen(error_msg));
    }

    return 0;
}*/