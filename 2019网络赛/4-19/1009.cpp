#include <stdio.h>
#include <iostream>
using namespace std;

int n,m,k;
char s[110][110];
char ss[110][1100];
int main(){
	//freopen("1009.in","r",stdin);
	while(~scanf("%d %d %d",&n,&m,&k)){
		for(int i = 0;i < n;i++){
			scanf("%s",s[i]);
		}
		for(int i = 0;i < n;i++){
			int p = 0;
			for(int j = 0;j < m;j++){
				char c = s[i][j];
				for(int l = 0;l < k;l++){
					ss[i][p++] = c;
				}
			}
		}
		
		for(int i = 0;i < n;i++){
			for(int l = 0;l < k;l++){
				for(int j = 0;j < m*k;j++)
					printf("%c",ss[i][j]);
				puts("");
			}	
		}
	}
	return 0;
} 
