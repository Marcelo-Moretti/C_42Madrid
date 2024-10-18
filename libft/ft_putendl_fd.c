/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:29:57 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/15 19:45:17 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putendl_fd(char *s, int fd)
{
	if (s != NULL)
	{
		ft_putstr_fd(s, fd);
		ft_putchar_fd('\n', fd);
	}
}

/*
int main(void)
{
	char	phrase;
	int	file_dest;

	phrase = 'hello world';
	file_dest = open("file", O_RDWR);
	ft_putendl_fd(phrase, file_dest);
	close(file_dest);
}
*/