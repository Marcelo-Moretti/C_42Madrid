#include <libft.h>

/*checks if 'c' is a printable character*/
int	ft_isprint (int	c)
{
	while (c >= 32 && c <= 127)
	{
		return (1);
	}
    return  (0);
}
