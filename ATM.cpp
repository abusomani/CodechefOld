#include<iostream>
#include<iomanip>
using namespace std;
int main()
{ios_base::sync_with_stdio(false);
int x;float y;
cin>>x>>y;
if(y>=x+0.5&&x%5==0)
cout<<std::fixed<<std::setprecision(2)<<y-(x+0.5);
else
cout<<std::fixed<<std::setprecision(2)<<y;
return 0;
}
