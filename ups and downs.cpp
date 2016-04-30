#include<bits/stdc++.h>
using namespace std;
int main()
	{int t;
	cin>>t;
	while(t--)
		{int n,i,k,l=0;
		cin>>n;
		int a[n];
		for(i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+i);
		if(i%2==0)
		{k=i/2;
		for(int j=0;j<n;j++)
			{if(j%2==0)
				cout<<a[l++]<<" ";
			else
				cout<<a[k++]<<" ";
			}
		}
		else
			{k=(i+1)/2;
			for(int j=0;j<n;j++)
				{if(j%2==0)
					cout<<a[l++]<<" ";
				else
					cout<<a[k++]<<" ";
				}
			}
		cout<<endl;
		}
	return 0;
	}
