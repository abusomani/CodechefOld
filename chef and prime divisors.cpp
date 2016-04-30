#include<bits/stdc++.h>
#include<fstream>
using namespace std;

void sieve(fstream &f,int N)
{
	int M=(N-1)/2;
	int x=(floor(sqrt(N))-1)/2,i,j;
	vector<bool> S(M+1,0);
	for(i=1;i<=x;i++)
		if(!S[i])
			for(j=2*i*(i+1);j<=M;j+=(2*i+1))
			 S[j]=1;
			 
	long long s=2;
	for(i=1;i<=M;i++)
		if(!S[i])
		 f<<2*i+1<<",";
}


long long gcd(long long a,long long b)
{
	
	if(a==0) return b;
	
	else if(b==0) return a;
	
	else return gcd(b,a%b);
}

int main()
{
	
ios_base::sync_with_stdio(false);
		 int t;
		 cin>>t;
		 while(t--)
		 	{
		 		long long a,b,hcf,y,flag=0;
		 		cin>>a>>b;
		 		if(b==1)
		 		cout<<"Yes\n";
		 		
		 		else
				 {
		 			hcf=gcd(a,b);
		 			y=b/hcf;
		 			if(hcf==1)
		 			cout<<"No\n";
		 			else{
		 				while(hcf!=1)
						{
					    if(hcf==1&&y>1) {cout<<"No\n";break;}
					 
		 				else
		 					{
		 					hcf=gcd(hcf,y);
					 		y=y/hcf;	
					 		}
						 }
						if(y==1)cout<<"Yes\n";
						else cout<<"No\n";
					 }
		 			 
				 }
	
			 }
		 return 0;
}
