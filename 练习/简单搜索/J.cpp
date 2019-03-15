#include <stdio.h>
#include <queue>

struct node{
	int x,y;
	int fx;    //以何种方向到这个点  0-右 1-左 2-下 3-上  
};
using namespace std;

int maze[5][5] = {0};
int vis[6][6] = {0};
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int 

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
			if(next.x < 0 || next.x > 4||next.y < 0 || next.y > 4 || vis[next.x][next.y])
				continue; //over edge 
			if(next.x == 4 && next.y == 4)
				return ; 
		}
	} 
	return ;
}

int main(){
	
	for(int i = 0;i < 5;i++){
		for(int j = 0;j < 5;j++){
			scanf("%d",&maze[i][j]);
		}
	}
	
	
	return 0;
} 
