/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:37:52 by mugurel           #+#    #+#             */
/*   Updated: 2022/11/03 17:43:20 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
	{
		i++;
	}
	return (&str[i]);
}

int	ft_atoi(char *str)
{
	int		i;
	int		mult;
	int		nb;
	char	*onum;

	mult = 1;
	nb = 0;
	i = 0;
	onum = ft_whitespace(str);
	while (onum[i] == '-' || onum[i] == '+')
	{
		if (onum[i] == '-')
		mult *= -1;
		i++;
	}
	while (onum[i] >= '0' && onum[i] <= '9')
	{
		nb = (nb * 10) + (onum[i] - '0');
		i++;
	}
	nb *= mult;
	return (nb);
}
