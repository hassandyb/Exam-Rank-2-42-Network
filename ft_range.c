/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:57:08 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/02/23 14:01:25 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <string.h>
#include <stdlib.h>



int     *ft_range(int start, int end)
{
	unsigned char len;
	int i = 0;
	if(start > end)
	{
		len = start - end + 1;
		int *arr = (int *)malloc(len * sizeof(int));
		while(start >= end)
		{
			arr[i] = start;
			start --;
			i++;
		}
		return arr;
	}
	else
	{
		len = end - start + 1;
		int *arr = (int *)malloc(len * sizeof(int));
		while(start <= end)
		{
			arr[i] = start;
			start ++;
			i++;
		}
		return arr;
	}
	
}


// int main ()
// {
// 	int *p = ft_range(1, 3);
// 	int i = 0;
// 	while(i < 3)
// 	{
// 		printf("%d  ", p[i]);
// 		i++;
// 	}
// }