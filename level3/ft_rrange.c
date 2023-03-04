/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:57:08 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/02/23 14:41:08 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*

Subject
Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.
*/



#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <string.h>
#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
	int i = 0;
	unsigned int len;
	if(end >= start)
	{
		len = end - start + 1;
		int *arr = (int *)malloc(len * sizeof(int));
		while(end >= start)
		{
			arr[i] = end;
			i++;
			end--;
		}
		return arr;
	}
	else
	{
		len = start - end + 1;
		int *arr = (int *)malloc(len * sizeof(int));
		while(end <= start)
		{
			arr[i] = end;
			end++;
			i++;
		}
		return arr;
	}
}

// int main ()
// {
// 	int *p = ft_rrange(0, -3);
// 	int i = -1;
// 	while(++i < 4)
// 		printf("%d  ", p[i]);
// }