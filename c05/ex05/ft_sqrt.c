/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyukim <gyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 16:52:11 by gyukim            #+#    #+#             */
/*   Updated: 2021/10/24 18:10:50 by gyukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive(int nb, int n)
{
	if (n >= 46341)
		return (0);
	if (n * n == nb)
		return (n);
	if (n * n < nb)
		return (ft_recursive(nb, n + 1));
	return (0);
}

int	ft_sqrt(int nb)
{
	return (ft_recursive(nb, 0));
}
