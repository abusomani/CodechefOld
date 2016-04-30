#include <bits/stdc++.h>
#define M 100
#define MOD 1000000007
using namespace std;
typedef long long ll;

bool is_prime(int N)
{
	if(N == 2 || N == 17)		return false;
	if(N%2 == 0)				return false;       
	for (int i = 3; i*i <= N; i+=2)
	{
		if(N%i == 0)
			return false;
	}
	return true;
}

int main()
{
	//win[16] = win[34] = win[289] = 0;
	int Cases , N;
	scanf("%d" , &Cases);
	while(Cases--)
	{
		scanf("%d" , &N);
		if(is_prime(N) || N == 16 || N == 34 || N == 289)
			printf("Tom\n");
		else
			printf("Mike\n");
	}
}
