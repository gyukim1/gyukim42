/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyukim <gyukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:58:51 by gyukim            #+#    #+#             */
/*   Updated: 2021/10/21 21:13:00 by gyukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	error(char *str)
{
	int	i;
	int	ascii[128];

	i = 0;
	while(i <= 128)
		ascii[i++] = 0;
	i = 0;
	while(str[i])
	{
		if(str[i] == 43 || str[i] == 45 || ascii[str[i]])
			return 1;
		ascii[str[i]] = 1;
		i++;
	}
	if (i<=1)
		return 1;
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;

	i = 0;
	if (error(base))
		write(1, &"Z", 1);
	return ;

}
