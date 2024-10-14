#include <libft.h>

/*isascii recibe una variable c y retorna si está dentro de la tabla ascii*/
int ft_isascii(int  c)
{
    while (c >= 0 && c <= 127)
    {
        return  (1);
    }
    return  (0);
}