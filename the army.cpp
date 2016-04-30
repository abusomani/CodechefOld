#include <iostream>
#include<algorithm>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
		int a[100007]={0},b[100007]={0},i=0,j=0;
        int n,m,mini=100007,maxi=-1;
		cin>>n>>m;
 
		for(i=0;i<m;i++)
		{
			cin>>b[i];
		}
 
        for(i=0;i<m;i++)
		{
			if(b[i]<mini)
                mini=b[i];
 
            if(b[i]>maxi)
                maxi=b[i];
		}
 
        for(i=0;i<n;i++)
		{
			a[i]=max(abs(i-mini),abs(i-maxi));
		}
 
 
 
		for(i=0;i<n-1;i++)
			cout<<a[i]<<" ";
 
		cout<<a[n-1]<<endl;
 
	}
    return 0;
}
