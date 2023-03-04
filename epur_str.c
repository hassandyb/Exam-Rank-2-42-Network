/*Assignment name  : epur_str
Expected files   : epur_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays this string with exactly one
space between words, with no spaces or tabs either at the beginning or the end,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

If the number of arguments is not 1, or if there are no words to display, the
program displays \n.

Example:

$> ./epur_str "See? It's easy to print the same thing" | cat -e
See? It's easy to print the same thing$
$> ./epur_str " this        time it      will     be    more complex  . " | cat -e
this time it will be more complex .$
$> ./epur_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./epur_str "" | cat -e
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
				write(1, &argv[1][i],1);
				i++;
			}
			while((argv[1][i] == ' ' || argv[1][i] == '\t') && argv[1][i] != '\0')
				i++;
			if(argv[1][i] != '\0')
				write(1, " ",1);
		}
	}
	write (1, "\n", 1);
}