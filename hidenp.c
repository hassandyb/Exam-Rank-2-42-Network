/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:57:08 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/02/26 13:27:57 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Subject
Assignment name  : hidenp
Expected files   : hidenp.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program named hidenp that takes two strings and displays 1
followed by a newline if the first string is hidden in the second one,
otherwise displays 0 followed by a newline.

Let s1 and s2 be strings. We say that s1 is hidden in s2 if it's possible to
find each character from s1 in s2, in the same order as they appear in s1.
Also, the empty string is hidden in any string.

If the number of parameters is not 2, the program displays a newline.

Examples :

$>./hidenp "fgex.;" "tyf34gdgf;'ektufjhgdgex.;.;rtjynur6" | cat -e
1$
$>./hidenp "abc" "2altrb53c.sse" | cat -e
1$
$>./hidenp "abc" "btarc" | cat -e
0$
$>./hidenp | cat -e
$
$>
*/


#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <string.h>
#include <stdlib.h>


int ft_strlen (char *s)
{
	int d = -1;
	while(s[++d]);
	return d;
}
int ft_check(char *s1, char *s2)
{
	int i, j;
	i = j = 0;
	while(s2[j] && s1[i])
	{
		if(s1[i] == s2[j])
			i++;
		j++;
	}
	if(i == ft_strlen(s1))
		return 1;
	return 0;
}

int main (int argc, char **argv)
{
	if(argc == 3)
	{
		if(ft_check(argv[1], argv[2]) == 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
	write(1 , "\n", 1);
}
