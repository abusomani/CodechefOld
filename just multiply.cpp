#include<bits/stdc++.h>
#include<stack>
using namespace std;
long long modpow(long long base, long long exp, long long modulus) {
  base %= modulus;
  long long result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}
int main()
{ios_base::sync_with_stdio(false);
int t;
cin>>t;
while(t--)
	{
	long long mod;
	string s;
	cin>>mod>>s;
	stack<long long>S;
	int count=0,flag=0;
		for(int i=s.size()-1;i>=0;i--)
			{
				if(s[i]!='*')
					{
					S.push(s[i]-'0');	
					}
				else
					{if(count==1)
						{
							count=0;
							
							if(flag)
								{
									long long x=S.top();
									S.pop();
									long long y=S.top();
									S.pop();
									long long result=modpow(x,y,mod);
									S.push(result);
								}
							else
								{
									long long x=S.top();
									S.pop();
									long long y=S.top();
									S.pop();
									S.push(x*y);
								}
							flag=0;
						}
					if(s[i-1]=='*')
						{	i--;
							flag=1;
							count=1;
						}
					else
						{
						flag=0;
						count=1;	
						}
					}
					
			}
		
							if(flag)
								{
									long long x=S.top();
									S.pop();
									long long y=S.top();
									S.pop();
									long long result=modpow(x,y,mod);
									S.push(result);
								}
							else
								{
									long long x=S.top();
									S.pop();
									long long y=S.top();
									S.pop();
									S.push(x*y);
								}
				cout<<S.top()<<endl;
				S.pop();
		
	}
	return 0;
}
