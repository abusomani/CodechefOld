/*	In this problem we need to find probability for changing one char to another char where for each a,b p is given
	so this is same problem as finding K length path between two nodes just difference is there val in matrix
	is 1 if there is an edge and here it will be probability , so we can find P^x using repeted square
	then P^x[a][b] -> probability of changing a into b after x steps
*/


#include <bits/stdc++.h>
#define L 26
#define M 1005
#define MOD 1000000007
#define to(x) (int)x - (int)'a'
using namespace std;

struct matrix
{
	double m[L][L];
	matrix operator*(matrix a)
	{
		matrix temp;
		memset(temp.m , 0 , sizeof(temp.m));
		for (int i = 0; i < L; ++i)
			for (int j = 0; j < L; ++j)
				for (int k = 0; k < L; ++k)
					temp.m[i][j] += m[i][k] * a.m[k][j];
		return temp;
	}
	void identity()
	{
		for (int i = 0; i < L; ++i)
			for (int j = 0; j < L; ++j)
				m[i][j] = (i == j);
	}
	void show()
	{
		for (int i = 0; i < L; ++i)
		{
			for (int j = 0; j < L; ++j)
				cout<<m[i][j]<<"  ";
			cout<<endl;	
		}
	}
};

matrix pow(matrix a , int exp)
{
	matrix res;
	res.identity();
	while(exp > 0)
	{
		if(exp&1)
			res = res * a;
		exp >>= 1;
		a = a*a;
	}
	return res;
}

int main()
{
	int Cases;
	scanf("%d" , &Cases);

	int N , K;
	matrix p;
	string start , str;
	double d , ans , final;
	set<string> st;
	
	while(Cases--)
	{
		scanf("%d %d" ,&N , &K);
		cin>>start;
		int l = start.length();
		
		for (int i = 0; i < 26; ++i)
		{
			for (int j = 0; j < 26; ++j)
			{
				scanf("%lf" , &d);
				p.m[i][j] = d;
			}
		}
		p = pow(p , K);
//		p.show();
		for(int i = 0; i < N; ++i)
		{
			cin>>str;
			if(str.length() == l)
				st.insert(str);
		}
		
		final = 0.0;
		for(set<string>:: iterator itr = st.begin() ; itr != st.end() ; itr++)
		{
			str = *itr;
			ans = 1.0;
			for(int i = 0 ; i<l ; i++)
			{
				ans = ans * p.m[to(start[i])][to(str[i])];
			}
			final += ans;
		}

		printf("%.9lf\n", final);
		st.clear();
	}	
}
