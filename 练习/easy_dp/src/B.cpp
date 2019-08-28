#include <stdio.h>
#define maxn 1e7
using namespace std;


int main(){
	int n;
	while(~scanf("%d",&n)){
		int ans,cnt = 0,num,pre;
		scanf("%d",&num);
		cnt++;
		ans = num;
		for(int i = 1;i < n;i++){
			scanf("%d",&num);
			if(num == ans){
				cnt++;
			}
			else cnt--;
			if(cnt < 0){
				ans = num;
				cnt = 1;
			}
		}
		printf("%d\n",ans);
	}	
	return 0;
} 
