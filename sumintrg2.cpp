 #include<stdio.h>
 #define c(n) scanf("%d",&n);
 #define L(i,s,e) for(i=s;i<=e;i++) 
 #define Q(i,s,e) for(i=s;i>=e;i--) 
 int m(int a,int b){return (a>=b)?a:b;}int main()
 {int t,i,j,k,n,r;c(t);while(t--){c(n)k=1;r=(n*(n+1)/2);int a[r+1],s[r+1];L(i,1,r)c(a[k++])L(i,r-n+1,r)s[i]=a[i];Q(i,n-1,1){Q(j,i,1){r=(i*(i-1))/2+j;s[r]=a[r]+m(s[r+i],s[r+i+1]);}}printf("%d\n",s[1]);}}
