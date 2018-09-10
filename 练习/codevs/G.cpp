#include <bits/stdc++.h>

using namespace std;
typedef long long LL;  
  
const int N=1000005;  
const LL INF=(LL)1<<62;  
  
bool prime[N];  
LL p[N];  
LL fac[N];  
LL k,cnt,num,ans,n,m,K;
 
void Solve(LL m,LL n)  
{  
    cnt=0;  
    LL i;  
    for(i=0; p[i]*p[i]<=n; i++)  
    {  
        if(n%p[i]==0)  
        {  
            fac[cnt++]=p[i];  
            while(n%p[i]==0) n/=p[i];  
        }  
    }  
    if(n>1)  
        fac[cnt++]=n;  
    for(i=0; p[i]*p[i]<=m; i++)  
    {  
        if(m%p[i]==0)  
        {  
            fac[cnt++]=p[i];  
            while(m%p[i]==0) m/=p[i];  
        }  
    }  
    if(m>1)  
        fac[cnt++]=m;  
}  
  
void dfs(LL k,LL t,LL s,LL n)  
{  
    if(k==num)  
    {  
        if(t&1) ans-=n/s;  
        else    ans+=n/s;  
        return;  
    }  
    dfs(k+1,t,s,n);  
    dfs(k+1,t+1,s*fac[k],n);  
}

void init(){
	
}
int main(){
	
	while(~scanf("%lld %lld",&n,&m)){
		Solve(1,m);
		for(int i = 0;i < cnt;i++){
			printf("%d %d\n",fac[i],p[i]);
		}
	}
	return 0;
} 
