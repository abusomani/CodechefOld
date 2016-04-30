#include<bits/stdc++.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
int min(int a, int b, int c)
{
  int m = a;
  if (m > b) 
    m = b;
  if (m > c) 
    m = c;
  return m;
}

int main()
{
  int t,i,j;
  cin>>t;
  while(t--)
  {int m,n;
  cin>>m>>n;
  int M[m][n];
  for(i=0;i<m;i++)
  		{
  		  for( j=0;j<n;j++)
  		  cin>>M[i][j];
  		}
  int R=m,C=n;
  int S[R][C];
  int max_of_s, max_i, max_j; 

  for(i = 0; i < R; i++)
     S[i][0] = M[i][0];
     
  for(j = 0; j < C; j++)
     S[0][j] = M[0][j];
      
  for(i = 1; i < R; i++)
  {
    for(j = 1; j < C; j++)
    {
      if(M[i][j] == 1) 
        S[i][j] = min(S[i][j-1], S[i-1][j], S[i-1][j-1]) + 1;
      else
        S[i][j] = 0;
    }    
  } 
   

  max_of_s = S[0][0]; max_i = 0; max_j = 0;
  for(i = 0; i < R; i++)
  {
    for(j = 0; j < C; j++)
    {
      if(max_of_s < S[i][j])
      {
         max_of_s = S[i][j];
         max_i = i; 
         max_j = j;
      }        
    }                 
  }
  int count=0;
  for(i = max_i; i > max_i - max_of_s; i--)
  {count=0;
    for(j = max_j; j > max_j - max_of_s; j--)
    {
      count++;
    }  
  } 
  printf("%d\n",count);
  }
                
  
  getchar();  
}  
