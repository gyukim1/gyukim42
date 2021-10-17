#include <stdio.h>
void	ft_putchar(char c)
{
	printf("%c", c);
}
void	ft_printMAP(int(*MAP)[4], int(*row_col)[4], int size) {
	int i;
	int j;

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
int solve1(int(*row_col)[4], int pos[2], int size) {
	int x = pos[1];
	int y = pos[0];
	int i;
	int j;

	if (row_col[0][x] == size)
		return y + 1;
	else if (row_col[1][x] == size)
		return size - y;
	else if (row_col[2][y] == size)
		return x + 1;
	else if (row_col[3][y] == size)
		return size - x;
	else if (row_col[0][x] == 1 && y == 0)
		return size;
	else if (row_col[1][x] == 1 && y == size - 1)
		return size;
	else if (row_col[2][y] == 1 && x == 0)
		return size;
	else if (row_col[3][y] == 1 && y == size - 1)
		return size;


	else if (row_col[0][x] + row_col[1][x] == size + 1)
	{
		if (row_col[0][x] > row_col[1][x])
		{
			if (row_col[0][x] == y + 1)
				return size;
		}
		else
		{
			if (row_col[1][x] == size - y)
				return size;
		}
	}
	else if (row_col[2][y] + row_col[3][y] == size + 1)
	{
		if (row_col[2][y] > row_col[3][y]) {
			if (row_col[2][y] == x + 1)
				return size;
		}
		else
		{
			if (row_col[3][y] == size - x)
				return size;
		}
	}

	return 0;
}
int main()
{
	const static int N = 4; //사이즈

	int row_col[N][N] = {
		{1, 2, 3, 2},		//col_up			rol_col[0]
		{3, 2, 1, 2},		//col_down			rol_col[1]
		{1, 2, 4 ,3},		//row_left			rol_col[2]
		{2, 2, 1, 2},		//row_right			rol_col[3]
	};
	int solveMAP[N][N] = {
		{ 1, 2, 3, 4},
		{2, 3, 4, 1},
		{3, 4, 1 ,2},
		{4, 1, 2, 3},
	};
	int MAP[N][N] = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0 ,0},
		{0, 0, 0, 0},
	};
	int pos[2] = { 0, 0 };
	//pos[0] y좌표
	//pos[1] x좌표
	while (pos[0] < N)
	{
		pos[1] = 0;
		while (pos[1] < N)
		{
			if (MAP[pos[0]][pos[1]] == 0)
				MAP[pos[0]][pos[1]] = solve1(row_col, pos, N);
			pos[1]++;
		}
		pos[0]++;
	}
	ft_printMAP(MAP, row_col, N);
}
