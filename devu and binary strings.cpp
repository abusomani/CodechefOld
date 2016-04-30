#include<bits/stdc++.h>
using namespace std;
char flip(char c)
{
	if(c=='1')
	return '0';
	else
	return '1';
}
void change(char a[],int start,int end,int k,int changes)
{int total=end-start+1;
	if(total%(k+1)==0)
		{
			a[start+k-1]=flip(a[start+k-1]);
			changes--;
			int loc=start+k;
			while(changes&&loc<end)
				{
					a[loc+k]=flip(a[loc+k]);
					loc=loc+k+1;
					changes--;
				}
		}
	else
		{
			while(changes&&start<end)
			{
				a[start+k]=flip(a[start+k]);
				start=start+k+1;
				changes--;
			}
		}
}
int main()
{ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	char b[100005],c[100005],one='1',zero='0';
	for(int i=0;i<100005;i++)
				{
					if(i%2==0)
						{
							b[i]=one;
							c[i]=zero;
						}
					else
						{
							b[i]=zero;
							c[i]=one;
						}
				}
	while(t--)	
		{
			int n,k;
			cin>>n>>k;
			char a[n+1];
			cin>>a;
			if(k==1)
				{int min=0,min1=0;
					for(int i=0;i<n;i++)
						{
							if(a[i]!=b[i])min++;
							if(a[i]!=c[i])min1++;
							
						}
					if(min<=min1)
						{
							cout<<min<<endl;
							for(int i=0;i<n;i++)cout<<b[i];
							cout<<endl;
						}
					else
						{
							cout<<min1<<endl;
							for(int i=0;i<n;i++)cout<<c[i];
							cout<<endl;
						}
				}
			else
				{
					int start=0,len=1,j=0,count=0;
					while(j<n-1)
					{
						if(a[j]==a[j+1])
							{
								len++;
							
							}
						else{
							if(len>k)
								{
									count+=len/(k+1);
									change(a,start,j,k,len/(k+1));
								}
							len=1;
							start=j+1;
							}
						j++;
				}
				if(len>k) 
								{
									count+=len/(k+1);
									change(a,start,j,k,len/(k+1));
								}
			cout<<count<<endl;
			for(int i=0;i<n;i++)
				cout<<a[i];
				cout<<endl;		
			}
		}
	return 0;
}
