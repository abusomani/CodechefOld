#include<bits/stdc++.h>
using namespace std;
int main()
{
		int n,neg=0;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
			{
				cin>>a[i];
				if(a[i]<0)
				neg++;
				
			}
		sort(a,a+n);

		if(neg==0)
			{
				cout<<a[0];
			}
		else
			{
				if(n%2==0)
					{long long product=1;
						for(int i=0;i<neg-1;i++)
							product*=a[i];
						cout<<product;
					}
				else
					{long long product=1;
						for(int i=0;i<neg;i++)
							product*=a[i];
						cout<<product;
					}
						
					}
			
	
	return 0;
}
