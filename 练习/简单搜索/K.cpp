#include <stdio.h>
#include <queue>
#include <stack>

using namespace std;

struct node{
	int x,y;   
};

int maze[5][5] = {0};
int vis[5][5] = {0};
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int road[5][5] = {0}; 
queue <node> Q;
stack <node> st;


void bfs(){
	node cur,next;
	cur.x = 0;
	cur.y = 0;
	Q.push(cur);
	while(!Q.empty()){
		cur = Q.front();
		Q.pop();
		for(int i = 0;i < 4;i++){
			next.x = cur.x + dx[i];
			next.y = cur.y + dy[i];
			if(next.x < 0 || next.x > 4||next.y < 0 || next.y > 4 || vis[next.x][next.y] || maze[next.x][next.y])
				continue; //over edge 
			if(next.x == 4 && next.y == 4)  //find answer
				return ; 
			road[next.x][next.y] = i;
			vis[next.x][next.y] = 1;
			Q.push(next);
		}
	} 
	return ;
}

void dfs(int x,int y){
	if(x == 0&&y == 0){
		return ;
	}
	int dir = road[x][y];
	dfs(x -= dx[dir],y -= dy[dir]);
	printf("(%d, %d)\n",x,y);
} 


int main(){
	
	for(int i = 0;i < 5;i++){
		for(int j = 0;j < 5;j++){
			scanf("%d",&maze[i][j]);
		}
	}
	bfs();
	
	dfs(4,4);
	printf("(4, 4)");
	return 0;
} 
