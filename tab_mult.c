/*
	Subject


Assignment name  : tab_mult
Expected files   : tab_mult.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays a number's multiplication table.

The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.

If there are no parameters, the program displays \n.

Examples:

$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$>		
*/


#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
void ft_putnbr(int n)
{
	char c;
	if(n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
	}
}

int ft_atoi(char *str)
{
	int i = 0;
	int sign = 1;
	int r = 0;
	while((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
		i++;
	if(str[i] == '-' || str[i] == '+')
	{
		if(sign == '-')
			sign = -1;
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		r = (r * 10) + (str[i] - '0');
		i++;
	}
	return r * sign;
}

void ft_putstr(char *str)
{
	int j = -1;
	while(str[++j])
		write(1, &str[j], 1);
}
int main (int argc, char **argv)
{
	int i = 1;
	int r;
	if(argc == 2)
	{
		while(i <= 9)
		{
			ft_putnbr(i);
			write(1, " x ", 3);
			ft_putstr(argv[1]);
			write(1, " = ", 3);
			r = i * ft_atoi(argv[1]);
			ft_putnbr(r);
			write(1, "\n", 1);
			i++;	
		}
		return 0;
	}
	write(1, "\n", 1);
}
