#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll val(ll a)
{
	return (a<0) ? 0 : a*(a+1)/2;
}

int main()
{
	int Cases;
	cin>>Cases;
	ll T1 , T2 , t1 , t2 , unf;
	double ans;
	
	while(Cases--)
	{
		scanf("%lld %lld %lld %lld", &T1,&T2,&t1,&t2);
		ans = 0;
		if(t1 == 0 and t2 == 0)
		{
			printf("%.8f\n", ans);
			continue;
		}
		
		if(t1 == 0 or t2 == 0)
		{
			if(t1 == 0)
			{
				ans = (double)T1/(T2 + t2);
				if(ans > 1)
					ans = 1;
				ans = ans*((double)t2 / T1);
			}
			else
			{
				ans = (double)T2/(T1 + t1);
				if(ans > 1)
					ans = 1;
				ans = ans*((double)t1 / T2);
			}
			if(ans > 1)
				ans = 1;
			printf("%.8f\n", ans);
			continue;
		}
		
		if(T1 > T2)
		{
			swap(T1 , T2);		swap(t1 , t2);
		}
		
		if(t1 <= t2 <= T1 <= T2)
		{
			unf = val(T1 - t2) + val(T2 - t1);
		}    
		else if(t1 <= T1 <= t2 <= T2)
		{
			unf = val(T2 - t1); 
		}  
		else if(t1 <= T1 <= T2 <= t2)
		{
			unf = val(T2 - t1);
		}      
		else if(t2 <= t1 <= T1 <= T2)
		{
			unf = val(T1 - t2) + val(T2 - t1);
		}  
		else if(t2 <= T1 <= t1 <= T2)
		{
			unf = val(T1 - t2) + val(T2 - t1);
		}  
		else if(t2 <= T1 <= T2 <= t1)
		{
			unf = val(T1 - t2) + val(T2 - t1);
		}    
		else if(T1 <= t2 <= t1 <= T2)
		{
			unf = val(T1 - t2) + val(T2 - t1);
		}  
		else if(T1 <= t2 <= T2 <= t1)
		{
			unf = val(T1 - t2) + val(T2 - t1);
		}  
		else if(T1 <= t1 <= t2 <= T2)
		{
			unf = val(T2 - t1);
		}  
		else if(T1 <= t1 <= T2 <= t2)
		{
			unf = val(T2 - t1);
		}  
		else if(T1 <= T2 <= t1 <= t2)
		{
			unf = val(T2 - t1);
		}  
		else if(T1 <= T2 <= t2 <= t1)
		{
			unf = val(T2 - t1);
		}    
//		cout<<unf<<endl;s
		ans = 1.0 - (double)unf / ((T1+1)*(T2+1));
		printf("%.8f\n", ans);
	}	
}

