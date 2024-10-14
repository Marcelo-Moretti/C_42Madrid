#include <libft.h>


/*memcpy copia n bytes desde el area de memoria src al area de memoria dest. 
El area de memoria no debe sobreescribirse.  
Use mem‐move if the memory areas do overlap.
retorna el puntero *dest*/
void *ft_memcpy(void dest, const void src, size_t n)
{
	int copy;

	copy = '0';
	while (copy <= n)
	{
		dest[copy] = src[copy];
		copy++;
	}
	return *copy;
	/*creo una variable como referencia y la igualo a 0
	mientras la variable de referencia sea menor de n, 
	recorro el puntero hasta el valor de n
	copiando del src para dest*/
}