#include<bits/stdc++.h>
using namespace std;
const int MAXN=205;
int r[MAXN],idx[MAXN],dp[MAXN][MAXN][MAXN];
int main()
{
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++)
    {
        int n,q;
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++)
            scanf("%d",&r[i]),idx[i]=i;
        sort(idx+1,idx+n+1,[](int x,int y){return r[x]<r[y];});
        sort(r+1,r+n+1);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&dp[0][i][j]);
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    dp[k][i][j]=min(dp[k-1][i][j],dp[k-1][i][idx[k]]+dp[k-1][idx[k]][j]);
        printf("Case #%d:\n",ca);
        for(int i=1;i<=q;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            int k=upper_bound(r+1,r+n+1,w)-r-1;
            printf("%d\n",dp[k][u][v]);
        }
    }
    return 0;
}
