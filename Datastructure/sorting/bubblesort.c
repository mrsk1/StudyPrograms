#include<stdio.h>
#include<stdlib.h>


int main()
{
	int count = 0;
	int i = 0;
	int j = 0;
	int *ptr = NULL;
	int temp = 0;

	printf("Enter the count:");
	scanf("%d",&count);
	ptr = (int *) malloc(sizeof(int) * count);
	if( ptr == NULL ){
		printf("malloc failed ");
		exit(EXIT_FAILURE);
	}
	printf("Enter the element:");
	for (i = 0; i < count ; i++){
		scanf("%d",&ptr[i]);
	}
	printf("\n");
	for (i = 0; i < count ; i++){
		printf("%d\t",ptr[i]);
	}
	printf("\n");
	
	for(i = 0 ; i < count; i++){
		for ( j = 0 ; j < count -i -1; j++){
			printf(" i = %d j = %d \n", i, j);
			if( ptr[j] > ptr[j+1]){
				temp = ptr[j];
				ptr[j] = ptr[j+1];
				ptr[j+1] = temp;
			}
		}
	}

	printf("\n");
	for (i = 0; i < count ; i++){
		printf("%d\t",ptr[i]);
	}
	printf("\n");
}
