#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int n,V;
double p,pp[101],dp[10010];
int m[101];

void print(){
	for(int i = 0;i <= V;i++){
		printf("%lf ",dp[i]);
	}
	puts("");
}

int main(){
	int T;
	freopen("2955in.txt","r",stdin);
	scanf("%d",&T);
	while(T--){
		scanf("%lf %d",&p,&n);
		V = 0;
		for(int i = 0;i < n;i++){
			scanf("%d %lf",&m[i],&pp[i]);
			V += m[i];
		}
			
		memset(dp,0,sizeof(dp));
		dp[0] = 1.0;
		for(int i = 0;i < n;i++){
			for(int j = V;j >= m[i];j--){
				dp[j] = max(dp[j],dp[j-m[i]]*(1.0-pp[i]));
			}
			print();
		}
//		print();
		for(int i = V;i >= 0;i--){
			if(dp[i] > 1.0-p){
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;	
} 
