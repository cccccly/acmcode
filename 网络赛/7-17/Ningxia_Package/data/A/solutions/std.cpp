#include<bits/stdc++.h>
using namespace std;
const int MAXN=5000005;
int stk[MAXN],top,res[MAXN];
int n, p, q, m;
unsigned int SA,SB,SC;
unsigned int rng61()
{
    SA ^= SA << 16;
    SA ^= SA >> 5;
    SA ^= SA << 1;
    unsigned int t = SA;
    SA = SB;
    SB = SC;
    SC ^= t ^ SA;
    return SC;
}
long long solve()
{
    scanf("%d%d%d%d%u%u%u",&n,&p,&q,&m,&SA,&SB,&SC);
    long long res=(top=0);
    for(int i=1;i<=n;i++)
    {
        if(rng61()%(p+q)<p)
        {
            ++top;
            stk[top]=rng61()%m+1;
            stk[top]=max(stk[top],stk[top-1]);
        }
        else top=max(top-1,0);
        res^=1LL*i*stk[top];
    }
    return res;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int ca=1; ca<=T; ca++)
        printf("Case #%d: %lld\n",ca,solve());
    return 0;
}
