/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:29:41 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/15 19:44:22 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putstr_fd(char *s, int fd)
{
	if (s != NULL)
	{
		write(fd, s, ft_strlen(s));
	}
}

/*
int main(void)
{
	char	phrase;
	int	file_dest;

	phrase = 'hello world';
	file_dest = open("file", O_RDWR);
	ft_putstr_fd(phrase, file_d);
	close(file_dest);
}
*/