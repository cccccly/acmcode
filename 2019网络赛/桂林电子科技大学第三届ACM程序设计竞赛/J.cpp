#include <stdio.h>
#include <string.h>
using namespace std;
char maze[55][55];
bool vis[55][55];
int n,m,t,ans;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

struct node{
	int x,y;
};

void init(){
	scanf("%d %d",&n,&m);
	for(int i = 0;i < n;i++){
		scanf("%s",maze[i]);
	}
	memset(vis,0,sizeof(vis));
	ans = 0;
}

bool judge(int x,int y){
	if(x >= 0 && x < n && y >= 0 && y < m && vis[x][y] == 0 && maze[x][y] == '1')
		return 1;
	else return 0;
}

void dfs(node cur){
	node next;
	for(int i = 0;i < 4;i++){
		next.x = cur.x + dx[i];
		next.y = cur.y + dy[i];
		if(!judge(next.x,next.y))
			continue;
		vis[next.x][next.y] = 1;
		dfs(next);
	}
}

int main(){
	scanf("%d",&t);
	while(t--){
		init();
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(vis[i][j] == 1 || maze[i][j] == '0')
					continue;
				node tmp = node{i,j};
				dfs(tmp);
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
