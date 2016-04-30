#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
void print(const string& item)
{
    cout << item << endl;
}

int main()
{int t;
cin>>t;
while  (t--)
{
	
int n;
cin>>n;
    set<string> sortedItems;

    for(int i = 1; i <= n; ++i)
    {
        string name;
        
        cin >> name;

        sortedItems.insert(name);
    }

    for_each(sortedItems.begin(), sortedItems.end(), &print);
}
    return 0;
}
