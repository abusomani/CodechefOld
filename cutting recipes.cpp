    #include<iostream>
    #include<stdio.h>
    #define SIZE 10005
    #include<algorithm>
     
    long long gcd(long long x, long long y)
    {
    if(y==0) return x;
    return gcd(y,x%y);
    }
    using namespace std;
     
    int main()
    {
     ios_base::sync_with_stdio(false);
    long long t;
    cin>>t;
    while(t--)
    {
    long long min = 1005	;
    long long n;
    cin>>n;
    long long a[n];
    bool ans = false;
    for(int i = 0; i < n ; i++)
    {	
    cin>>a[i];
    if(a[i] < min)
    min = a[i];
    }	
 
  long long count = 0;   
   for(int j = min; j >0 ; j--)   
	if(!ans)
    for(int i = 0; i < n ; i++)
{	
	if(a[i] %j == 0 )
  		  count ++;
	if(a[i] %j != 0 )
  		   count = 0;
	 
 
	 if(count == n)
	 	min = j,ans = true;
		 	
 }    
 
 for(int i = 0; i < n ; i++)
    	cout<<a[i]/min<<" ";
    
    cout<<endl;
   }
     
    return 0;
    }  
