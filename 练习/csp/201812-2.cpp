#include <stdio.h>

using namespace std;
#define ll long long 
ll r,y,g,n,ans;

ll judge(ll k,ll t){
	ll temp,cost;
	if(k == 1){
		temp = (y+g+r+ans-t)%(y+g+r);
	}
	else if(k == 2){
		temp = (ans + g + y-t)%(y+g+r);
	}
	else{
		temp = (ans + g-t)%(y+g+r);
	}
	if(temp < g)
		cost = 0;
	else 
		cost = g+y+r-temp;
	return cost;
}

int main(){
	//freopen("2.in","r",stdin);
	ans = 0;
	scanf("%lld %lld %lld",&r,&y,&g);
	scanf("%lld",&n);
	ll k,t,temp;
	while(n--){
		scanf("%lld %lld",&k,&t);
		if(k == 0){
			ans += t;
		}
		else{
			temp = judge(k,t);
			ans += temp;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
