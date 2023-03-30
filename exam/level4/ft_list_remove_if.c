#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if (begin_list == NULL || *begin_list == NULL)
		return;

	t_list *cur = *begin_list;

	if (cmp(cur->data, data_ref) == 0)
	{
		*begin_list = cur->next;
		free(cur);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	cur = *begin_list;
	ft_list_remove_if(&cur->next, data_ref, cmp);
}

void	print_list(t_list **begin_list)
{
	t_list *cur = *begin_list;
	while (cur != 0)
	{
		printf("%s\n", cur->data);
		cur = cur->next;
	}
}

int		main(void)
{
	char straa[] = "String aa";
	t_list *aa = malloc(sizeof(t_list));
	aa->next = 0;
	aa->data = straa;

	char strbb[] = "String bb";
	t_list *bb = malloc(sizeof(t_list));
	bb->next = 0;
	bb->data = strbb;

	char strcc[] = "String cc";
	t_list *cc = malloc(sizeof(t_list));
	cc->next = 0;
	cc->data = strcc;

	char strdd[] = "String dd";
	t_list *dd = malloc(sizeof(t_list));
	dd->next = 0;
	dd->data = strdd;

	aa->next = bb;
	bb->next = cc;
	cc->next = dd;

	t_list **begin_list = &aa;

	print_list(begin_list);
	printf("----------\n");
	ft_list_remove_if(begin_list, straa, strcmp);
	print_list(begin_list);
}



// The reason why the begin_list parameter is a double pointer t_list **begin_list in the ft_list_remove_if function is because the function is intended to modify the beginning of the list.

// In C, when you pass a pointer to a function, the function receives a copy of that pointer. Any changes made to the pointer inside the function will only affect the copy, not the original pointer in the calling function. However, if you pass a pointer to a pointer, the function can modify the original pointer because it has access to its memory address.

// In this case, the ft_list_remove_if function needs to modify the beginning of the list by setting it to the next node when the data matches the reference data. If the begin_list parameter was a single pointer, the function could not modify the original pointer in the calling function. By using a double pointer, the function can modify the original pointer and make the changes visible to the calling function.


// In C, when you pass a pointer to a function, the function receives a copy of the pointer's value, which means any modifications made to the pointer inside the function do not affect the original pointer outside the function. However, when you pass a pointer to a pointer to a function, the function receives the memory address of the original pointer, which allows it to modify the original pointer directly.

// Using double pointers to modify the original pointer outside the function is a powerful technique that allows you to create functions that modify data structures such as linked lists or trees, without having to return a modified copy of the entire data structure. It can also be used to pass multiple pointers to a function and modify them simultaneously.

// ------  Derefrence concept-------

// In C, a pointer is a variable that stores the memory address of another variable. When you want to access the value stored in the memory location pointed to by a pointer, you need to "dereference" the pointer using the unary * operator. Dereferencing a pointer gives you access to the value stored in the memory location it points to.

// When you pass a pointer to a function, the function receives a copy of the pointer's value, which means any modifications made to the pointer inside the function do not affect the original pointer outside the function. However, when you pass a pointer to a pointer to a function, you can dereference the double pointer inside the function to access the original pointer's memory location and modify it directly.

// For example, consider the following code:

// c
// Copy code
// void foo(int **ptr) {
//     *ptr = malloc(sizeof(int));
//     **ptr = 42;
// }

// int main() {
//     int *p;
//     foo(&p);
//     printf("%d\n", *p); // prints 42
//     return 0;
// }
// In this code, the foo function takes a double pointer to an integer (int **ptr) as its argument. Inside the function, the double pointer is dereferenced to modify the original pointer's memory location by allocating memory for an integer and setting its value to 42.

// When the foo function returns, the original pointer p in the main function has been modified, and its value points to the newly allocated memory location containing the value 42. The original pointer is modified indirectly by dereferencing the double pointer inside the foo function.





