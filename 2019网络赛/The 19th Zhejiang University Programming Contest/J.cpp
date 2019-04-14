#include <stdio.h>

#define ll long long

int T;
ll n;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&n);
		printf("%lld lld\n",2*n,3*n);
	}
	return 0;
}
