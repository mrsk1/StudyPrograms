#include "header.h"

#define SWAPBIT(NUM,POS1,POS2) ( ((NUM>>POS1) &1)!= ((NUM>>POS2)&1)? (NUM^=(1<<POS1 | 1<<POS2)):POS1)

int main()
{
	int num, pos1, pos2;
	int temp1,temp2;
	printf("enter the number:");
	scanf("%d",&num);
	printf("enter the position1:");
	scanf("%d",&pos1);
	printf("enter the position2:");
	scanf("%d",&pos2);
	printf("num = %d pos1 = %d pos2 = %d \n", num, pos1, pos2);
	printf("before setting:");
	showbit(num);
#if 0
    temp1 = (num >> pos1)&1	;
    temp2 = (num >> pos2)&1	;
	if( temp1 != temp2)
		num = num ^( 1<<pos1 | 1<<pos2);
#endif
	printf("after setting: ");
	SWAPBIT(num,pos1,pos2);
	showbit(num);
	return 0;
}
