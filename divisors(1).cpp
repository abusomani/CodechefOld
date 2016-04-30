#include<iostream>
#include<math.h>
#include<stack>
using namespace std;
void prime(long long n)
{	long long count=0,x=n;
	stack<long long>S;
    while (n%2 == 0)
    {	count++;
    	S.push(2);
        
        n = n/2;
    }
    for ( int i = 3; i <= sqrt(x); i = i++)
    {
        
        while (n%i == 0)
        {
            count++;
			S.push(i);
            n = n/i;
        }
    }
    cout<<count<<endl;
 	while(!S.empty())
 	{
 	cout<<S.top()<<endl;
 	S.pop();
 	}
 	

}
int main()
{long long x;
int t;
cin>>t;
while(t--)
{cin>>x;
prime(x);
}
return 0;
}
