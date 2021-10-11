/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyukim <gyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:19:05 by gyukim            #+#    #+#             */
/*   Updated: 2021/10/11 15:51:16 by gyukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_tochar(int i)
{
	char	char_1;
	char	char_2;

	if (i < 10)
	{
		char_1 = 48;
		char_2 = i + 48;
	}
	else
	{
		char_1 = (i / 10) + 48;
		char_2 = (i % 10) + 48;
	}
	ft_putchar(char_1);
	ft_putchar(char_2);
}

void	ft_print_comb2(void)
{
	int	int_1;
	int	int_2;

	int_1 = 0;
	while (int_1 < 99)
	{
		int_2 = int_1 + 1;
		while (int_2 < 100)
		{
			ft_print_tochar(int_1);
			ft_putchar(' ');
			ft_print_tochar(int_2);
			if (int_1 < 98)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			int_2++;
		}
		int_1++;
	}
}
