

/*
	Subject
Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int is_white(char c)
{
	if(c == ' ' || c == '\t' || c == '\n')
		return 1;
	return 0;
}
int words_count(char *s)
{
	int j = 0;
	int i = 0;
	while(s[i])
	{
		if((is_white(s[i]) == 0 && is_white(s[i+1]) == 1) || (is_white(s[i]) == 0 && s[i+1] == '\0'))
			j++;
		i++;
	}
	return j;
}
char *ft_substr(char *s, int n, int len)
{
	int m = 0;
	char *p = (char *)malloc((len * 1) * sizeof(char));
	if(p == NULL)
		return NULL;
	while(m < len && s[n])
	{
		p[m] = s[n];
		m++;
		n++;
	}
	p[len] = '\0';
	return p;
}
char    **ft_split(char *str)
{
	int n = words_count(str);
	char **split = (char **)malloc((n + 1) * sizeof(char *));
	if(split == NULL)
		return NULL;
	int i = 0;
	int j = 0;
	int begin;
	while(str[i] && j < n)
	{
		while(is_white(str[i]) == 1)
			i++;
		begin = i;
		while(is_white(str[i]) == 0 && str[i])
			i++;
		split[j] = ft_substr(str, begin, i - begin);
		if(split[j] == NULL)
			return NULL;
		j++;
	}
	split[n] = NULL;
	return split;
}

// int main ()
// {
// 	char **t = ft_split(NULL);
// 	int i = -1;
// 	while(t[++i])
// 		printf("%s\n", t[i]);
// }

