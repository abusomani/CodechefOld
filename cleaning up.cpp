#include<iostream>
using namespace std;
 
int main()
{
    int n,m,i,t,j,k,l;
    int b[1000]={0},a[1000]={0};
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=1;i<=m;i++)
        cin>>b[i];
        for(i=1;i<=n;i++)
        a[i]=i;
        for(i=1;i<=m;i++)
            for(j=1;j<=n;j++)
            {
                if(b[i]==a[j])
                {
                    for(l=j;l<n;l++)
                    {
                        a[l]=a[l+1];
                    }
 
                }
            }
        for(i=1;i<=n-m;i++)
        {
            if(i%2!=0)
            cout<<a[i]<<" ";
        }
        cout<<endl;
        for(i=1;i<=n-m;i++)
        {
            if(i%2==0)
            cout<<a[i]<<" ";
        }
        cout<<endl;
 
    }
    return 0;
}
