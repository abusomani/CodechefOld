#include<iostream>
#define M 100005
using namespace std;
int gcd(int m, int n)     	
{
   int  r;                
   while (n != 0) 
   {      
      r = m % n;          
      m = n;            
      n = r;
   }                      
   return m;              
}
int main()
{
	int t,n,q,g,l,r;
	int gfwd[M];
	int gbwd[M];	int a[M];
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	cin>>t;
	while(t--)
	{
		cin>>n>>q;
		for(int i=0;i<n;i++)
			cin>>a[i];
		g = 0;
		for(int i=0;i<n;i++)
		{
			gfwd[i] = gcd(g,a[i]);
			g = gfwd[i];
		//	cout<<i<<"  :  "<<gfwd[i]<<endl;
		}
		g = 0;
		for(int i=n-1;i>=0;i--)
		{
			gbwd[i] = gcd(g,a[i]);
			g = gbwd[i];
		//	cout<<i<<"  :  "<<gbwd[i]<<endl;
		}
		while(q--)
		{
			cin>>l>>r;	l--;	r--;
			if(l==0  && r==n-1)
				cout<<gfwd[n-1]<<endl;
			else if(l==0)
				cout<<gbwd[r+1]<<endl;
			else if(r==n-1)
				cout<<gfwd[l-1]<<endl;
			else
				cout<<gcd(gfwd[l-1],gbwd[r+1])<<endl;
		}
	}
}
