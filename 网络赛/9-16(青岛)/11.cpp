#include <bits/stdc++.h>

using namespace std;
typedef long long ll; 

ll sum[45];
int ans[45];
int main(){
	int T;
	sum[1] = 1;
	for(int i = 2;i <= 40;i++){
		sum[i] = sum[i-1]*2;
	}
	for(int i = 2;i <= 40;i++){
		sum[i]--;
	}

	scanf("%d",&T);
	while(T--){
		int mx = 0;
		memset(ans,0,sizeof(ans));
		int n;
		ll temp;
		scanf("%d",&n);
		for(int i = 1;i <= n;i++){
			scanf("%lld",&temp);
			for(int i = 2;i <= 40;i++){
				if(temp <= sum[i]){
					ans[i]++;
					mx = max(mx,ans[i]);
					break;
				}
			}
		}
		printf("%d\n",mx); 
	}
	return 0;
} 
