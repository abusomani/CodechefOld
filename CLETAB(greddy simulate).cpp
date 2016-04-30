/*
We would prefer to remove someone who doesn't places an order in future. If such customers are seated, we can remove anyone 
from them. If we remove someone who will order in future, we'll have to clean one extra table which we won't have to if we pick 
greedily.
If no such customer is present who'll NOT order in future, we'll pick a customer who will order in future in "farthest of time"
																			i.e  find the one who will order next in last
*/

#include <bits/stdc++.h>
#define M 500
using namespace std;

int n , m , c[M];
int getNext(int pos , int val)			//   at which pos it will order next
{
	for(int i = pos+1 ; i<m ; i++)
	{
		if(c[i] == val)
			return i;
	}
	return -1;
}

int main()
{
	int Cases;
	scanf("%d",&Cases);
	int cleaned , unused , minf , keep;
	set<int> st;

	while(Cases--)
	{
		scanf("%d %d",&n,&m);
		
		for(int i = 0 ; i<m ; i++)
		{
			scanf("%d",&c[i]);
		}

		unused = n;
		cleaned = 0;
		for(int i = 0 ; i<m ; i++)
		{
			if(!st.count(c[i]))
			{									//	new member
				if(unused > 0)
				{
	    			st.insert(c[i]);
					unused--;
				}
				else
				{
					minf = -1;
					for(set<int>:: iterator p = st.begin() ; p!=st.end() ; p++)
					{
						int K = getNext(i , *p);
						if(K == -1)
						{
							keep = *p;
							break;
						}
						else if(K > minf)			//	getting farthest pos where it will order
						{
							minf = K;
							keep = *p;
						}
					}
					st.erase(st.find(keep));
					st.insert(c[i]);
				}
				cleaned++;
			}
		}
		printf("%d\n",cleaned);

		st.clear();
	}	
}

