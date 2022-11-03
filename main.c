/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:25:20 by mugurel           #+#    #+#             */
/*   Updated: 2022/11/03 17:43:17 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "lib/ft_lib.h"

int	main(int ac, char **av)
{
	int		imap;

	imap = 1;
	if (ac == 1)
	{
		// standart dosyayi okuma
	}
	if (ac > 1)
	{
		while (imap < ac)
		{
			mtu_bsq(av[imap]);
			imap++;
		}
	}
}
