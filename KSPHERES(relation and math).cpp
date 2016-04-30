#include <bits/stdc++.h>
#define MX 100005
#define MOD 1000000007
using namespace std;
typedef long long ll;

int a[MX], cntL[MX], cntU[MX];
ll ans[2][MX];

int main()
{
    ll N, M, C;
	int b;
	vector<int> v;
	
	cin>>N>>M>>C;
    for (int i = 0; i < N; ++i)
    {
        cin>>a[i];
        cntU[a[i]]++;
    }   

    for (int i = 0; i < M; ++i)
    {
        cin>>b;
        cntL[b]++;
    }

	set<int> st(a, a + N);
	ll K;
	for (set<int> :: iterator p = st.begin(); p != st.end(); p++)
	{
        K = ((ll)cntU[*p] * cntL[*p]) % MOD;
        if(K != 0)
            v.push_back(K);
    }
    

    ll sum = v[0];

    int f = 0;
    for (int j = 1; j < v.size(); ++j)
    {
        ans[0][j] = (v[j] * sum) % MOD;
        f = (f + ans[0][j]) % MOD;
        sum = (sum + v[j]) % MOD;
    }

	cout << f << " ";
    for (int i = 1; i < C; ++i)
    {
    	f = 0;		sum = ans[1 - i%2][i];
        for (int j = i + 1; j < v.size(); ++j)
        {
            ans[i%2][j] = (v[j] * sum) % MOD;
            f = (f + ans[i%2][j]) % MOD;
            sum = (sum + ans[1 - i%2][j]) % MOD;
//            cout << i <<"  "<<j<<"  "<< sum <<"  "<< ans[i%2][j]<<"  "<<f<<endl;
        }
        cout << f << " ";
    }
    cout << endl;
}

/*
6 7 4
1 1 1 3 5 7 
1 1 3 3 5 7 7
*/
