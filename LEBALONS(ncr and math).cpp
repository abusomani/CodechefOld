/*  Details -     LEBALONS   based on combinatorics and maths */
#include <bits/stdc++.h>
using namespace std;
#define M 42
typedef long long ll; 
int c[M];

ll Cr(int n , int r)
{
	ll ans = 1;
	if(r > n-r)		r = n-r;
	for(int i = 0 ; i<r ; i++)
	{
		ans = (ans*(n-i))/(i+1);
	}
	return ans;
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    freopen("E://temp.txt" , "r" , stdin);
    
	int Case;
 	cin>>Case;
 	int a , n , k;
 	ll two[M] , t , sum , total;
 	ll C[M][M];
 	
 	for(int i=0 ; i<M ; i++)
 		C[0][i] = 1,
 		C[i][0] = 1;
 		
 	for(int i=1 ; i<M ; i++)
	{   
		C[i][1]=i;   C[i][i]=1;  
	}
	
 	for(int i = 2 ; i<M ; i++)
 	{
 		for(int j = 2 ; j<M ; j++)
 		{
 			C[i][j] = C[i-1][j] + C[i-1][j-1];
 		}
 	}
 	
 	t = 1;
 	for(int i = 0; i<M ; i++)
 	{
 		two[i] = t;
 		t = t<<1;
 	}
 		
    while(Case--)
    {
    	sum = 0;
    	cin>>n>>k;
    	
		for(int i = 0 ; i<n ; i++)
    	{
    		cin>>a>>c[i];
    		sum += c[i];
    	}
    	
//    	cout<<sum<<endl;
		if(k==0)
		{
			printf("%.8f\n",(double)(two[n-1]*sum)/(two[n]));
			continue;		
		}
		
    	total = two[n-1]*sum;    	
		ll term = 0;
    	for(int i = 1; i<k ; i++)
    	{
    		total -= C[n-1][i-1]*(sum);
    		term += C[n][i];
    	}
    	
    	term = two[n] - term - 1;
    	cout<<total<<"  "<<term<<endl;
    	
		printf("%.8f\n", ((double)total / term));
    }
}
