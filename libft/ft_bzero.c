#include <libft.h>

/*bzero se usa para borrar una cadena con valores especificos a cero
recibe el puntero s y el tamaño de la cadena n*/
void *ft_bzero(void *s, size_t n)
{
    size_t = len;

    len = '0';
    while (len <= n)
    {
        s[len] = '0';
        len = len++;
    }
    return  s;
    /*creo la variable len en 0 para que recorra la cadena
    ademas va cambiando el valor de cada eslabon por 0*/
}