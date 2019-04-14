#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define maxn 10010


int y,m,d,h,mm,s,T;
int ans;
int main(){
	
	//freopen("2.txt","r",stdin);
	scanf("%d",&T);
	while(T--){
		scanf("%d-%d-%d %d:%d:%d",&y,&m,&d,&h,&mm,&s);
		ans = (mm*60+s)%100;
		printf("%d",ans);
	}
	return 0;
} 
