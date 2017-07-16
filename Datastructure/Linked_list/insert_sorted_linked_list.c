/** program to insert element in a sorted singly lineked list **/
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
NODE insert_node(NODE head, int key)
{
	NODE tmp = create_node(key);
	NODE cur = head;
	if(head == NULL){
		return tmp;	
	}
	if( head->data > key){
		tmp->link = head;
		return tmp;
	}
	while( cur->data < key && cur->link != NULL){
		cur = cur->link;
	}
	if(cur->link == NULL){
		cur->link = tmp;
		return head;
	}
	tmp->link = cur->link;
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

int main()
{
	NODE head;
	int choice;
	int num;
	for(;;)
	{
		printf("1.insert_node\n2.display\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("enter the num to insert: ");
				scanf("%d",&num);
				head = insert_node(head, num);
				break;
			case 2:
				display(head);
				break;
		}
	}
	return 0;
}

