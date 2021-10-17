/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyukim <gyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:08:02 by gyukim            #+#    #+#             */
/*   Updated: 2021/10/17 20:03:08 by gyukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_printmap(int MAP[][4], int row_col[][4], int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		ft_putchar(' ');
		while (j < size)
		{
			ft_putchar(MAP[i][j] + 48);
			ft_putchar(' ');
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}

int	solve1(int row_col[][4], int *pos, int size)
{
	int	x;
	int	y;

	x = pos[1];
	y = pos[0];
	if (row_col[0][x] == size)
		return (y + 1);
	else if (row_col[1][x] == size)
		return (size - y);
	else if (row_col[2][y] == size)
		return (x + 1);
	else if (row_col[3][y] == size)
		return (size - x);
	else if (row_col[0][x] == 1 && y == 0)
		return (size);
	else if (row_col[1][x] == 1 && y == size - 1)
		return (size);
	else if (row_col[2][y] == 1 && x == 0)
		return (size);
	else if (row_col[3][y] == 1 && y == size - 1)
		return (size);
	return (0);
}

int	solve2(int row_col[][4], int *pos, int size)
{
	int	x;
	int	y;

	x = pos[1];
	y = pos[0];
	if (row_col[0][x] + row_col[1][x] == size + 1)
	{
		if (row_col[0][x] > row_col[1][x] && row_col[0][x] == y + 1)
			return (size);
		else if (row_col[0][x] < row_col[1][x] && row_col[1][x] == size - y)
			return (size);
	}
	else if (row_col[2][y] + row_col[3][y] == size + 1)
	{
		if (row_col[2][y] > row_col[3][y] && row_col[2][y] == x + 1 )
			return (size);
		else if (row_col[2][y] < row_col[3][y] && row_col[3][y] == size - x)
			return (size);
	}
	return (0);
}

void	init(int map[][4], int row_col[][4], char *argv[], int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		while (j < n)
		{
			map[i][j] = 0;
			j++;
		}
		i++;
	}

	i = 0;
	while (i < 16)
	{
		row_col[i%16][i] = argv[1][i*2] - 48;
		i++;
	}
	return ;
}

int	error(int argc, char *argv[])
{
	int	err;
	int	i;
	int	count;
	int	num[16] = {0};
	
	err = 0;
	i = 0;
	count = 0;
	if (argc != 2)
		err = 1;
	else
	{
		while (argv[1][1])
		{
			if ((argv[1][i] >= '0' + 1) && (argv[1][i] <= '0' + 4))
			{
				num[count] = argv[1][i] - '0';
				count++;
			}
			else if (argv[1][i] != ' ')
			{
				err = 1;
				break;
			}
		}
		if (count != 16) err = 1;
		else
		{
			while (count > 12)
			{
				if ((argv[1][count] + argv[1][count - 4]) > 5)
				{
					err = 1;
					break;
				}
				count--;
			}
			count = 8;
			while (count > 4)
			{
				if ((argv[1][count] + argv[1][count - 4]) > 5)
				{
					err = 1;
					break;
				}
				count--;
			}
		}
	}
	return (err);
}

int	main(int argc, char *argv[])
{
	int	row_col[4][4];
	int	map[4][4];
	int	pos[2];
	
	pos[0] = 0;
	if (error(argc, argv) == 1)
	{
		write(1, "Error\n", 6);
	}

	init(map, row_col, argv, 4);
	while (pos[0] < 4)
	{
		pos[1] = 0;
		while (pos[1] < 4)
		{
			if (map[pos[0]][pos[1]] == 0)
			{
				map[pos[0]][pos[1]] = solve1(row_col, pos, 4);
				map[pos[0]][pos[1]] = solve2(row_col, pos, 4);
			}
			pos[1]++;
		}
		pos[0]++;
	}
	ft_printmap(map, row_col, 4);
}
