#include <stdio.h>
#include <string.h>
using namespace std;

char s[300010];
int a[300010],ans[400010]; 
int biao[26];
void init(){
	int tmp,tmp2; 
	for(int i = 97;i < 97+26;i++){
		tmp = 0;
		for(int j = 7;j >= 0;j--){
			tmp += ((i >> j)&1) << (7-j);
		}
		biao[i-97] = tmp;
	}
}

void solve(){
	int tmp,tmp2,n;
	n = strlen(s)/3;
	tmp2 = 255;
	for(int i = 0;i < n*3;i++){
		a[i] = biao[s[i]-97];
	}
//	for(int i = 0;i < n*3;i++)
//		printf("%d ",a[i]);
//	puts("");
	
	for(int i = n;i > 0;i--){
		tmp = 0;
		for(int j = 0;j < 3;j++){
			tmp += a[i*3-1-j]<<(j*8);
		}
		//printf("%d\n",tmp);
		tmp2 = 63;
		for(int j = 0;j < 4;j++){
			ans[i*4-1-j] = 63 & tmp;
			tmp = tmp>>6;
		}
	}
	for(int i = 0;i < 4*n;i++){
		if(i == 4*n-1)
			printf("%d ",ans[i]);
		else printf("%d ",ans[i]);
	}
}

int main(){
	scanf("%s",s);
	init();
	solve();
	return 0;
}
