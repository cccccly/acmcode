#include <bits/stdc++.h>

using namespace std;
#define ll long long
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		ll a,b,sum = 0;
		scanf("%d",&n);
		for(int i = 1;i <= n;i++){
			scanf("%lld %lld",&a,&b);
			sum += a*b;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
