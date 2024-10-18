/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:28:28 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/15 19:43:31 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putchar_fd(char c, int fd)
{
	if (c != NULL)
	{
		write(fd, &c, 1);
	}
}

/*
int main(void)
{
	char	character;
	int	file_name;

	character = 'I';
	file_name = open("I_Robot", O_RDWR);
	ft_putchar_fd(character, file_name);
	close(file_name);
}
*/