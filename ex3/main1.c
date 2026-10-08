#include <stdio.h>

int main(void)
{
	int i, j;
	
	for (i = 1; i <= 6;i++)
	{
		
		for(j = 1;j <= 6 - i; j++)
	{
		printf(" "); 
	}
	
	for(j = 1;j <= i; j++)
	{
		printf("%d",i);
	}
	
	printf("\n");
}
    return 0;
}

