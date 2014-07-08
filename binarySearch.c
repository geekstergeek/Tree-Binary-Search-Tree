#include<stdio.h>

int binarySearch(int a,int m, int n, int key, int arr[])
{
	if(key==arr[m])
	{

			return 1;
	}
	else if(key<arr[m]&& key > arr[a])
	{	
		n=m-1;
		m=(a+n)/2;
		binarySearch(a,m,n,key,arr);
		
	}
	else if(key>arr[m]&& key<arr[n])
	{
		a=m+1;
		m=(a+n)/2;
		binarySearch(a,m,n,key,arr);
	}
	else{
		return 0;
	}
	
}

int main(){

	int arr[10]={0,1,2,2,4,5,6,7,8,9};
	int a=0, n=10;
	int m=(a+n)/2;
	int key;
	printf("Enter Key: ");
	scanf("%d",&key);
	if(binarySearch(a,m,n,key,arr)==1)
		printf("found");
	else
		printf("Not Found");
	
}
