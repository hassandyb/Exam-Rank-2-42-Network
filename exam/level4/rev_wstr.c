/*
	Subject
Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the
begin/end of the string.

If the number of parameters is different from 1, the program will display
'\n'.

In the parameters that are going to be tested, there won't be any "additional"
spaces (meaning that there won't be additionnal spaces at the beginning or at
the end of the string, and words will always be separated by exactly one space).

Examples:

$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
$>
*/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int ft_confirm_space(char *s, int end)
{
	int i = 0;
	while(s[i] == ' ' || s[i] == '\t')
		i++;
	while(s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
		i++;
	if(i > end)
		return 0;
	return 1;
}
int main(int argc, char **argv)
{
	int i = 0;
	int end;
	int start;
	if(argc == 2)
	{
		while(argv[1][i])
			i++;
		i--;
		while(i >= 0)
		{
			while(argv[1][i] == ' ' || argv[1][i] == '\t')
				i--;
			end = i;
			while(argv[1][i] != ' ' && argv[1][i] != '\t' && i >= 0)
				i--;
			if(i != 0)
				start = i + 1;
			else
				start = i;
			while(start <= end)
			{
				write(1, &argv[1][start], 1);
				start++;
			}
			if(ft_confirm_space(argv[1], end) == 1)
				write(1, " ", 1);
		}
	}
	write(1, "\n", 1);
}