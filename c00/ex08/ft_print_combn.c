/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyukim <gyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:17:40 by gyukim            #+#    #+#             */
/*   Updated: 2021/10/12 17:02:09 by gyukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_print_arr(int arr[], int n)
{
	int index;
	index = 0;
	while(index < n) ft_putchar(arr[index++]+48);
	ft_putchar(',');
	ft_putchar(' ');
}

void	ft_reset(int arr[], int index, int n)
{
	while(index < n)
	{
		arr[index+1] = arr[index]+1;
		index++;
	}
}
int	ft_check(int arr[], int index, int n)
{
	int max;
	max = 9;
	while(n > index) {
		if(arr[n] == max)
		{
			n--;
			max--;
		}
		else return n, max;
	}
	
	return 0;
}
void	ft_print_combn(int n)
{
	int arr[n];
	int index;
	int max;

	index = 0;
	max = 9;

	while(index < n)
	{
		arr[index] = index;
		index++;
	}

	index--;
	ft_print_arr(arr, n);
	while(index > -1)
	{
		if(arr[index] < max) arr[index]++;
		else 
		{
			if(index>0) --index, --max;
			else return;

			arr[index]++;
			ft_reset(arr, index, n);
			if(ft_check(arr, index, n) > 0)
			{
				index, max = ft_check(arr, index, n);
			}
		}
		ft_print_arr(arr, n);
	}
}
