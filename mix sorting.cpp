#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
			char a[1000007];
			int arr[10]={0},brr[26]={0},count1=0,count2=0;
			cin>>a;
			
			int len=strlen(a);
			for(int i=0;i<len;i++)
				{
					if(a[i]>='a'&&a[i]<='z')
						{
							brr[a[i]-'a']++;
						}
					else
						arr[a[i]-'0']++;
				}
			for(int i=0;i<len;i++)
				{
					if(a[i]>='a'&&a[i]<='z')
						{
							if(brr[count2]==0)
								{
									count2++;
									char ch=brr[count2]+'a';
									cout<<ch;
									brr[count2]--;
								}
						}
							else
								{
									if(arr[count1]==0)
									{
									
									count1++;
									char ch=arr[count1]+'0';
									cout<<ch;
									brr[count1]--;
									}
								}
						}
				
			cout<<endl;
			
			
			
	}
	
	return 0;
}
