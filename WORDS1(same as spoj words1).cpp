#include <bits/stdc++.h>

#define M 			 26
#define MOD          1000000007
#define INF 	     0x3f3f3f3f
#define s(x)         scanf("%d",&x)
#define p(x)         printf("%d",x)
#define sl(x)        scanf("%lld",&x)
#define pl(x)        printf("%lld",x)
#define nl           printf("\n");
#define pb			 push_back
#define mp			 make_pair
#define mset(x,val)  memset(&x,val,sizeof(x))
#define Fr           freopen("E://Test//in.txt","r",stdin);
#define Fw           freopen("E://Test//out.txt","w",stdout);
#define Frw 		 Fr	Fw

using namespace std;
typedef long long     ll;
typedef vector<int>   vi;
typedef vector<vi>	  vvi;
typedef pair<int,int> ii;
typedef vector<ii>    vii;
typedef vector<vii>   vvii;

bool mark[M+1];
bool visit[M+1];

void dfs(vvi& g , int u)
{
	visit[u] = true;
	for (int i = 0; i < g[u].size(); ++i)
	{
		if(!visit[g[u][i]])
			dfs(g , g[u][i]);
	}
}

bool is_connected(vvi& g , int s)
{
//	cout<<((char)(s + 'a'))<<endl;
	mset(visit , 0);
	dfs(g , s);
	for (int i = 0; i < M; ++i)
	{
		if(mark[i] && !visit[i])
			return false;
	}
	return true;
}

int main()
{
	int Cases;
	cin>>Cases;
	string str;
	int in[M] , out[M] , N , f , l;
	bool sc;

	while(Cases--)
	{
		scanf("%d", &N);
		mset(in , 0);
		mset(out , 0);
		mset(mark , 0);

		vvi g(M);
		vi unmtch;
		for (int i = 0; i < N; ++i)
		{
			cin>>str;	
			f = str[0] - 'a';		l = str[str.length()-1] - 'a';

			mark[f] = mark[l] = true;  
			if(f != l)
			{
				in[f]++;		out[l]++;		g[f].pb(l);
			}
		}	

		if(N == 1)
			goto yes;

		for (int i = 0; i < M; ++i)
		{
			if(in[i] != out[i])
				unmtch.push_back(i);
		}

		l = unmtch.size();
		if(l != 0 && l != 2)
		{
//			cout<<"t";
			goto no;
		}

		if(l == 2)
		{
			bool a = (in[unmtch[0]] == out[unmtch[0]] + 1) && (out[unmtch[1]] == in[unmtch[1]] + 1);
			bool b = (in[unmtch[1]] == out[unmtch[1]] + 1) && (out[unmtch[0]] == in[unmtch[0]] + 1);

			if(!a && !b)
			{
//				cout<<"u";
				goto no;
			}

			if(a)
				sc = is_connected(g , unmtch[0]);
			else
				sc = is_connected(g , unmtch[1]);
		}
		else
		{
			sc = is_connected(g , 0);
		}

		if(!sc)
		{
//			cout<<"v";
			goto no;
		}

		yes:
			printf("Ordering is possible.\n");
			continue;
		no:
			printf("The door cannot be opened.\n");
			continue;
	}	
}
