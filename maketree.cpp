#include<iostream>
using namespace std;
int b[20],n,d=0;
int *start,*end;
int fnd(int *p,int t)
{
	for(int i=0;i<n;i++)
	{
		if(p[i]==t)
		return i;
	}
}
void mtree(int *ins,int *ine,int *pres,int *pree)
{
    if(ins>end  ||  ine<start)  return;
	if(*ins==*ine)      b[d++]=*ins;
	else 
	{
		int k=fnd(ins,*pres);
//		cout<<in[k]<<endl;
//	b[d++]=*pres;
		mtree(ins,ins+k-1,pres+1,pres+k);
		mtree(ins+k+1,ine,pres+k+1,pree);
	   b[d++]=*pres;
	}
}
int main()
{
	int i;
	cout<<"enter length\n";
	cin>>n;
	int pre[n],in[n];
	cout<<"Enter preorder\n";
	for(i=0;i<n;i++)
	cin>>pre[i];
	cout<<"Enter inorder\n";
	for(i=0;i<n;i++)
	cin>>in[i];
	start=in;
	end=in+n-1;
	mtree(start,end,pre,pre+n-1);
	for(i=0;i<n;i++)
	cout<<b[i];
}
