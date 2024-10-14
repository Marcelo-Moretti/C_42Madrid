#include <libft.h>

static unsigned int	ft_number_size(int number)
{
	unsigned int	length;
	
	length = 0;
	if (number == 0)
		return (1);
	if (number < 0)
		length += 1;
	while (number != 0)
	{
		number /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char		*string;
	unsigned int	number;
	unsigned int	length;

	length = ft_number_size(n);
	string = (char *)malloc(sizeof(char) * (length + 1));
	if (string == NULL)
		return (NULL);
	if (number < 0)
	{
		string[0] = '-';
		number = -n;
	}
	else
		number = n;
	if (number == 0)
		string[0] = '0';
	string[length] = '\0';
	while (number != 0)
	{
		string[length - 1] = (number % 10) + '0';
		number = number / 10;
		length--;
	}
	return (string);
}
/*
Prototipo char *ft_itoa(int n);
Archivos a entregar
-
Parámetros n: el entero a convertir.
Valor devuelto La string que represente el número.
NULL si falla la reserva de memoria.
Funciones autorizadas
malloc
Descripción Utilizando malloc(3), genera una string que
represente el valor entero recibido como argumento.
Los números negativos tienen que gestionarse.
*/