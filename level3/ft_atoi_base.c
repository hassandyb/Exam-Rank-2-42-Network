/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:03:54 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/02/26 11:48:34 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_get_number(char c, int base)
{
	int n = 0;
	if(c >= '0' && c <= '9')
	{
		n = c - '0';
	}
	else if((c >= 'a' && c <= 'f'))
		n = (c - 'a') + 10;
		
	else if((c >= 'A' && c <= 'F'))
		n = (c - 'A') + 10;
	if(n >= base)
		return -1;
	return n;
	
}

int	my_ft_atoi_base(const char *str, int str_base)
{
	int i = 0;
	int sign = 1;
	int total;
	static int power;
	if(str[0] == '-')
	{
		sign = -1;
		i++;
	}
	while(str[i])
		i++;
	i--;
	total = ft_get_number(str[i], str_base);
	if(ft_get_number(str[i], str_base) == -1)
			return 0;
	i--;
	power = 1;
	while(i >= 0 && str[i] != '-')
	{
		power = (power * str_base);
		total = total + (ft_get_number(str[i], str_base) * power);
		if(ft_get_number(str[i], str_base) == -1)
			return 0;
		i--;
	}
	return (total * sign);
}

int main ()
{
	printf("%d", my_ft_atoi_base("abc23", 5));
}