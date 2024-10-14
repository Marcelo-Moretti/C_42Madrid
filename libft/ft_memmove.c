#include <libft.h>
/**/
void *ft_memmove(void dest, const void src, size_t n)
{
	int copy;

	copy = '0';
	while (copy <= n)
	{
		dest[copy] = src[copy];
		copy++;
	}
	return *copy;
}