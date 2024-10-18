/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:14:12 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/14 19:38:56 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_tolower(int i)
{
	if (i >= 'a' && i <= 'z')
		return (i + 32);
	return (i);
}

/*
int	main(void)
{
	if (ft_tolower('A' - 1) == 'A' - 1)
	{
		if (ft_tolower('A' + 1) == 'A' + 1)
		{
			if (ft_tolower('A') == 'a' && ft_toupper('Z') == 'z')
			{
				write(1, 'ok\n', 3);
			}
		}
	}
	return (0);
}
*/