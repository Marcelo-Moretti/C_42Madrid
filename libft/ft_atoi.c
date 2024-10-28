/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <mmoretti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:21:52 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/28 20:30:37 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	counter;
	int	negative;
	int	result;

	counter = 0;
	negative = 1;
	result = 0;
	while (nptr[counter] == ' ' || (nptr[counter] >= 9 && nptr[counter] <= 13))
		counter++;
	if (nptr[counter] == '-' || nptr[counter] == '+')
	{
		if (nptr[counter] == '-')
			negative *= -1;
		counter++;
	}
	while (nptr[counter] != '\0' && ft_isdigit(nptr[counter]))
	{
		result = (result * 10) + ((nptr[counter] - '0'));
		counter++;
	}
	return (result * negative);
}
