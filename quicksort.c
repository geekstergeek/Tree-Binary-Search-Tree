#include<stdio.h>
#define MAX 100


void quicksort(int arr[], int n)
{
	int piv;
	int beg[MAX],end[MAX],i=0, L, R, swap;
	beg[0]=0;
	end[0]=n;
	
	while(i>=0){
		
		L=beg[i];
		R=end[i]-1;
		if(L<R){
		
			piv=arr[L];
			while(L<R)
			{
				while(arr[R]>=piv && L<R) R--;
					if(L<R) arr[L++]=arr[R];
				while(arr[L]<=piv && L<R) L++;
					if(L<R) arr[R--] = arr[L];
			}

			arr[L]=piv;
			beg[i+1]=L+1;
			end[i+1]=end[i];
			end[i++]=L;

			if(end[i]-beg[i] > end[i-1] -beg[i-1])
			{	
			
				swap = beg[i];
				beg[i]=beg[i-1];
				beg[i-1]=swap;
				swap= end[i];
				end[i]=end[i-1];
				end[i-1]=swap;
			}
		
		}
		
		else{
			i--;
		}	
	}
}




int main(){

int arr[9]={2,5,4,3,1,6,8,7,12};
int i;
quicksort(arr,9);

for(i=0; i<9;i++)
	printf("%d\n",arr[i]);
}

