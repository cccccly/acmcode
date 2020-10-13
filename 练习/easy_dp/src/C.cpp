#include <stdio.h>

using namespace std;

int T,N;
char s[101][16];
int d[16],c[16];

struct node{
	int now,pre,time,score;
}dp[1<<15]; 

void printAll(){
	for(int i = 0;i < N;i++){
		printf("%s %d %d\n",s[i],d[i],c[i]);
	}
}

int main(){
	freopen("c.txt","r",stdin);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(int i = 0;i < N;i++){
			scanf("%s %d %d",s[i],d+i,c+i);
		}
		printAll();
	}
	return 0;
}
