#include <bits/stdc++.h>
#include <sstream>
#include <algorithm>
using namespace std;
int main()
{
int t;
cin>>t;
while(t--)
{
	int n; 
	cin >> n;
	int a[n];
	stringstream ss;
	for(int i=0;i<n;i++)
		{
		cin>>a[i];
		ss<<a[i];
		}
	for(int i=0;i<n;i++)
	cout<<a[i];
	cout<<endl;
	string ans = ss.str();
	int f = next_permutation(ans.begin(), ans.end());
	if( f == 0 )
	cout << "NO NXTBIG\n";
	else
	cout<<ans<<endl;
}
return 0;

}
