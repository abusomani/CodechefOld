#include <stdio.h>
#include <string.h>
 
int main()
{
  long long int arr[1001],max;
  int i,t,x,n;
  
  scanf("%d",&t);
 
	while(t--)
	{
		scanf("%d",&n);
		
		for(i=0;i<1001;i++)
		   arr[i]=0;
		
		
		printf("\n");
			
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			arr[x]++;
		}
		
		
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			arr[x]--;
		}
		
		max=0;
		
		for(i=1;i<1001;i++)
		{
		   arr[i]+=arr[i-1];
		   if(arr[i]>max)
				max=arr[i];
		}
		printf("%lld\n",max );
		
	}
 
  return 0;
}
