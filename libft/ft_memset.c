#include <libft.h>

/*memset se usa para rellenar una cadena con valores especificos
recibe el puntero s, 
el valor del caracter a agregar c 
y el tamaño de la cadena n*/
void *ft_memset(void *s, int c, size_t n)
{
    size_t = len;

    len = '0';
    while (len <= n)
    {
        s[len] = c;
        len = len++;
    }
    return  s;
    /*creo la variable len en 0 para que recorra la cadena
    ademas va cambiando el valor de cada eslabon por c*/
}