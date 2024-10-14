#include <libft.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (str == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}
/*
char *ft_substr(char const *s, unsigned int start,
size_t len);
Parámetros s: La string desde la que crear la substring.
start: El índice del caracter en ’s’ desde el que
empezar la substring.
len: La longitud máxima de la substring.
Valor devuelto La substring resultante.
NULL si falla la reserva de memoria.
Funciones autorizadas
malloc
Descripción Reserva (con malloc(3)) y devuelve una substring de
la string ’s’.
La substring empieza desde el índice ’start’ y
tiene una longitud máxima ’len’.
*/