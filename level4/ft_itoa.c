/*
	Subject
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);
*/


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int ft_intlen(int n)
{
	int len = 0;
	if(n == 0)
		return 1;
	if(n < 0)
	{
		len++;
		n = n * (-1);
	}
	while(n > 0)
	{
		n = n / 10;
		len++;
	}
	return len;
}

char	*ft_itoa(int nbr)
{
	int len = ft_intlen(nbr);
	char *str = (char *) malloc((len + 1) * sizeof(char));
	if(str == NULL)
		return NULL;
	
	str[len] = '\0';
	if(nbr == 0)
	{
		str[0] = '0';
		return str;
	}
	if(nbr < 0)
	{
		str[0] = '-';
		nbr = nbr * (-1);
	}
	len = len - 1;
	while(nbr > 0)
	{
		str[len] = (nbr % 10) + '0';
		nbr = nbr / 10;
		len--;
	}
	return str;
}

