#include <bits/stdc++.h>
#define M 1010
#define MOD 23102009
using namespace std;
typedef long long ll;

int LCS[M][M] , dp[M][M];
string str1 , str2;

int distinct(int i , int j)
{
    if(i<=0 || j<=0)
        return 1;
    int& ret = dp[i][j];
    if(ret != -1)
        return ret;

    ret = 0;
    if(str1[i-1] == str2[j-1])
        ret = distinct(i-1 , j-1);
    else									//	
    {
        if(LCS[i][j] == LCS[i-1][j])
            ret += distinct(i-1 , j);
        if(LCS[i][j] == LCS[i][j-1])
            ret += distinct(i , j-1);
//        if(LCS[i][j] == LCS[i-1][j-1])		//	we have to subtract once otherwise it is overcounted twice
//            ret -= distinct(i-1 , j-1);
    }
    return (ret + MOD) % MOD;				//	thing to remmember , as we are subtracting above line:28  so we have to add MOD
}

int main()
{
    int Cases;
    scanf("%d" , &Cases);
	getchar();
    int N;
    while(Cases--)
    {
        cin>>str1>>str2;
        int lenS = str1.length();
        int lenT = str2.length();
        memset(LCS , 0 , sizeof(LCS));
        memset(dp , -1 , sizeof(dp));

        for (int i = 1; i <= lenS; ++i)
        {
            for (int j = 1; j <= lenT; ++j)
            {
                if(str1[i-1] == str2[j-1])
                    LCS[i][j] = LCS[i-1][j-1] + 1;
                else
                    LCS[i][j] = max(LCS[i-1][j] , LCS[i][j-1]);
            }
        }

//        for (int i = 1; i <= lenS; ++i)
//        {
//            for (int j = 1; j <= lenT; ++j)
//            {
//                cout<<LCS[i][j]<<"  ";
//            }
//            cout<<endl;
//        }
        
        printf("%d %d\n" , LCS[lenS][lenT] , distinct(lenS , lenT));
    }    
}
