#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	while(~scanf("%d",&n)){
		int mx = -1,temp;
		for(int i = 1;i <= n;i++){
			scanf("%d",&temp);
			mx = max(mx,temp); 
		}
		printf("%d\n",mx*2);
	}
	return 0;
}
