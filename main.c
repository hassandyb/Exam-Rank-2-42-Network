

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


#include <stdlib.h>

typedef struct s_list t_list;

struct s_list
{
	int     data;
	t_list  *next;
};

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int	swap;
	t_list	*tmp;

	tmp = lst;
	while(lst->next != NULL)
	{
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}

int ascending(int a, int b)
{
    return (a <= b);
}

int main(void)
{
    t_list *lst = NULL;
    int data[] = {5, 2, 8, 4, 1, 9};
    int i, len = sizeof(data) / sizeof(int);
    
    for (i = 0; i < len; i++)
        push_front(&lst, data[i]);
    
    printf("Original list: ");
    print_list(lst);
    
    lst = sort_list(lst, ascending);
    
    printf("Sorted list: ");
    print_list(lst);
    
    return (0);
}
