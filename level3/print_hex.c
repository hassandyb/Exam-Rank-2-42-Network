/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:57:08 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/02/23 19:36:14 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Subject
Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int ft_atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int result = 0;
	while((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if(s[i] == '-' || s[i] == '+')
	{
		if(s[i] == '-')
			sign = -1;
		i++;
	}
	while(s[i] >= '0' && s[i] <= '9')
	{
		result = (result * 10) + (s[i] - '0');
		i++;
	}
	return result * sign;
}
void ft_print(int nbr)
{
	char arr[17] = "0123456789abcdef";
	write(1, &arr[nbr], 1);
}
void ft_print_hex(int n)
{
	char c;
	if(n >= 16)
	{
		ft_print_hex(n / 16);
		ft_print_hex(n % 16);
	}
	else
		ft_print(n);
}
int main (int argc, char **argv)
{
	if(argc == 2)
	{
		int n = ft_atoi(argv[1]);
		ft_print_hex(n);
	}
	write(1, "\n", 1);
}


