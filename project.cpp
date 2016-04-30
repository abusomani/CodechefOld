#include<iostream>
#include<new>
using namespace std;
int main()
{
	long i,max,min,*p,n,rem;
	cout<<"Enter the size of array";
	cin>>n;
	long a[n];
	cout<<"Now enter numbers\n";
	cin>>a[0];
	max=min=a[0];
	for(i=1;i<n;i++)
	{
		cin>>a[i];
		if(max<a[i])
		max=a[i];
		if(min>a[i])
		min=a[i];
	}
	cout<<"\nRange of numbers are from"<<min<<" to "<<max<<endl;
	cout<<"Missing numbers are\n";
	p=new long[max-min+1];
	for(i=0;i<max-min+1;i++)
	*(p+i)=min+i;
	for(i=0;i<n;i++)
	{
		if(*(p+(a[i]-min))<max+1)
		   *(p+(a[i]-min))=max+1; 
		else
	       *(p+(a[i]-min))=*(p+(a[i]-min))+1;
    }
	for(i=0;i<max-min+1;i++)
	if(*(p+i)<max+1)
    cout<<*(p+i)<<endl;
	for(i=0;i<max-min+1;i++)
	if(*(p+i)>max+1) cout<<i+min<<" occur "<<*(p+i)-max<<" times. \n";
	delete[] p;
	
}
