#include<iostream>
using namespace std;
int check(int array[],int array_size,int element)
	{ 
    
       int start=0;
       int end=array_size;
       int middle;
       int position=-1;

       middle=(start+end)/2;

       do
      {
         if(element<array[middle])
        end=middle-1;

         else if(element>array[middle])
        start=middle+1;

         middle=(start+end)/2;
      }
       while(start<=end && array[middle]!=element);

       if(array[middle]==element)
      position=middle;

       return position;
    
	}
void srt(int k[],int lb,int ub)
{
 int i,j,key,flag=0,temp;

 if (lb<ub)
    {
     i=lb;
     j=ub+1;
     key=k[i];
     while(flag!=1)
      {
       i++;
       while(k[i]<key)
        {
         i++;
        }
       j--;
       while(k[j]>key)
        {
         j--;
        }
       if (i<j)
          {
           temp=k[i];
           k[i]=k[j];
           k[j]=temp;
          }
       else
          {
           flag=1;
           temp=k[lb];
           k[lb]=k[j];
           k[j]=temp;
          }
      }
     srt(k,lb,j-1);
     srt(k,j+1,ub);
    }
}
int main()
{int n,i,j,t;
cin>>t;
while(t--)
	{cin>>n;
	char a[n][n];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>a[i][j];
			int flagged[n];
		int count=-1,ways=0;
		int x;
	for(j=n-1;j>=0;j--)
		{
		for(i=0;i<n;i++)
		  {x=check(flagged,count,i);
		  			if(x!=-1)
					  continue;
				 if(a[i][j]=='.')
		  		{
		  			  ways++;
		  		}
		else 
			{
			 flagged[++count]=i;
			 srt(flagged,0,count);
			}
		  	
		  }
		}
	cout<<ways<<endl;
	}

}
