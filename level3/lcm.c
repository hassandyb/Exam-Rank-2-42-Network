/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:57:08 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/02/23 16:07:54 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
	Subject:
Assignment name  : lcm
Expected files   : lcm.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function who takes two unsigned int as parameters and returns the
computed LCM of those parameters.

LCM (Lowest Common Multiple) of two non-zero integers is the smallest postive
integer divisible by the both integers.

A LCM can be calculated in two ways:

- You can calculate every multiples of each integers until you have a common
multiple other than 0

- You can use the HCF (Highest Common Factor) of these two integers and
calculate as follows:

	LCM(x, y) = | x * y | / HCF(x, y)

  | x * y | means "Absolute value of the product of x by y"

If at least one integer is null, LCM is equal to 0.

Your function must be prototyped as follows:

  unsigned int    lcm(unsigned int a, unsigned int b);

*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <string.h>
#include <stdlib.h>


unsigned int    lcm(unsigned int a, unsigned int b)
{
	unsigned int l;
	if(a * b == 0)
		return 0;
	if(a > b)
		l = a;
	l = b;
	while(1)
	{
		if(l % a == 0 && l % b == 0)
			return l;
		l++;
	}
	
}

// int main ()
// {
// 	printf("%d\n", lcm(5, 10));
// }