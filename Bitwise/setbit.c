#include "header.h"

#define SETBIT(NUM,POS) (NUM = NUM | (1<<POS))

int main()
{
	int num,pos;
	printf("enter the number:");
	scanf("%d",&num);
	printf("enter the position to set:");
	scanf("%d",&pos);
	printf("num = %d pos = %d \n", num, pos);
	printf("before setting:");
	showbit((unsigned int)num);
	//num = num | (1<<pos);
	SETBIT(num,pos);
	showbit(1<<pos);
	printf("after setting: ");
	showbit(num);
	return 0;
}
