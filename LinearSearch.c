#include<stdio.h>



int main(int argc, char const *argv[])
{
	int key;
	int i;
	int a[10]={5,2,4,1,5,7,8,9,6,7};
	printf("enter search key\n");
	scanf("%d",&key);

	for(i=0;i<10;i++)
	{
		if(key==a[i])
		{
			printf("Found at position : %d \n",i+1);
		}
		else
		{
			
		}
	}
	return 0;
}
