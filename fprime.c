/*
	Subject
Assignment name  : fprime
Expected files   : fprime.c
Allowed functions: printf, atoi
--------------------------------------------------------------------------------

Write a program that takes a positive int and displays its prime factors on the
standard output, followed by a newline.

Factors must be displayed in ascending order and separated by '*', so that
the expression in the output gives the right result.

If the number of parameters is not 1, simply display a newline.

The input, when there is one, will be valid.

Examples:

$> ./fprime 225225 | cat -e
3*3*5*5*7*11*13$
$> ./fprime 8333325 | cat -e
3*3*5*5*7*11*13*37$
$> ./fprime 9539 | cat -e
9539$
$> ./fprime 804577 | cat -e
804577$
$> ./fprime 42 | cat -e
2*3*7$
$> ./fprime 1 | cat -e
1$
$> ./fprime | cat -e
$
$> ./fprime 42 21 | cat -e
$
*/

#include <stdio.h>
#include <stdlib.h>
                                                   
int ft_isprime(int n)
{
	int i = 2;
	while(i <= n / 2)
	{
		if(n % i == 0)
			return 0;
		i++;
	}
	return 1;
}


int ft_get_prime(int nbr)
{
	int j = 2;
	while(j <= nbr / 2)
	{
		if(nbr % j == 0 && ft_isprime(j) == 1)
			return j;
		j++;
	}
	return j;
}
int main (int argc, char **argv)
{
	if(argc == 2)
	{
		int n = atoi(argv[1]);
		if(n == 0)
		{
			printf("0\n");
			return 0;
		}
		if(n == 1)
		{
			printf("1\n");
			return 0;
		}
		while(ft_isprime(n) == 0)
		{
			int p = ft_get_prime(n);
			n = n / p;
			printf("%d*", p);
		}
		printf("%d", n);
	}
	printf("\n");
	return 0;

}