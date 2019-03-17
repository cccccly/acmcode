#include <bits/stdc++.h>

using namespace std;
int r,y,g,n,ans;
int main(){
	ans = 0;
	scanf("%d %d %d",&r,&y,&g);
	scanf("%d",&n);
	int k,t;
	while(n--){
		scanf("%d %d",&k,&t);
		if(k == 0  || k == 1){
			ans += t;
		}
		else if(k == 2){
			ans += t + r;
		}
	}
	printf("%d\n",ans);
	return 0;
}
