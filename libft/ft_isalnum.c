/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:47:15 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/17 19:19:16 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_isalnum(int c)
{
	while (ft_isalpha(c) || ft_isdigit(c))
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
	write(1, ft_isalnum(num), 1);
	write(1, ft_isalnum(word), 1);
	return (0);
}
*/