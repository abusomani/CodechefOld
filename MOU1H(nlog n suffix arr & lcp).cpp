#include <bits/stdc++.h>
#define MOD 1000000009
using namespace std;
typedef long long ll;

#define M 1000005
//  O(n log n) - Manber and Myers      
int a[M]; 							//	input string or number
int rank[M], pos[M]; 
int cnt[M], next[M]; 
bool bh[M], b2h[M];
  
bool smaller_first_char(int x, int y) 
{
    return a[x] < a[y];
}
  
void suffixSort(int n) 
{
    for (int i = 0; i < n; ++i) 
    {
        pos[i] = i;
    }
 
    sort(pos, pos + n, smaller_first_char);
 
    for (int i = 0; i < n; ++i) 
    {
        bh[i] = i == 0 || a[pos[i]] != a[pos[i - 1]];
        b2h[i] = false;
    }
  
    for (int h = 1; h < n; h <<= 1) 
    {
        int buckets = 0;
        for (int i = 0, j; i < n; i = j) 
        {
            j = i + 1;
            while (j < n && !bh[j])
                j++;
            next[i] = j;
            buckets++;
        }
        if (buckets == n)
            break; 

        for (int i = 0; i < n; i = next[i]) 
        {
            cnt[i] = 0;
            for (int j = i; j < next[i]; ++j) 
                rank[pos[j]] = i;
        }
  
        cnt[rank[n - h]]++;
        b2h[rank[n - h]] = true;
        for (int i = 0; i < n; i = next[i]) 
        {
            for (int j = i; j < next[i]; ++j) 
            {
                int s = pos[j] - h;
                if (s >= 0) 
                {
                    int head = rank[s];
                    rank[s] = head + cnt[head]++;
                    b2h[rank[s]] = true;
                }
            }
            for (int j = i; j < next[i]; ++j) 
            {
                int s = pos[j] - h;
                if (s >= 0 && b2h[rank[s]]) 
                {
                    for (int k = rank[s] + 1; !bh[k] && b2h[k]; k++)
                        b2h[k] = false;
                }
            }
        }
        for (int i = 0; i < n; ++i) 
        {
            pos[rank[i]] = i;
            bh[i] |= b2h[i];
        }
    }
    for (int i = 0; i < n; ++i) 
        rank[pos[i]] = i;
}
  
// O(n) - lcp - "Arrays and Its Applications" by Toru Kasai, Gunho Lee
int lcp[M];
// lcp[i] = lcp of suffix pos[i] and suffix pos[i-1]
// lcp[0] = 0
void getlcp(int n) 
{
    for (int i = 0; i < n; ++i)
        rank[pos[i]] = i;
    lcp[0] = 0;
    for (int i = 0, h = 0; i < n; ++i)
    {
        if (rank[i] > 0) 
        {
            int j = pos[rank[i] - 1];
            while (i + h < n && j + h < n && a[i + h] == a[j + h])
                h++;
            lcp[rank[i]] = h;
            if (h > 0)
                h--;
        }
    }
}

int main()
{
	int Cases;
	ll n , ans;
	scanf("%d" , &Cases);
	
	while(Cases--)
	{
		scanf("%lld" , &n);
		for(int i = 0 ; i<n ; i++)
			scanf("%d" , &a[i]);
		
		n--;
		for(int i = 0 ; i<n ; i++)
			a[i] = a[i+1] - a[i];
		ans = n*(n+1) / 2;					//	total substrings
		
		suffixSort(n);
		getlcp(n);
		for(int i = 0 ; i<n ; i++)
			ans -= lcp[i];
		
		printf("%lld\n" , ans%MOD);
	}
}
