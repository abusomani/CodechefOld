#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
void swap(int data[], int i, int j)
{
    int tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
}

int Partition(int data[], int low, int high);
void QuickSort(int data[], int low, int high)
{
    if (low >= high) return;
    
    int p = Partition(data, low, high);

    QuickSort(data, low, p-1);
    QuickSort(data, p+1, high);
}

int Partition(int data[], int low, int high)
{
    int p = low;
    for (int i = p+1; i <= high; ++i)
    {
        if (data[i] < data[p])
        {
            swap(data, i, p);
            if (i != p+1)
            {
                swap(data, i, p+1);
            }
            p = p + 1;
        }
    }

    return p;
}
int main()
{	int t;
	cin>>t;
	while(t--)
		{
		int K,Q;
		cin>>K>>Q;
		ll k[k],q[K];
		for(int i=0;i<K;i++)
		cin>>k[i];
		for(int i=0;i<K;i++)
		cin>>q[i];
		int l=0;
		QuickSort(k,0,K-1);
		QuickSort(q,0,K-1);
		for(int i=0;i<K;i++)
			for(int j=0;j<K;j++)
				arr[l++]=k[i]+q[j];
			QuickSort(arr,0,l-1);
		for(int i=0;i<Q;i++)
			{int x;
			cin>>x;
			cout<<arr[x]<<endl;
			}
		}
return 0;
}

