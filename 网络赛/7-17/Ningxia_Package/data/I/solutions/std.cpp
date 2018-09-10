#include<bits/stdc++.h>
using namespace std;
int pw[55];
int main()
{
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++)
    {
        int n,k,q;
        scanf("%d%d%d",&n,&k,&q);
        k=min(n,k);
        for(int i=(pw[0]=1);i<=n;i++)
            pw[i]=1LL*(k+1)*pw[i-1]%q;
        int res=pw[n-k];
        for(int i=2;i<=n-k;i++)
            res=(res+1LL*(n-k+1-i)*pw[n-k+1-i])%q;
        for(int i=3;i<=n-k;i++)
            res=(res+1LL*(n-k+1-i)*pw[n-k-1])%q;
        for(int i=1;i<=k;i++)
            res=1LL*i*res%q;
        printf("Case #%d: %d\n",ca,res);
    }
    return 0;
}
