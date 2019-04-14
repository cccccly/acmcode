#include <stdio.h>
#include <stack>
#include <string.h>

using namespace std;

struct node{
	int x,y;
};

int m,n,cnt;
char maze[110][110];
bool vis[110][110];
int dx[8] = {1,-1,0,0,-1,1,1,-1};
int dy[8] = {0,0,1,-1,-1,1,-1,1};

void init(){
    for(int i = 0;i < m;i++){
        scanf("%s",maze[i]);
    }
    memset(vis,0,sizeof(vis));
    cnt = 0;
}

void printAll(){
    for(int i = 0;i < m;i++){
        printf("%s\n",maze[i]);
    }
    puts("");
}

bool judge(node tmp){
	int x = tmp.x,y = tmp.y;
	if(x>=0 && x<m && y>=0 && y<n && vis[x][y]==0 &&maze[x][y] == '@')
		return 1;
	else return 0;
}

void dfs(node cur){
	node next;
	for(int k = 0;k < 8;k++){
		next.x = cur.x + dx[k];
		next.y = cur.y + dy[k];
		if(!judge(next))
			continue;
		vis[next.x][next.y] = 1;
		dfs(next);
	}
}

int main(){
    //freopen("..//data//l.in","r",stdin);
    while(~scanf("%d %d",&m,&n)){
        if(m == 0 && n == 0){
            break;
        }
        init();
        //printAll();
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(vis[i][j] == 1 || maze[i][j] == '*')
                    continue;
                node tmp = {i,j};
                dfs(tmp);
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
