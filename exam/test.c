#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	int data;
	struct s_list *next;
}t_list;
int	main(void)
{
	t_list *head=malloc(sizeof(t_list));
	t_list *node2=malloc(sizeof(t_list));
	t_list *node3=malloc(sizeof(t_list));
	t_list *tmp = head;
	tmp->data = 10;
	tmp->next = node2;	

	node2->data=50;
	node2->next=node3;

	node3->data=88;
	node3->next=NULL;

	while(tmp)
	{
		printf("%d ", tmp->data);
		tmp = tmp-> next;
	}
}