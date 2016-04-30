 #include<iostream>
using namespace std;
int main()
{
	int i,j,k=0,m=3,n=3,a[200]={0},b[3]={0},c[200]={0},rem,t,w,count=0;
	
	cin>>w;while(w--){
	
	
	cin>>t;  t--;
	a[0]=1;   b[0]=2;
	m=n=1;
	while(t--)
	{
		for(i=0;i<200;i++)  c[i]=0;
 	for(i=0;i<n;i++)
	{
		rem=0;
		k=i;
		for(j=m-1;j>=0;j--)
		 {
		 	c[k]=c[k]+rem+a[j]*b[i];
		 	rem=c[k]/10;
		 	c[k]%=10;
		 	k++;
	    	if(j==0)  { c[k]=rem;  }
		 }
	}if(rem!=0)   k++;
	for(i=0;i<k;i++)     a[i]=c[k-1-i];
	m=k  ;   b[0]++;  if(b[0]==10)  {  b[0]=0;  b[1]++; n=2; }   if(b[1]==10)  {  b[0]=0;  b[1]=0;  b[2]++;  n=3;  }
	}
	for(i=0;i<k;i++)  { if(c[i]==0)  count++;  else break;
	}
	cout<<count<<endl;
}
}
