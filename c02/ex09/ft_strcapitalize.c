/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyukim <gyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:54:59 by gyukim            #+#    #+#             */
/*   Updated: 2021/10/21 14:22:37 by gyukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	is_word;	

	i = 0;
	is_word = 1;
	while (str[i])
	{
		if (str[i] < 65 || (str[i] > 90 && str[i] < 97) || str[i] > 122)
			is_word = 1;
		if (str[i] >= 48 && str[i] <= 57)
			is_word = 0;
		if ((str[i] >= 65 && str[i] <= 90) && !is_word)
			str[i] += 32;
		if ((str[i] >= 65 && str[i] <= 90) && is_word)
			is_word = 0;
		if ((str[i] >= 97 && str[i] <= 122) && is_word)
		{
			str[i] -= 32;
			is_word = 0;
		}
		i++;
	}
	return (str);
}
