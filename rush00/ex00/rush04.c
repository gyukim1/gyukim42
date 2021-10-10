/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyukim <gyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 20:54:22 by gyukim            #+#    #+#             */
/*   Updated: 2021/10/10 17:08:42 by sungjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);

void	draw_ex(int x, int row, int col)
{
	if (col == 1)
	{
		if (row == 1)
		{
			ft_putchar('A');
		}
		else
		{
			ft_putchar('C');
		}
	}
	else if (col == x)
	{
		if (row == 1)
		{
			ft_putchar('C');
		}
		else
		{
			ft_putchar('A');
		}	
	}
}

void	draw_row(int x, int y, int row)
{
	int	col;

	col = 1;
	while (col <= x)
	{
		if ((row == 1 || row == y) && (col == 1 || col == x))
		{
			draw_ex(x, row, col);
		}
		else if (col == 1 || col == x || row == 1 || row == y)
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
