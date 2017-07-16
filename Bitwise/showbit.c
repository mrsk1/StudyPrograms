#include "header.h"
void showbit(int num)
{
	int i = 0;
	for(i = ((sizeof (int)*8) -1) ; i  >=0 ; i--)
		printf("%d",(num>>i )&1);
	putchar('\n');
}

#if 0
int main()
{
	int num = 10;
	showbit(num);
}
#endif
