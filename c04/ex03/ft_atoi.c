/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyukim <gyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:11:31 by gyukim            #+#    #+#             */
/*   Updated: 2021/10/21 20:41:15 by gyukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	num;
	sign = 1;
	i = 0;
	num = 0;
	while(str[i] <= 32 || str[i] == 127)
		i++;
	while(str[i] == 45 || str[i] == 43)
	{
		if(str[i] == 45)
			sign *= -1;
		i++;
	}
	while(str[i] >= 48 && str[i] <= 57)
	{
		num = (num * 10) + str[i] - 48;
		i++;
	}
	return (num * sign);
}
