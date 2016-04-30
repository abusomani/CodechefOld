#include<iostream>
#include<string.h>
using namespace std;
void flip(char& c)
{
	if(c=='1')	c='0';		else	c='1';
}
int main()
{
	string str;	
	char req;
	int i,count;
	int t=1;
	while(cin>>str)
	{
		count=0;
		req='1';
		int l = str.length();
		for(int i=0;i<l;i++)
		{
			if(str[i]==req)
			{
				count++;	flip(req);
			}
		}
		cout<<"Game #"<<t<<": "<<count<<endl;	
		t++;
	}
}
