#include <stdio.h>

using namespace std;
#define ll long long 
ll n,res;

void dfs(ll cur,int k){
	if(k >= 19 || res != -1){
		return ;
	}
	if(cur % n == 0){
		res = cur;
		return ;
	}
	dfs(cur*10,k+1);
	dfs(cur*10+1,k+1);
}

int main(){
	while(~scanf("%lld",&n) && n){
		res = -1;
		dfs(1,0);
		printf("%lld\n",res);
	}
	return 0;
} 
