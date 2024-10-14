#include <libft.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}
/*
Prototipo void ft_striteri(char *s, void (*f)(unsigned int,
char*));
Archivos a entregar
-
Parámetros s: La string que iterar.
f: La función a aplicar sobre cada carácter.
Valor devuelto Nada
Funciones autorizadas
Ninguna
Descripción A cada carácter de la string ’s’, aplica la función
’f’ dando como parámetros el índice de cada
carácter dentro de ’s’ y la dirección del propio
carácter, que podrá modificarse si es necesario.
*/