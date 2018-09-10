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
