/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:57:22 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/17 19:00:36 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_isascii(int c)
{
	while (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}

/*
int main(void)
{
	int	num;
	char	word;

	num = 5;
	word = 'hello';
	write(1, ft_isascii(num), 1);
	write(1, ft_isascii(word), 1);
	return (0);
}
*/