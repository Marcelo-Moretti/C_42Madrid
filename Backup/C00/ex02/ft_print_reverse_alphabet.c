/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:01:01 by mmoretti          #+#    #+#             */
/*   Updated: 2024/07/22 17:38:41 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	rever;

	rever = 'z';
	while (rever >= 'a')
	{
		write (1, &rever, 1);
		rever--;
	}
}

/*int	main(void)
{
	ft_print_reverse_alphabet();
	return (0);
}
*/
