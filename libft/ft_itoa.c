/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoretti <mmoretti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:25:22 by mmoretti          #+#    #+#             */
/*   Updated: 2024/10/25 20:21:54 by mmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_inttochar(unsigned int number)
{
	if (number == 0)
		return (0 + '0');
	if (number > 0)
	{
		ft_inttochar(number / 10);
		number %= 10;
	}
	return (number + '0');
}

static int	ft_isneg(int number)
{
	if (number < 0)
		return (1);
	return (0);
}

static size_t	ft_intlen(int n)
{
	size_t			length;
	unsigned int	number;

	length = 0;
	if (ft_isneg(n))
	{
		number = (unsigned int)-n;
		length++;
	}
	else
		number = (unsigned int)n;
	while (number > 9)
	{
		number /= 10;
		length++;
	}
	length++;
	return (length);
}

char	*ft_itoa(int n)
{
	char			*result;
	size_t			length;
	unsigned int	number;
	int				counter;

	length = ft_intlen(n);
	result = malloc(sizeof(char) * (length + 1));
	if (result == NULL)
		return (NULL);
	counter = 0;
	if (ft_isneg(n))
		number = (unsigned int)-n;
	else
		number = (unsigned int)n;
	while (counter++ <= (int)length - 1)
	{
		result[(int)length - counter] = ft_inttochar(number);
		number /= 10;
	}
	if (ft_isneg(n))
		result[0] = '-';
	result[length] = '\0';
	return (result);
}

/*
int main()
{
    int n[] = {0, 42, -42, 123456, -987654321, INT_MIN};
    int size = sizeof(n) / sizeof(n[0]);
    int i = 0;

    while (i < size)
    {
        char *r = ft_itoa(n[i]);
        if (r != NULL)
        {
            write(1, "ft_itoa(", 8);
            char buffer[12];
            int length = snprintf(buffer, sizeof(buffer), "%d) = %s\n", n[i], r);
            write(1, buffer, length);
            free(r);
        }
        else
        {
            write(1, "Error al convertir.\n", 20);
        }
        i++;
    }

    return 0;
}
*/