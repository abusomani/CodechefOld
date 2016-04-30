#include<bits/stdc++.h>

using namespace std;

int main()

{

int n,x,y,a[100005],b[100005],diff[100005],sum=0,tmp=0,ans=-1000000000,i;

scanf("%d %d %d",&n,&x,&y);

for(i=0;i<n;i++)

{

scanf("%d",a+i);

}

for(i=0;i<n;i++)

{

scanf("%d",b+i);

diff[i]=a[i]-b[i];

sum+=b[i];

}

sort(diff,diff+n);

reverse(diff,diff+n);

for(i=0;i<x;i++)

{

tmp+=diff[i];

if(n-(i+1)<=y)

{

ans=max(ans,sum+tmp);

}

}

printf("%d\n",ans);

}
