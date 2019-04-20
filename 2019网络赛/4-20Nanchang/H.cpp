#include <stdio.h>
#define ll long long

using namespace std;
const ll mod = 1000000007;
ll qmod(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1)
			ans*=a;
		a*=a;
        b>>=1;
        a%=mod;
        ans%=mod;
    }
    return ans;
}

ll n;

int main(){
	scanf("%lld",&n);
	if(n == 1){
		puts("1");
	}
	else if(n == 2){
		puts("4");
	}
	else{
		ll ans = qmod(3,n-2);
		ans = (ans*4)%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
