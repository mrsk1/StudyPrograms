#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
   int data;
   struct node *prev;
   struct node *next;
} * DNODE;

DNODE getnode(int num)
{
   DNODE tmp;
   tmp = (DNODE) malloc(sizeof(struct node) * 1);
   tmp->prev = NULL;
   tmp->next = NULL;
   tmp->data = num;
}

DNODE  insert_front(DNODE first, int num)
{
   DNODE tmp = getnode(num);
   if (first == NULL){
      first = tmp;
      return tmp;
   }
   tmp->next = first;
   first->prev = tmp;
   first = tmp;
   return first;
}
DNODE  insert_last(DNODE first, int num)
{
   DNODE tmp = getnode(num);
   DNODE cur = first;
   if (first == NULL){
      first = tmp;
      return tmp;
   }
   while(cur->next != NULL)
      cur = cur->next;

   cur->next = tmp;
   tmp->prev = cur;
   return first;
}
DNODE reverse(DNODE first)
{
	DNODE p1,p2;
	p1 = first;
	p2 = p1->next;
	p1->next = NULL;
	while(p2 != NULL){
		p2->prev = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p2->prev;
	}
	first = p1;
	return  p1;
}
DNODE insert_pos();
DNODE delete_first();
DNODE delete_last();
DNODE reverse_list();

void display(DNODE first)
{
   while(first != NULL){
      printf("%d\t",first->data);
      first = first->next;
   }
   printf("\n");
}

int main()
{
   int choice;
   DNODE first;
   int num;
   while(1){
      printf("1.insert_front 2.display\n");
      printf("3.insert_end 4.reverse\n");
      scanf("%d",&choice);
      switch(choice){
         case 1:
            printf("enter the num ");
            scanf("%d",&num);
            first = insert_front (first,num);
            break;
         case 2:
            display(first);
            break;
         case 3:
            printf("enter the num ");
            scanf("%d",&num);
            first = insert_last (first,num);
            display(first);
            break;
		case 4:
			first = reverse(first);
            display(first);
			break;
      }
   }
}

