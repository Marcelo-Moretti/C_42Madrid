/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:48:14 by mmoretti          #+#    #+#             */
/*   Updated: 2024/07/17 21:08:23 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	digit1;
	char	digit2;
	char	digit3;

	digit1 = '0';
	while (digit1 <= '7')
	{
		digit2 = digit1 + 1;
		while (digit2 <= '8')
		{
			digit3 = digit2 + 1;
			while (digit3 <= '9')
			{
				write (1, &digit1, 1);
				write (1, &digit2, 1);
				write (1, &digit3, 1);
				if (digit1 != '7')
					write (1, ", ", 2);
				digit3++;
			}
			digit2++;
		}
		digit1++;
	}
}

/*int	main(void)
{
	ft_print_comb();
	return (0);
}*/
