#include <libft.h>

/*checks if 'c' is a number*/
int	ft_isdigit (int	c)
{
	while (c >= 48 && c <= 57)
	{
		return (1);
	}
	return	(0);
}
