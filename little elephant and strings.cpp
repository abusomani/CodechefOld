#include<bits/stdc++.h>
using namespace std;
int main()
	{int n,k,j;
	cin>>k>>n;
		char a[53][53],b[53][53];
		for(int i=0;i<k;i++)
		cin>>a[i];
		for(int i=0;i<n;i++)
		cin>>b[i];
		for(int i=0;i<n;i++)
			{int len=strlen(b[i]);
				if(len>=47)
					{
					cout<<"Good\n";
					continue;
					}
				else
					{for(j=0;j<k;j++)
						{if(strstr(b[i],a[j]))
							{cout<<"Good\n";
							break;
							}
						}
					if(j==k)
						{cout<<"Bad\n";
						continue;
						}
					}
			}
		return 0;
	}
