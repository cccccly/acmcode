#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define maxn 10010

int T,n,m,k,pass;
int cnt[maxn];
int stu[maxn],rk[maxn];


int main(){
	
	//freopen("4.txt","r",stdin);
	scanf("%d",&T);
	while(T--){
		memset(cnt,0,sizeof(cnt));
		memset(rk,0,sizeof(rk));
		pass = 0;
		scanf("%d %d %d",&n,&m,&k);
		for(int i = 1;i <= n;i++){
			scanf("%d",&stu[i]);
			cnt[stu[i]]++;
		}
		for(int i = 1;i <= n/2;i++){
			if(++rk[stu[i]] <= cnt[stu[i]]/k)
				pass++;
		}
		printf("%d\n",pass);
	}
	return 0;
} 
