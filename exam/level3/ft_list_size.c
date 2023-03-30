/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:57:08 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/03/23 02:10:07 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_list_size
Expected files   : ft_list_size.c, ft_list.h
Allowed functions:
--------------------------------------------------------------------------------

Write a function that returns the number of elements in the linked list that's
passed to it.

It must be declared as follows:

int	ft_list_size(t_list *begin_list);

You must use the following structure, and turn it in as a file called
ft_list.h:

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <string.h>
#include <stdlib.h>


typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

int	ft_list_size(t_list *begin_list)
{
	int i;

	i = 0;
	while(begin_list)
	{
		i++;
		begin_list = begin_list->next;
	}
	return (i);
}


int main ()
{
	t_list s0, s1, s2, s3, s4, s5;
	
	s0.next = &s1;
	s1.next = &s2;
	s2.next = &s3;
	s3.next = &s4;
	s4.next = &s5;
	s5.next = NULL;
	
	s0.data = "1";
	s1.data = "1";
	s2.data = "54";
	s3.data = "833";
	s4.data = "3724";
	s5.data = "36458";

	printf("%d\n", ft_list_size(&s0));

}