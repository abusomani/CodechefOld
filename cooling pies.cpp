#include<iostream>
#include<algorithm>
using namespace std;
int main()
{ios_base::sync_with_stdio(false);
int t;
cin>>t;
while(t--)
  {int n,a[100],b[100],i,j;
    cin>>n;
    for(i=0;i<n;i++)
       cin>>a[i];
sort(a,a+n);
      for( j=0;j<n;j++)
       cin>>b[j];
sort(b,b+n);
int count=0;
i=0;j=0;
while(i<n&&j<n)
   {if(a[i]<=b[j])
       {i++;j++;count++;
        }
    else
     j++;
    }
cout<<count<<endl;

   }
return 0;
}
