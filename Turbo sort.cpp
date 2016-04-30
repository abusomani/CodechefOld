#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{ios_base::sync_with_stdio(false);
int t,x;
vector<int>V;
cin>>t;
for(int i=0;i<t;i++)
{cin>>x;
V.push_back(x);
}
sort(V.begin(),V.end());
for(int i=0;i<t;i++)
cout<<V[i]<<endl;
return 0;
}
