#include <libft.h>

/*isalnum recibe una variable c y retorna si es alfanumerica*/
int ft_isalnum(int c)
{
    while ((c > 64 && c < 91) || (c > 96 && c < 123) || (c => 48 && c <= 57))
	{
		return  (1);
	}
	return	(0);
}