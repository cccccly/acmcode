#include <stdio.h>
#include <string.h>
using namespace std;
#define maxn 10
int maze[maxn][maxn];//记录棋盘 
int vis[maxn];//第i列是否放置了棋子 
int count,tot;//当前放置的棋子数 ，方案数 
int n,k;  //棋盘大小 棋子数 
void dfs(int cur){
	if(count == k){ //达到总数 
		tot++;
		return; 
	}
	if(cur > n) //搜出棋盘外 
		return;
	for(int i = 1;i <= n;i++){
		if(!vis[i] && maze[cur][i]){ //当前列没放棋子 且当前点可走 
			vis[i] = 1;
			count++;
			dfs(cur+1);
			vis[i] = 0;  //回溯 
			count--;
		}
	}
	dfs(cur+1); //可能放不了棋子 
}

int main(){
	
	while(~scanf("%d%d",&n,&k)){
		if(n == -1 && k == -1)
			break;
		getchar();
		char c;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				c = getchar();
				if(c == '.')
					maze[i][j] = 0;
				else
					maze[i][j] = 1;
			}
			getchar();
		}
		count = 0,tot = 0;
		memset(vis,0,sizeof(vis));
		dfs(1);
		printf("%d\n",tot);	
	}
	return 0;
} 
