#include "header.h"

#define CLEARBIT(NUM,POS) (NUM = NUM & (~(1<<POS)))

int main()
{
	int num,pos;
	printf("enter the number:");
	scanf("%d",&num);
	printf("enter the position to set:");
	scanf("%d",&pos);
	printf("num = %d pos = %d \n", num, pos);
	printf("before setting:");
	showbit(num);
	num = num & (~(1<<pos));
	showbit(1<<pos);
	printf("after setting: ");
	showbit(num);
	return 0;
}
