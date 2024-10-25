# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoretti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/09 18:53:35 by mmoretti          #+#    #+#              #
#    Updated: 2024/10/14 17:44:25 by mmoretti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# variables
NAME	=	libft.a

FILES	=	ft_strlen \
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

COMPILER	=	cc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

CFILES	=	$(FILES:%=%.c)

OFILES	=	$(FILES:%=%.o)

# rules
all:	$(NAME)

$(NAME): $(OFILES)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OFILES)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all, clean, fclean, re
