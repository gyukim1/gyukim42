/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyukim <gyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 16:11:42 by gyukim            #+#    #+#             */
/*   Updated: 2021/10/24 19:00:47 by gyukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	error(char *str)
{
	int	i;
	int	ascii[128];
	int	k;

	i = 0;
	while (i <= 128)
		ascii[i++] = 0;
	i = 0;
	while (str[i])
	{
		k = str[i];
		if (str[i] == 43 || str[i] == 45 || ascii[k]
			|| (str[i] >= 8 && str[i] <= 13) || str[i] == 32)
			return (1);
		ascii[k] = 1;
		i++;
	}
	if (i <= 1)
		return (1);
	return (0);
}

int	ft_index(char *str)
{
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 8 && str[i] <= 13))
		i++;
	while (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
	}
	return (i * sign);
}

int	ft_convert_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	basesize;
	int	sign;
	int	result;

	result = 0;
	sign = 1;
	basesize = 0;
	if (error(base))
		return (0);
	while (base[basesize])
		basesize++;
	if (ft_index(str) < 0)
		sign *= -1;
	i = ft_index(str) * sign;
	while (str[i])
	{
		if (ft_convert_base(str[i], base) == -1)
			return (result * sign);
		result *= basesize;
		result += (ft_convert_base(str[i], base));
		i++;
	}
	return (result * sign);
}
