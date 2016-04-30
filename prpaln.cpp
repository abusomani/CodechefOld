#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
 
long long checkPalindrome(string s,long long i,long long j,long long &error1,long long &error2){
	while(i<=j)
		if(s[i++]!=s[j--]){
			error1=i-1;
			error2=j+1;
			return 0;
		}
	return 1;
}
 
int main(){
	int t;
	scanf("%d",&t);
	string s;
	while(t--){
		cin>>s;
		long long size=s.size();
		long long p=0,error1,error2;	//p number of errors
		long long i=checkPalindrome(s,0,size-1,error1,error2);
 
		if(i==1)		//if palindrome
			printf("YES\n");
 
		else{		//not palindrome
			if(s[error1]==s[error2-1]){
				long long x,y;
				long long j=checkPalindrome(s,error1,error2-1,x,y);
				if(j==1)
					printf("YES\n");
				else
					printf("NO\n");
			}
 
 
			else if(s[error1+1]==s[error2]){
				long long x,y;
				long long j=checkPalindrome(s,error1+1,error2,x,y);
				if(j==1)
					printf("YES\n");
				else
					printf("NO\n");
			}
 
 
			else
				printf("NO\n");
		}	
	}
return 0;
}	
