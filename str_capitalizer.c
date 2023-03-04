/*
Assignment name  : str_capitalizer
Expected files   : str_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or several strings and, for each argument,
capitalizes the first character of each word (If it's a letter, obviously),
puts the rest in lowercase, and displays the result on the standard output,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string. If a word only has one letter, it must be
capitalized.

If there are no arguments, the progam must display \n.

Example:

$> ./str_capitalizer | cat -e
$
$> ./str_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A First Little Test$
$> ./str_capitalizer "__SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
__second Test A Little Bit   Moar Complex$
   But... This Is Not That Complex$
     Okay, This Is The Last 1239809147801 But Not    The Least    T$
$>
*/


#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


int ft_is_letter(char c)
{
	if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return 1;
	return 0;
}
void ft_to_upper(char c)
{
	if(c >= 'a' && c <= 'z')
		c = c - 32;
	write(1, &c, 1);
}

void ft_to_lower(char c)
{
	if(c >= 'A' && c <= 'Z')
		c = c + 32;
	write(1, &c, 1);
}

int main (int argc, char **argv)
{
	int j = 1;
	int i;
	if(argc != 1)
	{
		while(argv[j])
		{
			i = 0;
			while(argv[j][i])
			{
				if(i == 0)
				{
					if(ft_is_letter(argv[j][0]) == 1)
						ft_to_upper(argv[j][0]);
					else
						write(1, &argv[j][0], 1);
					
				}
				else if(ft_is_letter(argv[j][i]) == 1 && ft_is_letter(argv[j][i - 1]) != 1)
					ft_to_upper(argv[j][i]);
				else
					ft_to_lower(argv[j][i]);
				i++;
				
			}
			j++;
		}
	}
	write(1, "\n", 1);
}