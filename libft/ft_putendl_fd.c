#include <libft.h>

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
/*
Prototipo void ft_putendl_fd(char *s, int fd);
Archivos a entregar
-
Parámetros s: La string a enviar.
fd: El file descriptor sobre el que escribir.
Valor devuelto Nada
Funciones autorizadas
write
Descripción Envía la string ’s’ al file descriptor dado,
seguido de un salto de línea.
*/