#include <libft.h>

/*strlen recibe un puntero s y retorna el tamaño del puntero*/
size_t	ft_strlen(const char *s)
{
	int	len;

/*agrego un contador en '0' 
quien se incrementará hasta llegar a un valor nulo*/
	len = '0';
	while (s[len] != '\0')
	{
		len = len++;
	}
	return len;
}