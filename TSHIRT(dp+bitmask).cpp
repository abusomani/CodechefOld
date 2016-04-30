#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

ll dp[1025][110];
ll DP[1025];	
bool personhas[11][110];
vector<int> tshirttakenby[110];
int ALLalloted , N;

ll solverec(int mask , int tshirtID)
{
	if(tshirtID == 101)												//	finished all tshirt
	{
		if(mask == ALLalloted)										//	all persons are alloted
			return dp[mask][tshirtID] = 1LL;		
		else
			return dp[mask][tshirtID] = 0LL;
	}	

	if(dp[mask][tshirtID] != -1)
		return dp[mask][tshirtID];

	ll ans = 0LL;
	
	ans += solverec(mask , tshirtID + 1);						//	not alloting this tshirt
	if(ans >= MOD)
		ans -= MOD;
	
	for(int i = 0; i < tshirttakenby[tshirtID].size(); ++i)
	{
		int person = tshirttakenby[tshirtID][i];
		if(!(mask & (1<<person)))									//  if person not alloted yet
			ans += solverec((mask|(1<<person)) , tshirtID +1);		//	bit_on person's bit and send new mask
		if(ans >= MOD)	
			ans -= MOD;
	}	
		
	return dp[mask][tshirtID] = ans;
}

ll solvenonrec()
{
	int nbits = ALLalloted;
	memset(DP, 0, sizeof DP);
	DP[0] = 1;													//	If no one chooses <- one way
	for(int i = 1 ; i<=100 ; ++i)
	{
		for(int mask = nbits ; mask>=0 ; --mask)
		{
			for(int j = 0 ; j<N ; ++j)	
			{
				int tmp = (1<<j);
				if(personhas[j][i] == true and (mask & tmp))
				{
					DP[mask] += DP[mask ^ tmp];				//	we add mask(currentperson) with mask^tmp(without current person)
					if(DP[mask] >= MOD) DP[mask] -= MOD;	//	because A^1 = ~A  so by ^ with tmp so that bit_off that person

				}
			}
		}
	}
	return DP[nbits];
}

int main()
{
	int Cases;
	scanf("%d" ,&Cases);
	int num;
	string str;
	
	while(Cases--)
	{
		scanf("%d" ,&N);
		ALLalloted = (1<<N) - 1;							//	All bits one () is used because '-' has more priority than << 
		getchar();
		memset(personhas , false , sizeof(personhas));
		memset(dp , -1 , sizeof(dp));
		for(int i = 0 ; i<110 ; i++)
			tshirttakenby[i].clear();

		for(int i = 0 ; i<N ; i++)
		{
			getline(cin , str);
			istringstream iss(str);
			while(iss>>num)
			{
				personhas[i][num] = true;
				tshirttakenby[num].push_back(i);
			}	
		}
		ll ansR  = solverec(0,1);							//	sending mask 0 (no one alloted) and tshirtID starts from 1
	//	ll ansNR = solvenonrec();
		printf("%lld\n", ansR);
	}	
}
