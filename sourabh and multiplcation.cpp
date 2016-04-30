#include<bits/stdc++.h>
using namespace std;
long long answer(long long n,long long k)
{
	long long a[20]={0},ans=0;
	int var,count=0;
	while(n!=0)
		{
			var=n%10;
			n/=10;
				if(var==k)
					{
						a[count++]=var+k;
					}
				else
					a[count++]=var*k;
		}
	int carry=0,i=0;
	while(i<count)
		{
			
			a[i]=a[i]+carry;
			carry=a[i]/10;
			a[i]=a[i]%10;
			i++;
		}
	if(carry)
		a[i]=carry;
	else
		i--;
	for(int j=i;j>=0;j--)
		ans=ans*10+a[j];
	return ans;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
		{
		long long n,k,sum=0;
		cin>>n>>k;
		sum=n*k;
		sum+=answer(n,k);
		cout<<sum<<endl;
		}
	return 0;
}
