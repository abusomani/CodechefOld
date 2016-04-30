 #include<iostream>
 using namespace std;
 int n,c,flag=0;
 int max(int* node,int l)
 {
 	int sum=0,a,b;
 	if(l==2)
 	{
 		if(*(node+n)>*(node+n+1))
 		return  (*node + *(node+n));
 		else return  (*node + *(node+n+1));
 	}
 	else
 	{
 		if(flag)
 	{	a=c;     flag=0;}  
 		else 
 	{	a=max(node+n,l-1);
 		b=max(node+n+1,l-1);
 		c=b;    flag=1;
      	if(a>b)
 		sum=*node+a;
 		else 
 		sum=*node+b;
 		return sum;
 	}
 }
}
 int main()
 {
 	int t,i,j,k;
 	cin>>t;
 	while(t--)
 	{
 	cin>>n;
 	int a[n][n];
 	for(i=0;i<n;i++)
 	{
 		for(j=0;j<=i;j++)
 		 {
 		 	cin>>a[i][j];
 		 }
 	}
 	k=max(&a[0][0],n);
 	cout<<k<<endl;
 }
 }
