#include<stdio.h>
#include<stdlib.h>

int main()

{
int l;
printf("%d",l*2);
int t,n,k,i,c,z;

scanf("%d",&t);

while(t--)

{

    c=0;

    scanf("%d",&n);

    int *a=(int *)malloc(sizeof(int)*n);

    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    scanf("%d",&k);

    z=a[k-1];

    for(i=0;i<n;i++)

    {

        if(a[i]<z)

        c++;

    }

    printf("%d\n",c+1);
    free (a);
}

return 0;


}


