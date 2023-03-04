

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int ft_confirm_space(char *s, int j)/* it help me to know if i will print a space or not case i dont have to in the end*/
{
	int len = -1;
	while(s[++len])
		len++;
	if(j >= len)
		return 0;
	return 1;
}
int main ()
{
	printf("%d", ft_confirm_space("  		fdgfghgf 	  "));
}