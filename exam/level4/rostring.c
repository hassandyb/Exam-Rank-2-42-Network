/*
	Subject
Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
void ft_print_first_word(char *s)
{
	int i = 0;
	while(s[i] == ' ' || s[i] == '\t')
		i++;
	while(s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}
int ft_first_word(char *s)/*tow possibilties : 1#if i have many words i will print space and the first word 2#if i have just one word i will not print space i will simply print the word!! **/
{
	int i = 0;
	int count = 0;
	while(s[i] == ' ' || s[i] == '\t')
		i++;
	while(s[i])
	{
		while(s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
			i++;
		while(s[i] == ' ' || s[i] == '\t')
			i++;
		count++;
	}
	if(count > 1)
		return 1;
	return 0;
}
int ft_confirm_space(char *s, int j)/* it help me to know if i will print a space or not case i dont have to in the end*/
{
	while(s[j] == ' ' || s[j] == '\t')
		j++;
	if(s[j] == '\0')
		return 0;
	return 1;
}
int main(int argc, char **argv)
{
	int i = 0;
	if(argc >= 2)
	{
		while(argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		while(argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i] != '\0')
			i++;
		while(argv[1][i])
		{
			while(argv[1][i] == ' ' || argv[1][i] == '\t')
				i++;
			while(argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i] != '\0')
			{
				write(1, &argv[1][i], 1);
				i++;
			}
			if(ft_confirm_space(argv[1], i) == 1)
				write(1, " ", 1);
		}
		i = 0;
		if(ft_first_word(argv[1]) == 1)
		{
			write(1, " ", 1);
			ft_print_first_word(argv[1]);
		}
		else
			ft_print_first_word(argv[1]);
	}
	write(1, "\n", 1);
}
