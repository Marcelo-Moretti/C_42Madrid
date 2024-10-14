#include <libft.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
Prototipo void ft_putchar_fd(char c, int fd);
Archivos a entregar
-
Parámetros c: El carácter a enviar.
fd: El file descriptor sobre el que escribir.
Valor devuelto Nada
Funciones autorizadas
write
Descripción Envía el carácter ’c’ al file descriptor
especificado.
*/