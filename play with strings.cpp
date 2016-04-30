#include<bits/stdc++.h>
using namespace std;
int check(char a[],int start,int end)
{
	while(start<=end&&a[start]==a[end])
			{
				start++;
				end--;
			}
	if(start>end)
	return 1;
	else 
	return 0;
	
}
int isPalin(char a[],int start,int end)
{
		
if(check(a,start,end)&&start!=end)
	return end;
else
	isPalin(a,start,end-1);
	
	
}
int main()
{
	int t;
	cin>>t;
	while(t--)
		{
			char a[205];
			cin>>a;
			int len=strlen(a);
			int head=0,tail,maxlength=-1,end;
			for(int i=0;i<len;i++)
				{
					tail=isPalin(a,i,len-1);
					
					
					if(tail-i+1>maxlength)
						{
							maxlength=tail+1-i;
							head=i;
							end=tail;
						}
					
				}
			for(int i=head;i<=end;i++)
			cout<<a[i];
			
			cout<<endl;
		}
	return 0;
}
