#ifndef LIBFT_H
/*Inicio una include guard para evitar que el archivo de cabecera sea 
incluido varias veces en un mismo archivo de implementación*/
#define LIBFT_H
/*Defino la cabecera y si se incluye nuevamente en otro archivo, 
la include guard evitará que el contenido se procese más de una vez*/
#include <unistd.h>
/*Para constantes y tipos de datos estándar del SO y funciones del sistema (write, read, close)*/
#include <ctype.h>
/*Para la clasificación y conversión de caracteres (isalnum, isalpha, isdigit)*/
#include <string.h>
/*Para funciones para manipulación de cadenas (strlen, strcpy, strcmp)*/
#include <stdlib.h>
/*Para la gestión de memoria dinámica y conversiones numérica (malloc, free, atoi, etc)*/

int		ft_atoi(const char *str);
int		ft_isalnum(int i);
int		ft_isalpha(int i);
int		ft_isascii(int i);
int		ft_isdigit(int i);
int		ft_isprint(int i);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strlen(const char *str);
int		ft_strncmp(const char *s1, char *s2, size_t n);
int		ft_tolower(int i);
int		ft_toupper(int i);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strchr(const char *s, int i);
char	*ft_strdup(const char *s);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *str, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *s1, const void *s2, size_t n);
void	*ft_memset(void *b, int c, size_t len);

#endif
/*Cierro la include guard*/