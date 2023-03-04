/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:57:08 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/02/23 17:39:09 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Subject
Assignment name  : paramsum
Expected files   : paramsum.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays the number of arguments passed to it, followed by
a newline.

If there are no arguments, just display a 0 followed by a newline.

Example:

$>./paramsum 1 2 3 5 7 24
6
$>./paramsum 6 12 24 | cat -e
3$
$>./paramsum | cat -e
0$
$>
*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <string.h>
#include <stdlib.h>

void ft_putnbr(int n)
{
	int l;
	if(n >= 10)
	{
		ft_putnbr (n / 10);
		l = (n % 10) + '0';
		write(1, &l, 1);
		
	}
	else
	{
		n = n + '0';
		write(1, &n, 1);
		
	}
}
int main (int argc, char **argv)
{
	int i = 0;
	if(argc == 1)
		write(1, "0", 1);
	else
	{
		while(argv[i])
			i++;
		ft_putnbr(i - 1);
	}
	write(1, "\n", 1);
}

