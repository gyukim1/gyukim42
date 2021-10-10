/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:14:53 by chaejkim          #+#    #+#             */
/*   Updated: 2021/10/10 17:23:32 by sungjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	draw_row(int x, int y, int row)
{
	int	col;

	col = 1;
	while (col <= x)
	{
		if ((col == 1 && row == 1) || (col == x && row == 1))
		{
			ft_putchar('A');
		}
		else if ((col == 1 && row == y) || (col == x && row == y))
		{
			ft_putchar('C');
		}
		else if (row == 1 || row == y || col == 1 || col == x)
		{
			ft_putchar('B');
		}
		else
		{
			ft_putchar(' ');
		}
		col += 1;
	}
}	

void	rush(int x, int y)
{
	int	row;

	row = 1;
	if (x <= 0 || y <= 0)
	{
		return ;
	}
	while (row <= y)
	{
		draw_row(x, y, row);
		ft_putchar('\n');
		row += 1;
	}
}
