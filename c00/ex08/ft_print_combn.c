/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyukim <gyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:17:40 by gyukim            #+#    #+#             */
/*   Updated: 2021/10/16 11:34:34 by gyukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_array_print(int *array, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putchar(array[i]+48);
		i++;
	}
	if(array[0]!=10-n)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_array_add (int *array, int n)
{
	int i;
	int max;

	i = n - 1;
	max = 9;
	while (array[i] == max)
	{
		i--;
		max--;
	}
	array[i]++;
	while (i < n)
	{
		array[i + 1] = array[i] + 1;
		i++;
	}
}

void	ft_print_combn(int n)
{
	int i;
	int array[10];

	i = 0;
	while (i < n)
	{
		array[i] = i;
		i++;
	}
	ft_array_print(array, n);
	while (array[n-1] != 9 || array[0] != 10-n)
	{
		if(array[n-1] != 9) array[n-1]++;
		else ft_array_add(array, n);
		ft_array_print(array, n);
	}
}
