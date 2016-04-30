#include <bits/stdc++.h>
#define M 3000003
#define MOD 1000000007
using namespace std;
typedef long long ll;

int N , Z[M];
void getZarr(string s)
{
	int L , R , k;
	int l = s.length();
	L = R = 0;
	for (int i = 1; i < 2*N ; ++i)
	{
		if(i > R)
		{
			L = R = i;
			while(R<l && s[R-L] == s[R])		R++;
			Z[i] = R-L;		R--;
		}
		else
		{
			k = i-L;
			if(Z[k] < R-i+1)		
				Z[i] = Z[k];
			else
			{
				L = i;
				while(R<l && s[R-L] == s[R])	 	R++;
				Z[i] = R-L;		R--;
			}
		}
	}	
}

int main()
{
	int maxv = 0 , ans = 0;
	string str1 , str2;
	scanf("%d" , &N);
	cin>>str1>>str2;

	string concat = str1 + '$' + str2 + str2;
	getZarr(concat);

	for (int i = N+1; i <= 2*N; ++i)
	{
		if(Z[i] > maxv)
		{
			maxv = Z[i];
			ans  = i;
		}
	}
	printf("%d\n", ans-N-1);
}
