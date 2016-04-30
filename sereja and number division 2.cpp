#include<bits/stdc++.h>
 
#include<stdio.h>

 
using namespace std;
 
int main()
 
{
 
int t;
 
cin>>t;
 
while(t--)
{string a;
   int n;
cin>>a;
int len=a.size();
int arr[10]={0};
for(int i=0;i<len;i++)
	arr[(a[i]-'0')]++;
cin>>n;
int b[n];
for(int i=0;i<n;i++)
cin>>b[i];
for(int i=9;i>=0;i--)
	{while(arr[i]--)
		cout<<i;
	}
cout<<endl;
}
 
	return 0;
}
 

