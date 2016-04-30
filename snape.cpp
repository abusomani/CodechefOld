#include<iostream>
#include<math.h>
using namespace std;
uint64_t comb(unsigned int n, unsigned int k) 
{ 
     if (k > n) 
         return 0; 
     uint64_t r = 1; 
     for (unsigned int d = 1; d <= k; ++d) 
     { 
         r *= n--; 
         r /= d; 
     } 
     return r; 
} 
int main()
{
     int t;
     cin>>t;
     int r,c,i,j;
     long long g,sum;
     while(t--)
     {
     	cin>>r>>c>>g;
     	while(1)
     	{
     	sum=comb(r,c);
     	for(i=r-1;i>=1;i--)
     	sum+=comb(i,i/2);
     	if(sum<g)
     	{
     	   r++;  //cout<<"hello";
     	}
     	else break;
        }
        sum=comb(r,c);
        cout<<sum<<" ";
        sum=g-sum;
        
		for(i=r-1;i>=1;i--)
        {
        	for(j=0;j<=i/2;j++)
        	{
        	sum=sum-comb(i,i/2+j); //cout<<")"<<sum<<endl;
        	if(sum<0) {  sum=sum+comb(i,i/2+j); 
        	}else break;}
        	
        		cout<<comb(i,i/2+j)<<" ";
            if(sum==0) break;
            
          
        }
        
     }
}
