#include<stdio.h>
#define N 600000
int mod[N];
int ans[200];
int main()
{
    int i,k,n;
    while(scanf("%d",&n),n)
    {
        mod[1]=1%n; 
        for(i=2;mod[i-1]!=0;i++)
        {                    
            mod[i]=(mod[i/2]*10+i%2)%n;
        }
        i--;
        k=0;
        while(i)
        {
            ans[k++]=i%2;
            i/=2;
        }
        for(i=k-1;i>=0;i--)
            printf("%d",ans[i]);
        puts("");
    }
    return 0;
}
