/*
Subject
Assignment name  : rstr_capitalizer
Expected files   : rstr_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or more strings and, for each argument, puts
the last character that is a letter of each word in uppercase and the rest
in lowercase, then displays the result followed by a \n.

A word is a section of string delimited by spaces/tabs or the start/end of the
string. If a word has a single letter, it must be capitalized.

A letter is a character in the set [a-zA-Z]

If there are no parameters, display \n.

Examples:

$> ./rstr_capitalizer | cat -e
$
$> ./rstr_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A firsT littlE tesT$
$> ./rstr_capitalizer "SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
seconD tesT A littlE biT   moaR compleX$
   but... thiS iS noT thaT compleX$
     okay, thiS iS thE lasT 1239809147801 buT noT    thE leasT    T$
$>
*/



#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int ft_is_letter(char c)
{
	if((c >= 'a' && c<= 'z') || (c >= 'A' && c<= 'Z'))
		return 1;
	return 0;
}

void ft_to_upper(char c)
{
	if(c >= 'a' && c<= 'z')
		c = c - 32;
	write( 1, &c, 1);
}

void ft_to_lower(char c)
{
	if(c >= 'A' && c <= 'Z')
		c = c + 32;
	write(1, &c, 1);
}
int main (int argc, char **argv)
{
	int  j = 1;
	int i = 0;
	if(argc != 1)
	{
		while(argv[j])
		{
			i = 0;
			while(argv[j][i])
			{
				if(ft_is_letter(argv[j][i])== 1 && ft_is_letter(argv[j][i+1])!= 1)
					ft_to_upper(argv[j][i]);
				else
					ft_to_lower(argv[j][i]);
				i++;
			}
			write(1, "\n", 1);
			j++;
		}
	}
	write(1, "\n", 1);
}