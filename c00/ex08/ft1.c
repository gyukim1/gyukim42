#include <unistd.h>
int	ft_check(int *arr, int *max_arr, int n);
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_print_combn(int n)
{
	int min_arr[n];
	int max_arr[n];
	int arr[n];
	int i;

	i = 0;
	while (i < n)
	{
		min_arr[i] = i;
		arr[i] = i;
		max_arr[n-i-1] = 9-i;
		i++;
	}
	i=0;
	while (i < n)
	{	
		ft_putchar(max_arr[i]+48);
		i++;
	}
	ft_putchar('\n');
	i=0;
	while (i < n)
	{
		ft_putchar(arr[i]+48);
		i++;
	}
	while (ft_check(arr, max_arr, n))
	{
		i=9;
		if (arr[n-1] != max_arr[n-1]) arr[n-1]++;
		else
		{
			while(arr[i] == max_arr[i]) i--;
			arr[i]++;
			while(i++ < n)
			{
				arr[i] = min_arr[i];
			}
		}
		i=0;
		while (i<n)
		{
			ft_putchar(arr[i]+48);
			i++;
		}
	}
}
int	ft_check(int *arr, int *max_arr, int n)
{
	int i;

	i = 0;
	while(i < n)
	{
		if(arr[i] != max_arr[i])
			return 1;
		else
			i++;
	}
	return 0;
}
int	main(void)
{
	ft_print_combn(9);
}
