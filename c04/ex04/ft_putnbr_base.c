/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyukim <gyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:58:51 by gyukim            #+#    #+#             */
/*   Updated: 2021/10/24 19:05:40 by gyukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

unsigned int	error(char *str)
{
	int	i;
	int	ascii[128];
	int	k;

	i = 0;
	while (i <= 128)
		ascii[i++] = 0;
	i = 0;
	while (str[i])
	{
		k = str[i];
		if (str[i] == 43 || str[i] == 45 || ascii[k])
			return (1);
		ascii[k] = 1;
		i++;
	}
	if (i <= 1)
		return (1);
	return (0);
}

void	ft_write_base(int nb, char *base, unsigned int basesize)
{
	long	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr >= basesize)
	{
		ft_write_base(nbr / basesize, base, basesize);
		ft_write_base(nbr % basesize, base, basesize);
	}
	else
	{
		ft_putchar(base[nbr]);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;

	i = 0;
	if (error(base))
		return ;
	while (base[i])
		i++;
	ft_write_base(nbr, base, i);
	return ;
}
