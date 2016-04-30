 #include<iostream>
using namespace std;
int main()
{
int a[10],i,temp=0;
cout<<"enter elements:"<<endl;
for(i=0;i<10;i++)
{
cin>>a[i];
}
for(i=1;i<10;i++)
{
if(a[i]==a[i-1])
{
temp++;
}
else
{
cout<<a[i-1]<<" occurs "<<temp+1<<" times."<<endl;
temp=0;
}
}
if(a[9]==a[8])
{
cout<<a[9]<<" occurs "<<temp+1<<" times."<<endl;
}
else
{
cout<<a[9]<<" occurs once."<<endl;
}
return 0;
}
