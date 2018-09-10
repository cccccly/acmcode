#include <bits/stdc++.h>

using namespace std;
using ll = long long;
//线性筛

const int MAXN = 1e7*2;
bool check[MAXN + 5];
int ans[MAXN + 5];  //记录答案 
int prime[MAXN + 5]; //素数 
ll pre[MAXN + 5];   //前缀和 
int tot = 0; //素数的个数
void primeTable(int N){
	memset(check,false,sizeof(check));
	tot = 0;
	ans[1] = 1; 
	for(int i = 2;i <= N;i++){
		if(!check[i]){  
			prime[tot++] = i;
			ans[i] = 2;
		}
		for(int j = 0;j < tot;j++){
			if(i*prime[j] > N) break;
			check[i * prime[j]] = true;
			if(i % prime[j] == 0){
				ll temp = prime[j]*prime[j];
				if(i % temp == 0){
					ans[i*prime[j]] = 0;
				}
				else {
					ans[i*prime[j]] = ans[i/prime[j]];
				}
				break; 
			}
			else{
				ans[i*prime[j]] = ans[i] * ans[prime[j]];
			} 
		}
	}
} 

void solve(){
	ll sum = 0;
	for(int i = 1;i <= MAXN + 2;i++){
		sum += ans[i];
		pre[i] = sum;
	}
} 

int main(){
	int T,n;
	primeTable(MAXN);
	solve();
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		printf("%lld\n",pre[n]);
	}
	return 0;
}
