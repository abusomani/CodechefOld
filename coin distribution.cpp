#include<iostream>
#include<map>
#include<stdio.h>
using namespace std;
map<long long,long long> m;
map<long long,long long>:: iterator p;
long long max(long long n)
{

	long long sum,k1,k2,k3;
	if(n<(n/2 + n/3 + n/4))
	{
			
		p=m.find(n/2);
		if(p== m.end()) 
		k1=max(n/2); 
		else 
		k1=p->second;
		p=m.find(n/3);
		if(p== m.end()) 
		k2=max(n/3); 
		else 
		k2=p->second;
		p=m.find(n/4);
		if(p== m.end()) 
		k3=max(n/4); 
		else 
		k3=p->second;
		sum=k1 + k2 + k3;
		m.insert(pair<long long,long long>(n,sum));
		return sum;  
	}
	else{  
	return n;}
}
int main()
{
	int n;
	while(1)
	{
	if (scanf("%d",&n)==-1) break;
	cout<<max(n)<<endl;}
}
	
