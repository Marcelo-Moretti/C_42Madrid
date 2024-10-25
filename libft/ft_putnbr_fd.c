/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <mmoretti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:30:21 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/25 19:59:23 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		if (n == INT_MIN)
		{
			ft_putstr_fd("-2147483648", fd);
			return ;
		}
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

/*
int main()
{
    int fd = STDOUT_FILENO;

    ft_putnbr_fd(42, fd);
    ft_putchar_fd('\n', fd);
    ft_putnbr_fd(-42, fd);
    ft_putchar_fd('\n', fd);
    ft_putnbr_fd(INT_MIN, fd);
    ft_putchar_fd('\n', fd);
    ft_putnbr_fd(0, fd);
    ft_putchar_fd('\n', fd);

    return 0;
}
*/