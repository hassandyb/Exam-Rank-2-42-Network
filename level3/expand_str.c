/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:09:29 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/02/20 16:10:19 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : expand_str
Expected files   : expand_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it with exactly three spaces
between each word, with no spaces or tabs either at the beginning or the end,
followed by a newline.

A word is a section of string delimited either by spaces/tabs, or by the
start/end of the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:

$> ./expand_str "See? It's easy to print the same thing" | cat -e
See?   It's   easy   to   print   the   same   thing$
$> ./expand_str " this        time it      will     be    more complex  " | cat -e
this   time   it   will   be   more   complex$
$> ./expand_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./expand_str "" | cat -e
$
$>*/


#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <string.h>


int main (int argc, char **argv)
{
	int i = 0;
	if(argc == 2)
	{
		while(argv[1][i] == ' ' || argv[1][i] == '\t')
				i++;
		while(argv[1][i])
		{
			while(argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i] != '\0')
			{
				write(1, &argv[1][i], 1);
				i++;
			}
			while((argv[1][i] == ' ' || argv[1][i] == '\t' ) && argv[1][i] != '\0')
				i++;
			if(argv[1][i] != '\0')
				write(1, "   ",3);
		}
	}
	write(1, "\n", 1);
	return 0;
}