#include<iostream>
#include<conio.h>
#include<cstring>
#include<stdio.h>
using namespace std;


/*	int t,k,i,j,sum=0;
	char s[10];
	cin>>t>>k;
	int a[1002]={0};
	for(i=0;i<k;i++)
	{
		gets(s);
		if(strcmp("CLOSEALL",s)==0)
		{
			for(j=0;j<k;j++)  a[j]=0;  b[i]=0;   continue;
		}
		else
		{
			for(j=6;s[j];j++){
				
			sum=sum*10+(int)s[j]-48;
			  	
			
		}}
		a[sum-1]=1;
		for(j=0;j<t;j++)    if(a[j]==1)  b[j]++;
		
	}
	for(j=0;j<k;j++)  
		
	cout<<b[j]<<endl;*/
	

int main()
{

int n,k,count=0,z,i;

int a[1002]={0};
char c;

scanf("%d %d",&n,&k);

c=getchar();

while(k--)

{

    c=getchar();

    c='a';

    while((c!='\n') && (c!=' '))

    c=getchar();

    if(c==' ')

    {

        scanf("%d",&z);

        if(a[z]==0)

        {

            a[z]=1;

            count++;

        }

        else if(a[z]==1)

        {

            a[z]=0;

            count--;

        }

   }}}



