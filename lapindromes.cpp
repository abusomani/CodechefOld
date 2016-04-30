#include<stdio.h>
#include<string.h>
 
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		char inp[1005];
		int ch[256];
		int x,kk;
		for(kk=0;kk<256;kk++)
			ch[kk]=0;
		scanf("%s",&inp);
		int len=strlen(inp);
		int mid=len/2;
		int i;
		for(i=0;i<mid;i++)
		{
			ch[(int)inp[i]]++;
		}
		if(len%2==0)
		{
			for(x=i;x<len;x++)
				ch[(int)inp[x]]--;
		}
		else
		{
			for(x=i+1;x<len;x++)
				ch[(int)inp[x]]--;
		}
		for(x=0;x<256;x++)
		{
			if(ch[x]!=0)
			{
				printf("NO\n");
				goto nxt;
			}
		}
		printf("YES\n");
nxt: ;
	}
	return 0;
}
 
