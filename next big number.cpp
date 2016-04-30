#include<bits/stdc++.h>
using namespace std;
int main()
{int t;
cin>>t;
while(t--)
	{
		int n,i,j;
		cin>>n;
		int number[n],flag=0;
		for(i=0;i<n;i++)
			cin>>number[i];
		for(i=0;i<n;i++)
			cout<<number[i];	
		cout<<endl;
		for(i=n-1;i>0;i--)
			{if(number[i]>number[i-1])
				{ int x = number[i-1], smallest = i;
    				for (j = i+1; j < n; j++)
			        	if (number[j] > x && number[j] < number[smallest])
			            smallest = j;
				swap(number[smallest],number[i-1]);
				sort(number + i, number + n);
				for(i=0;i<n;i++)
				cout<<number[i];
				cout<<endl;
				flag=1;
				break;
				}
			}
		if(!flag)
		cout<<"NO NXTBIG"<<endl;
		
	}
	return 0;
	
}
