#include<stdio.h>
#include<queue>
using namespace std;
int main()
{
	int t,val,ch,size,x;
	size = 0;
	scanf("%d",&t);
	priority_queue<int> maxh,minh;					// by default pri_queue is max heap , so using as minh put -ve values
	while(t--)
	{
		scanf("%d",&ch);
		if(ch==1)
		{
			scanf("%d",&val);
			if(minh.size()==0 || val >= -minh.top())		minh.push(-val);
			else											maxh.push(val);
			size++;
			while(minh.size() > size/3)
			{
				x = minh.top();		minh.pop();
				maxh.push(-x);
			}
			while(minh.size() < size/3)
			{
				x = -maxh.top();		maxh.top();
				minh.push(x);
			}
		}
		else
		{
				if(size / 3 == 0) 	printf("No reviews yet\n");
    		    else            	printf("%d\n", -minh.top());
		}
	}
	return 0;
}
