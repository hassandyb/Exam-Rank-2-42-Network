#include <stdio.h>
#include <stdlib.h>


typedef struct s_list
{
	int data;
	struct s_list *next;
}t_list;


t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int swap;
	t_list *temp = lst;
	while(temp->next != NULL)
	{
		if(cmp(temp->data, temp->next->data) == 0)
		{
			swap = temp->data;
			temp->data = temp->next->data;
			temp->next->data = swap;
			temp = lst;
		}
		else
			temp = temp->next;
	}
	return lst;
}

int cmp(int a, int b)
{
	return (a <= b);
}

int main ()
{
	t_list *p1 = malloc(sizeof(t_list));
	t_list *p2 = malloc(sizeof(t_list));
	t_list *p3 = malloc(sizeof(t_list));
	t_list *p4 = malloc(sizeof(t_list));

	p1->data = 9;
	p2->data = 44;
	p3->data = 3;
	p3->data = 2;

	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = NULL;
	
	t_list *temp = p1;
	while(temp)
	{
		printf("%d   ", temp->data);
		temp = temp->next;
	}
	printf("\n\n  ");

	sort_list(p1, cmp);

	temp = p1;
	while(temp)
	{
		printf("%d   ", temp->data);
		temp = temp->next;
	}

}
