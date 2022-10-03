#include <stdio.h>

int main()
{
	int a[10] = {2,5,8,1,4,7,3,10,6,9};
	int *MaxPtr, *MinPtr;
	int max=0, min=11;
	MaxPtr = &a[0];
	MinPtr = &a[0];
	for(int i=0; i<10; i++){
		if(a[i] > *MaxPtr)	MaxPtr=&a[i];
		if(a[i] < *MinPtr)	MinPtr=&a[i];
	}
	printf("Value of the item MaxPtr pointing at: %d\n", *MaxPtr);
	printf("Value of the item MinPtr pointing at: %d\n", *MinPtr);
}	
