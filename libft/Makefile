#Defino el nombre de la libreria
Library	=	libft

#Añado los archivos sin la extensión .c
files	=	ft_strlen \
			ft_memmove \
			ft_memcpy \
			ft_strlcpy \
			ft_strlcat \
			ft_isalpha \
			ft_isdigit \
			ft_isalnum \
			ft_isascii \
			ft_isprint \
			ft_memset \
			ft_bzero \
			ft_toupper \
			ft_tolower \
			ft_strchr \
			ft_strrchr \
			ft_strncmp \
			ft_memchr \
			ft_memcmp \
			ft_strnstr \
			ft_atoi \
			ft_calloc \
			ft_strdup \
			ft_substr \
			ft_strjoin \
			ft_strtrim \
			ft_split \
			ft_itoa \
			ft_strmapi \
			ft_striteri \
			ft_putchar_fd \
			ft_putstr_fd \
			ft_putendl_fd \
			ft_putnbr_fd \

#Defino el compilador
Compiler	=	cc

#Defino las banderas para la compilación
CmpFlags	=	-Wall -Wextra -Werror

#Defino el nombre del archivo de salida (libft.a)
OUTN		=	$(Library).a

#Añado la extensión .c a todos los archivos
CFILES		=	$(files:%=%.c)

#Genero la lista de archivos objetos .o
OFILES		=	$(files:%=%.o)

#Creo la variable NAME y la igualo a libft.a
NAME		=	$(OUTN)

#Creo el comando para compilar todas las funciones
# -c evita que se enlacen los archivos al compilar creando archivos objeto .o
# -I./ buscará headers en el directorio actual
# ar es una utilidad que crea y manipula archivos de librerias
# -rc reemplaza o crea un archivo, si ya existe, lo actualiza
$(NAME):
	$(Compiler) $(CmpFlags) -c $(CFILES) -I./
	ar -rc $(OUTN) $(OFILES)

#se ejecuta si solo se ejecuta make. Aquí indica que debe construir $(NAME)
all: $(NAME)

#Para eliminar la libreria libft.a y la lista de objetos .o
clean:
	rm -f $(NAME)
	rm -f $(OFILES)

#Ejecuta el comando clean
fclean: clean
	rm -f $(NAME)

#Limpio todos los archivos y los vuelvo a compilar y generar de cero
re: fclean all

#Defino que los siguientes nombres son comandos y no archivos
.PHONY: all, clean, fclean, re