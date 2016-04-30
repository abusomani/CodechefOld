#include <iostream>
using namespace std;
 
int main(void) {
	
	int test;
	cin>>test;
	
	while(test--)
	{
		int arr[105]={0};
		int N,i,j,count1=0,count2=0;
		
		cin>>N;
		for(i=1;i<=N;i++)
		{
			cin>>arr[i];
		}
		
		for(i=2;i<=N;i++)
		{
			for(j=1;j<i;j++)
			{
				if(arr[j] > arr[i])
				{
					count1++;
				}
			}
		}
		
		for(i=1;i<=N;i++)
		{
			if(arr[i] > arr[i+1])
			{
				count2++;
			}
		}
		
		count2=count2-1;
		
		if(count1 == count2)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	
	}
	return 0;
}
