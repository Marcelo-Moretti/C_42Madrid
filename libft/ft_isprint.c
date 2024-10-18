/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:00:34 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/17 19:10:56 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_isprint(int c)
{
	while (c >= 32 && c <= 127)
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
	write(1, ft_isprint(num), 1);
	write(1, ft_isprint(word), 1);
	return (0);
}
*/