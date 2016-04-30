#include <bits/stdc++.h>
#define M 600020
using namespace std;
typedef long long ll;

int Z[M];
int getZarr(string s)
{
	int L , R , k;
	int l = s.length();
	L = R = 0;
	for (int i = 1; i < l ; ++i)
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
		if(i + Z[i] == l)
			return i;
	}	
	return l;
}

int main()
{
    int Cases;
    scanf("%d" , &Cases);
	string str;
    int a , b;
    
    while(Cases--)
    {
        cin>>str;
        int l = str.length();
        scanf("%d %d" , &a , &b);   
        int period = getZarr(str);

       	ll rot = 0; 
		int operation = 0;
		while(true)
        {
        	rot = rot + (ll)a;
        	operation++;
        	if(rot % period == 0)
        		break;
        	rot = rot + (ll)b;
        	operation++;
        	if(rot % period == 0)
        		break;
		}
        printf("%d\n" , operation);
    }    
}
