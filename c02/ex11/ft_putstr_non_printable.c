/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyukim <gyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:25:06 by gyukim            #+#    #+#             */
/*   Updated: 2021/10/20 16:32:39 by gyukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_convert_hex(int c, int check)
{
	char	*base;

	base = "0123456789abcdef";
	if (c < 0)
		c += 256;
	if (c >= 16)
	{
		ft_convert_hex(c / 16, 1);
		ft_convert_hex(c % 16, 1);
	}
	else
	{
		if (check == 0)
			ft_putchar('0');
		ft_putchar(base[c]);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] == 127)
		{
			ft_putchar('\\');
			j = str[i];
			ft_convert_hex(j, 0);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
