#include <bits/stdc++.h>
#define inf 0x3f3f3f
#define ll long long
using namespace std;

const ll mod = 998244353;

ll qmod(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1)ans*=a;
        a*=a;
        b>>=1;
        a%=mod;
        ans%=mod;
    }
    return ans;
}

int main()
{
	int t;
	ll a,b,c,d;
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		ll res = 0;
		res = qmod(2,a)*(qmod(2,b) + (qmod(2,c)-1)*(1+b)%mod + qmod(2,c)*d%mod)%mod;
		printf("%lld\n",res);
	}
	return 0;
} 
