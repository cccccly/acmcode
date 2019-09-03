#include <stdio.h>
#include <string.h>
#include <algorithm>
#define maxn 55

using namespace std;
int N;

int v[55],cnt[55];
int dp[250010];
int main(){
	while(~scanf("%d",&N) && N >= 0){
		int sum_v = 0,sum_n = 0,V;
		for(int i = 0;i < N;i++){
			scanf("%d %d",&v[i],&cnt[i]);
			sum_v += v[i]*cnt[i];
			sum_n += cnt[i]; 
		}
		V = sum_v / 2;
		int p = 0,i = 0,time = cnt[0];
		memset(dp,0,sizeof(dp));
		while(p++ < sum_n){
			if(time-- == 0){
				i++;
				time = cnt[i] - 1;
			}
			for(int j = V;j >= v[i];j--){
				dp[j] = max(dp[j], dp[j-v[i]] + v[i]);
			}
		}
		printf("%d %d\n",sum_v-dp[V],dp[V]);
	}
	
	return 0;
}
