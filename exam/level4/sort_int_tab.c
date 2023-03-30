/*
	Subject
Assignment name  : sort_int_tab
Expected files   : sort_int_tab.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

void sort_int_tab(int *tab, unsigned int size);

It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.

Doubles must be preserved.

Input is always coherent.

*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// github solution :(better)

// void	sort_int_tab(int *tab, unsigned int size)
// {
// 	unsigned int	i = 0;
// 	int	temp;

// 	while (i < (size - 1))
// 	{
// 		if (tab[i] > tab[i + 1])
// 		{
// 			temp = tab[i];
// 			tab[i] = tab[i+ 1];
// 			tab[i + 1] = temp;
// 			i = 0;
// 		}
// 		else
// 			i++;
// 	}
// }



int sort_int_tab(int *tab, unsigned int size)
{
	int i = 0, temp;
	while (i < size - 1)
	{
		int j = 0;
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j + 1];
				tab[j + 1] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}





// int main ()
// {
// 	int tab[5] = {1, 5, 3, 7, 6};
// 	int i = -1;
// 	while(++i < 5)
// 		printf("%d\n", tab[i]);

// 	sort_int_tab(tab, 5);
// 	printf("------\n");
// 	i=-1;
// 	while(++i < 5)
// 		printf("%d\n", tab[i]);
// }