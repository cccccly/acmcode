#include <bits/stdc++.h>

using namespace std;

#define ll long long
ll a[30]; 
ll c(ll n,ll m)  
{
    if(m==1) return n;
    if(n==m) return 1;
    return (c(n-1,m-1)+c(n-1,m));
}
void init(){
	a[1] = 0;
	a[2] = 1;
	for(int i = 3;i <= 25/2;i++){
		a[i] = (i-1)*(a[i-1] + a[i-2]);
	}
}

int main()
{
	int n;
	init();
	while(~scanf("%d",&n) && n != 0){
		ll ans = 0;
		for(int i = 2;i <= n/2;i++){
			ans += c(n,i)*a[i];
		}
		printf("%lld\n",ans+1);
	}
	return 0;
} 
