#include <bits/stdc++.h>

using namespace std;
#define maxn 100000+7
int sum[maxn];
int sum1[maxn];
char ss[maxn];
int main(){
	int T;
	scanf("%d",&T);
	memset(sum,0,sizeof(sum));
	while(T--){
		scanf("%s",ss);
		int len = strlen(ss);
		char c = ss[len - 1];
		for(int i = len - 1;i >= 0 ;i--){
			if(c != ss[i]){
				sum[i+1] = sum[i] + 1;
				c = ss[i];
			}
			else 
				sum[i+1] = sum[i];
		}
		for(int i = 1;i <= len;i++)
			sum1[i] = sum[i-1] + sum[i];
		int ans = 0;
		int temp = sum1[len];
		for(int i = 1;i <= len;i++){
			if(!(ss[i-1]-48)){
				ans += len-i+1;
			}
			ans += temp;
			if(ss[i] != ss[i-1])
				temp -= len-i+1;
		}
		printf("%d\n",ans);
	}
	return 0;
} 
