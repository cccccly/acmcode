#include <bits/stdc++.h>

using namespace std;
char maze[32][32][32];
int ans[32][32][32];
bool vis[32][32][32];
int L,R,C;
int jz[6][3] = {{0,-1,0},{0,1,0},{-1,0,0},{1,0,0},{0,0,-1},{0,0,1}};
struct node{
	int x,y,z,num;
};
int main(){
	while(~scanf("%d%d%d",&L,&R,&C)){
		if(L == 0&&R == 0&&C == 0)
			break;
		getchar();
		char c;
		for(int i = 1;i <= L;i++){
			for(int j = 1;j <= R;j++){
				for(int k = 1;k <= C;k++){
					c = getchar();
					maze[j][k][i] = c;
				}
				getchar();
			} 
			getchar();
		} 
		for(int i = 1;i <= L;i++){
			for(int j = 1;j <= R;j++){
				for(int k = 1;k <= C;k++){
					scanf("%c",&maze[j][k][i]);
				}
				puts("");
			} 
			puts("");
		}
	}
	return 0;
} 
