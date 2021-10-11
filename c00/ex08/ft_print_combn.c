/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyukim <gyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:17:40 by gyukim            #+#    #+#             */
/*   Updated: 2021/10/11 16:49:46 by gyukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_print_tochar(int arr_n[], int index, int n)
{
	int i;
	i = 0;
	while(i < n)
	{
		ft_putchar(arr_n[index]+48);
		i++;
	}
	ft_putchar(',');
	ft_putchar(' ');
}
void	ft_int_tab(int arr_n[], int index)
{
	if (arr_n[index]>=9)
	{
		arr_n[index] = 0;
	}
	else
	{
		arr_n[index]++;

	}
}

void	ft_print_combn(int n)
{
	int arr_n[10];
	int index;

	index = 10;
	while(index>0)
	{
		index--;
		arr_n[index] = 0;
	}
	index = 0;
	
	while(index < n)
	{
		ft_int_tab(arr_n, index);
		ft_print_tochar(arr_n, index, n);
		index++;
	}
}
