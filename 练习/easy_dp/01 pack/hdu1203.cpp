#include <stdio.h>
#include <algorithm>
#include <string.h>
#define maxn 10010 
using namespace std;

double v[maxn],dp[maxn];
int V,m,w[maxn];

int main(){
//	freopen("1203in.txt","r",stdin);
	while(~scanf("%d %d",&V,&m) && !(V==0 && m==0)){
		for(int i = 0;i < m;i++){
			scanf("%d %lf",&w[i],&v[i]);
		}
		for(int i = 0;i <= V;i++)
			dp[i] = 1.0;
		for(int i = 0;i < m;i++){
			for(int j = V;j >= w[i];j--){
				dp[j] = min(dp[j], dp[j-w[i]]*(1-v[i]));
			}
		}
		printf("%.1lf%%\n",(1.0-dp[V])*100);
	}
	
	return 0;
}
