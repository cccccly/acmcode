#include <stdio.h>
#include <string.h>
using namespace std;
#define maxn 110
int T,N,ans,cnt;
int a[maxn];
int dp[maxn],vis[maxn];

void init(){
	scanf("%d",&N);
	for(int i = 1;i <= N;i++){
		scanf("%d",&a[i]);
	}
	memset(vis,0,sizeof(vis));
	cnt = a[1];
	vis[1] = 1;
	//memset(dp,0,sizeof(dp));
}

void solve(){
	for(int i = 2;i <= N;i++){
		if(!vis[i-1]){
			vis[i] = 1;
			cnt += a[i];
			continue;
		}
		if(a[i] > a[i-1]){
			vis[i] = 1;
			vis[i-1] = 0;
			cnt += a[i]-a[i-1];
			if(i-2 >= 1 && !vis[i-3]){
				vis[i-2] = 1;
				cnt += a[i-2];
			}
		}
		else {
			if(i-2>=1 && !vis[i-3] &&a[i] + a[i-2] > a[i-1]){
				vis[i] = vis[i-2] = 1;
				vis[i-1] = 0;
				cnt += a[i]+a[i-2]-a[i-1];
			}
		}
	}
}

int main(){
	scanf("%d",&T);
	while(T--){
		init();
		solve();
		printf("%d\n",cnt);
	}
	return 0;
}
