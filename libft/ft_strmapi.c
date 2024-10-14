#include <libft.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
Prototipo char *ft_strmapi(char const *s, char (*f)(unsigned
int, char));
Archivos a entregar
-
Parámetros s: La string que iterar.
f: La función a aplicar sobre cada carácter.
Valor devuelto La string creada tras el correcto uso de ’f’ sobre
cada carácter.
NULL si falla la reserva de memoria.
Funciones autorizadas
malloc
Descripción Aplica la función ’f’ a cada carácter de la cadena
’s’, pasando su índice como primer argumento y el
propio carácter como segundo argumento. Se crea una
nueva cadena (utilizando malloc(3)) para recoger
los resultados de las sucesivas aplicaciones de
’f’.
*/