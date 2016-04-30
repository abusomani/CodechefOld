#include<bits/stdc++.h>
using namespace std;
void printSubStr( char* str, int low, int high )
{
    for( int i = low; i <= high; ++i )
        printf("%c", str[i]);
}
void longestPalSubstr( char *str )
{
    int n = strlen( str ); 
 
 
    bool table[n][n];
    memset(table, 0, sizeof(table));
 
    int maxLength = 1;
    for (int i = 0; i < n; ++i)
        table[i][i] = true;
 
    
    int start = 0;
    for (int i = 0; i < n-1; ++i)
    {
        if (str[i] == str[i+1])
        {
            table[i][i+1] = true;
            start = i;
            maxLength = 2;
        }
    }
 
    for (int k = 3; k <= n; ++k)
    {
       
        for (int i = 0; i < n-k+1 ; ++i)
        {
            
            int j = i + k - 1;
 
            
            if (table[i+1][j-1] && str[i] == str[j])
            {
                table[i][j] = true;
 
                if (k > maxLength)
                {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }
 
   
    printSubStr( str, start, start + maxLength - 1 );
 
}

int main()
{
		int t;
	cin>>t;
	while(t--)
		{
			char a[205];
			cin>>a;
			longestPalSubstr(a);
			cout<<endl;
		}
	return 0;
}
