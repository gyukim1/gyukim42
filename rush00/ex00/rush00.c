/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyukim <gyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:27:01 by gyukim            #+#    #+#             */
/*   Updated: 2021/10/10 16:24:42 by sungjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);

void	draw(int x, int y, int row)
{
	int		col;

	col = 1;
	while (col <= x)
	{
		if ((col == 1 || col == x) && (row == 1 || row == y))
		{
			ft_putchar('o');
		}
		else if (row == 1 || row == y)
		{
			ft_putchar('-');
		}
		else if (col == 1 || col == x)
		{
			ft_putchar('|');
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
		draw(x, y, row);
		ft_putchar('\n');
		row += 1;
	}
}
