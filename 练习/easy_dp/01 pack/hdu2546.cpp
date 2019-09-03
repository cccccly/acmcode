#include <stdio.h>
#include <string.h>
#include <algorithm>
#define maxn 1010
using namespace std;

int dp[maxn],w[maxn],v[maxn];
int n,V;
int main(){
//	freopen("2546in.txt","r",stdin);
	while(~scanf("%d",&n) && n != 0){
		for(int i = 0;i < n;i++){
			scanf("%d",&v[i]);
		}
		scanf("%d",&V);
		int ans = V;
		sort(v,v+n);
		memset(dp,0,sizeof(dp));
		if(V < 5){
			printf("%d\n",V);
		}
		else{
			V -= 5;
			ans -= v[n-1];
			n--;
			for(int i = 0;i < n;i++){
				for(int j = V;j >= v[i];j--){
					dp[j] = max(dp[j],dp[j-v[i]]+v[i]);
				}
			}
			ans = ans - dp[V];
			printf("%d\n",ans);
		}	
	}
	return 0;
}
