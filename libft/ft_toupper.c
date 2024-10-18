/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:13:17 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/17 19:42:50 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_toupper(int i)
{
	if (i >= 'a' && i <= 'z')
		return (i - 32);
	return (i);
}

/*
int	main(void)
{
	if (ft_toupper('a' - 1) == 'a' - 1)
	{
		if (ft_toupper('a' + 1) == 'a' + 1)
		{
			if (ft_toupper('a') == 'A' && ft_toupper('z') == 'Z')
			{
				write(1, 'ok\n', 3);
			}
		}
	}
	return (0);
}
*/