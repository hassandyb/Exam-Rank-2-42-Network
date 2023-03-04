#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <string.h>

/*
Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>
*/

int ft_atoi (char *s)
{
	int signal = 1;
	int f = 0;
	int n = 0;
	while((s[f] >= 9 && s[f] <= 13) || s[f] == 32)
		f++;
	if(s[f] == '-' || s[f] == '+')
	{
		if(s[f] == '-')
			signal = -1;
		f++;
	}
	while(s[f] >= '0' && s[f] <= '9')
	{
		n = (n * 10) + (s[f] - '0');
		f++;
	}
	return(n * signal);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}
void ft_putnbr(int nbr)
{
	char c;
	if(nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		c = (nbr % 10) + '0';
		write(1, &c, 1);
	}
	else// in the last nbr will be < 10 so we will simply print it - and n
	{
		c = nbr + '0';
		write(1, &c, 1);
	}

}
int ft_isprime(int n)
{
	if(n == 0 || n == 1)
		return 0;
	int i = 2;
	while(i <= (n/2))
	{
		if(n % i == 0)
			return 0;
		i++;
	}
	return 1;
}




int main (int argc, char **argv)
{
	int i = 0;
	int n;
	if(argc == 2)
		n = ft_atoi(argv[1]);
	int total = 0;
	if(argc == 2 && n >= 2)
	{
			while(i <= n)
		{
			if(ft_isprime(i) == 1)
				total = total + i;
			i++;
		}
	}
	ft_putnbr(total);
	write(1, "\n", 1);
	return 0;
}