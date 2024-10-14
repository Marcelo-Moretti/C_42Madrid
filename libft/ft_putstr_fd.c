#include <libft.h>

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
/*
Prototipo void ft_putstr_fd(char *s, int fd);
Archivos a entregar
-
Parámetros s: La string a enviar.
fd: El file descriptor sobre el que escribir.
Valor devuelto Nada
Funciones autorizadas
write
Descripción Envía la string ’s’ al file descriptor
especificado.
*/