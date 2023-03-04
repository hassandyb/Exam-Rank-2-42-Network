/*Assignment name  : wdmatch
Expected files   : wdmatch.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and checks whether it's possible to
write the first string with characters from the second string, while respecting
the order in which these characters appear in the second string.

If it's possible, the program displays the string, followed by a \n, otherwise
it simply displays a \n.

If the number of arguments is not 2, the program displays a \n.

Examples:

$>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
faya$
$>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
$
$>./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e
quarante deux$
$>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
$
$>./wdmatch | cat -e
$*/




#include <unistd.h>
#include <string.h>
#include <string.h>





void  ft_putstr(char *str)
{
	int k = 0;
	while(str[k])
	{
		write(1, &str[k],1);
		k++;
	}
}
int ft_strlen(char *s)
{
	int m = 0;
	while(s[m])
		m++;
	return m;
}

int ft_check(char *str1, char *str2)
{
	int x = 0;
	int y = 0;
	while(str2[x] && str1[y])
	{
		if(str2[x] == str1[y])
			y++;
		x++;
	}
	if(y == ft_strlen(str1))
		return 1;
	return 0;
}


int main (int argc, char **argv)
{
	int i = 0;
	
	if(argc == 3)
	{
		if(ft_check(argv[1], argv[2]) == 1 )
		{
			ft_putstr(argv[1]);
		}
	}
	write(1, "\n", 1);
}