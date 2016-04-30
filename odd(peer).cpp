#include<bits/stdc++.h>
using namespace std;
//1000 0010 
int call(int v)
{
	         // 32-bit value to find the log2 of 
register  int r; // result of log2(v) will go here
register  int shift;

r =     (v > 0xFFFF) << 4;
 v >>= r;
shift = (v > 0xFF  ) << 3; 
v >>= shift; 
r |= shift;
shift = (v > 0xF   ) << 2;
 v >>= shift; 
 r |= shift;
shift = (v > 0x3   ) << 1; 
v >>= shift; 
r |= shift;
 r |= (v >> 1);
 v=1;
return v<<r;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
		{
			int n;
			cin>>n;
			cout<<call(n)<<endl;
		}
	return 0;
}
