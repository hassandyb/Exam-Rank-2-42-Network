/*
	Subject
Assignment name  : ft_list_foreach
Expected files   : ft_list_foreach.c, ft_list.h
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a list and a function pointer, and applies this
function to each element of the list.

It must be declared as follows:

void    ft_list_foreach(t_list *begin_list, void (*f)(void *));

The function pointed to by f will be used as follows:

(*f)(list_ptr->data);

You must use the following structure, and turn it in as a file called
ft_list.h:

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;



void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list *tmp;

	tmp = begin_list;
	while (tmp)
	{
		f(tmp->data);
		tmp = tmp->next;
	}
}
void function (void *x)
{
	char *str = (char *)x;
	for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = str[i] + 1;
    }
}

int main ()
{
	t_list	t1, t2, t3, t4, t5;

	
	t1.data = strdup("abc");
	t2.data = strdup("abc");
	t3.data = strdup("abc");
	t4.data = strdup("abc");
	t5.data = strdup("abc");



	t1.next = &t2;
	t2.next = &t3;
	t3.next = &t4;
	t4.next = &t5;
	t5.next = NULL;
	
	// t_list *begin = &t1;
	ft_list_foreach(&t1, &function);
	printf("%s", t1.data);
	// while(begin != NULL)
	// {
	// 	printf("%s\n", begin->data);
	// 	begin = begin->next;
	// }

}






//--------------------------------------------------------
// #include <stdio.h>
// #include <stdlib.h>

// typedef struct s_list
// {
//     struct s_list *next;
//     void *data;
// } t_list;

// void ft_list_foreach(t_list *begin_list, void (*f)(void *))
// {
//     while (begin_list != NULL)
//     {
//         (*f)(begin_list->data);
//         begin_list = begin_list->next;
//     }
// }

// void print_data(void *data)
// {
//     printf("%s\n", (char *)data);
// }

// int main()
// {
//     t_list *list = malloc(sizeof(t_list));
//     list->data = "Hello";
//     list->next = malloc(sizeof(t_list));
//     list->next->data = "World";
//     list->next->next = NULL;

//     ft_list_foreach(list, &print_data);

//     return 0;
// }
// ##############################
// #include <stdio.h>
// #include "ft_list.h"

// void	print_int(void *data)
// {
// 	int *int_ptr;

// 	int_ptr = (int *)data;
// 	printf("%d\n", *int_ptr);
// }

// int	main(void)
// {
// 	t_list	*list;
// 	int		data1 = 42;
// 	int		data2 = 1337;
// 	int		data3 = -1;

// 	// Create the list
// 	list = malloc(sizeof(t_list));
// 	list->data = &data1;
// 	list->next = malloc(sizeof(t_list));
// 	list->next->data = &data2;
// 	list->next->next = malloc(sizeof(t_list));
// 	list->next->next->data = &data3;
// 	list->next->next->next = NULL;

// 	// Apply the print_int function to each element of the list
// 	ft_list_foreach(list, &print_int);

// 	// Free the memory used by the list
// 	free(list->next->next);
// 	free(list->next);
// 	free(list);

// 	return (0);
// }
