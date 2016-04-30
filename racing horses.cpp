#include <stdio.h>
#include<iostream>
#include <algorithm>
using std::sort;
using namespace std;
 

int main(){
	ios_base::sync_with_stdio(false);
	int T , N,n, m, i,j;
	cin>>T;
	while(T--){
		cin>>N;
		 m=1000000000;
		int a[N];
		for(n=0; n < N; n++) cin>>a[n];
		sort(a, a+N);
		for(n=0; n < N-1; n++){
			i = a[n], j = a[n+1];
			if(i == j){
				m = 0;
				break;
			}else if(i < j && j - i < m) m = j - i;
			else if(i > j && i - j < m) m = i - j;
		}
		printf("%d\n",m);
	}
	return 0;
}
