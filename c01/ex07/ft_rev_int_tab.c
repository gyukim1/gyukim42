/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyukim <gyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:29:01 by gyukim            #+#    #+#             */
/*   Updated: 2021/10/12 17:49:43 by gyukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	cnt;
	int	rcnt;
	int	i;

	cnt = 0;
	rcnt = size - 1;
	while (cnt < size / 2)
	{
		i = tab[cnt];
		tab[cnt] = tab[rcnt];
		tab[rcnt] = i;
		cnt++;
		rcnt--;
	}
}
