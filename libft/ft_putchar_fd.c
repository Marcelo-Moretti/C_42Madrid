/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <mmoretti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:28:28 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/25 18:04:23 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
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