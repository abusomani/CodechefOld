/*
	suppose f_A[x]  shows  number of 'A' between 1 and x  ;   same for f_B & f_C then
	when we are at i , number of A , B , C between i and j are = f_A[i] - f_A[j-1] , f_B[i] - f_B[j-1] , f_C[i] - f_C[j-1]
	now for having equal number of ABC we should have
		f_A[i] - f_A[j-1] = f_B[i] - f_B[j-1] = f_C[i] - f_C[j-1]  or
		f_A[i] - f_B[i] = f_A[j-1] - f_B[j-1]   and    f_A[i] - f_C[i] = f_A[j-1] - f_C[j-1]		{	main form    }
	
	so we'll go from left to right and chk how many (f_A - f_B , f_A - f_C)  are there behind  and add them to answer
	for checking previous occurence I used map so  -  O(n log n)  
*/

#include <bits/stdc++.h>
#define M 3
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int main()
{
	string str;
	cin>>str;
	ll f[M] , ans = 0;
	map<ii , ll> mp;
	ii tmp;
	int l = str.length();
	f[0] = f[1] = f[2] = 0;

	mp[ii(0,0)] = 1;
	for (int i = 0; i < l; ++i)
	{
		f[str[i] - 'A']++;
		tmp = ii(f[0]-f[1] , f[0]-f[2]);
	
		ans = ans + (ll)(mp[tmp]);
		mp[tmp]++;	
	}

	cout<<ans<<endl;
}
