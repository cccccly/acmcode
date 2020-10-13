#include <stdio.h>
#include <algorithm>
#include <string.h>
#define maxn 1010
using namespace std;
int T,n,V;
int w[maxn],v[maxn],dp[maxn];

void print(){
	for(int i = 0;i <= V;i++){
		printf("%d ",dp[i]);
	}
	puts("");
}

int main(){
//	freopen("2602in.txt","r",stdin);
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&V);
		for(int i = 0;i < n;i++){
			scanf("%d",&v[i]);
		}
		for(int i = 0;i < n;i++){
			scanf("%d",&w[i]);
		}
		memset(dp,0,sizeof(dp));
		for(int i = 0;i < n;i++){
			for(int j = V;j >= w[i];j--){
				dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
			}
//			print();
		}
		printf("%d\n",dp[V]); 
	}
	return 0;
}
