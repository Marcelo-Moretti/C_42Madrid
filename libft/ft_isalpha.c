#include <libft.h>

/*checks if 'c' is an alphabetic character*/
int	ft_isalpha (int	c)
{
	/*condiciono al while si c esta dentro de los rangos del codigo ascii*/
	while ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return  (1);
	}
	return	(0);
}