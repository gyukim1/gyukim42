/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyukim <gyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:41:05 by gyukim            #+#    #+#             */
/*   Updated: 2021/10/11 15:11:55 by gyukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putchar_comb(char c_1, char c_2, char c_3)
{
	write(1, &c_1, 1);
	write(1, &c_2, 1);
	write(1, &c_3, 1);
}

void	ft_print_comb(void)
{
	char	i_1;
	char	i_2;
	char	i_3;

	i_1 = '0';
	while (i_1 <= '9')
	{
		i_2 = i_1 + 1;
		while (i_2 <= '9')
		{
			i_3 = i_2 + 1;
			while (i_3 <= '9')
			{
				ft_putchar_comb(i_1, i_2, i_3);
				i_3++;
				if (i_1 != '7')
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
			}
			i_2++;
		}
		i_1++;
	}
}
