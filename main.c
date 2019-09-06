#include <stdio.h>
#include <stdlib.h>
#include <time.h>



struct list{
	int key;
	struct list *next;
};


struct list* add_to_list(struct list *list, int x)
{
	struct list *tmp;
	
	tmp = (struct list*) malloc(sizeof(struct list));
	
	tmp->key = x;
	tmp->next = list;
	list = tmp;
	
	return list;
	
}

void print_list(struct list *list)
{
	struct list *tmp;
	
	int i = 0;
	
	tmp = list;
	
	while(tmp != NULL)
	{
		printf("\nElement nr: %d, key = %d\n", i++, tmp->key);
		
		tmp = tmp->next;
	}
}

struct list* del_from_list(struct list *list, int x)
{
	struct list *tmp, *pom;
	
	pom = list;
	
	while (pom != NULL && pom->key != x)
	{
		tmp = pom;
		pom = pom->next;
	}
	
	if (pom != NULL)
	{
		if(pom == list)
		{
			list = pom->next;
		}
		else
		{
			tmp->next = pom->next;
		}
		
		free(pom);
	}
	else
	{
		printf("\nElement not found\n");
	}
	
	return list;
}



int main(int argc, char *argv[]) {
	int i;
	struct list *head = NULL;
	
	for (i = 0; i < 5; i++)
	{
		head = add_to_list(head, i);
	}
	
	if(head != NULL)
	{
		print_list(head);
	}
	
	del_from_list(head, 3);
	
	print_list(head);
	
	
	return 0;
}
