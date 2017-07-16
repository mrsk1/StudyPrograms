#include<stdio.h>
#include<stdlib.h>

typedef struct singly {
	int data;
	struct singly *link;
} * NODE;

NODE create_node(int num)
{
	NODE tmp;
	tmp = (NODE) malloc(sizeof (struct singly)*1);
	tmp->data = num;
	tmp->link = NULL;
	return tmp;
}

NODE insert_last(NODE head, int num)
{
	NODE tmp = create_node(num);
    NODE cur = head;
	if (head == NULL)
		return tmp;
	while(cur->link != NULL){
		cur = cur->link;
	}
	cur->link = tmp;
	return head;
}

void display(NODE head)
{
	while( head != NULL){
		printf("%d\t",head->data);
		head = head->link;
	}
	printf("\n");
}
NODE reverse(NODE first)
{
	NODE cur,prev = NULL;

	while(first != NULL)
	{
		cur = first;
		first = first->link;
		cur->link = prev;
		prev = cur;
	}
	return cur;
}

NODE reverse_recur(NODE first)
{
	NODE temp = NULL;
	if(first->link == NULL)
		return first;
	temp = reverse_recur(first->link);
	first->link->link = first;
	first->link = NULL;
	return temp;
}

int main()
{
	NODE head;
	int choice;
	int num;
	for(;;)
	{
		printf("1.insert_last\n2.display\n3.reverse\n 4.reverse recurrsion \n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("enter the num to insert: ");
				scanf("%d",&num);
				head = insert_last(head, num);
				break;
			case 2:
				display(head);
				break;
			case 3:
				head = reverse(head);
				break;
			case 4:
				head = reverse_recur(head);
				break;
			case 5:
				exit(0);
				break;
		}
	}
	return 0;
}

