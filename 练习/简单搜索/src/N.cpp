#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;

struct node{
	int x,y,step;
};

int n,m;
char maze[210][210];
bool vis1[210][210],vis2[210][210];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
node ans[210][210];
queue <node> q1,q2;


void init(){
	for(int i = 0;i < n;i++){
		scanf("%s",maze[i]);
	}
	while(!q1.empty()) q1.pop();
	while(!q2.empty()) q2.pop();
	memset(vis1,0,sizeof(vis1));
	memset(vis2,0,sizeof(vis2));
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			char tmp = maze[i][j];
			if(tmp == 'Y'){
				q1.push(node{i,j,0});
			}
			else if(tmp == 'M'){
				q2.push(node{i,j,0});
			}
			else if(tmp == '@'){
				ans[i][j].x = ans[i][j].y = -1;
			}
		}
	}
}

bool judge1(node tmp){
	int x = tmp.x,y = tmp.y;
	if(x >= 0 && x < n && y >= 0 && y<m &&!vis1[x][y] && maze[x][y] != '#')
		return 1;
	else return 0; 
}

bool judge2(node tmp){
	int x = tmp.x,y = tmp.y;
	if(x >= 0 && x < n && y >= 0 && y<m &&!vis2[x][y] && maze[x][y] != '#')
		return 1;
	else return 0; 
}
void bfs1(){
	node cur,next;
	while(!q1.empty()){
		cur = q1.front();
		q1.pop();
		for(int i = 0;i < 4;i++){
			next.x = cur.x + dx[i];
			next.y = cur.y + dy[i];
			if(!judge1(next))
				continue;
			vis1[next.x][next.y] = 1;
			next.step = cur.step + 1;
			if(maze[next.x][next.y] == '@')
				ans[next.x][next.y].x = next.step;
			q1.push(next);
		}
	} 
}

void bfs2(){
	node cur,next;
	while(!q2.empty()){
		cur = q2.front();
		q2.pop();
		for(int i = 0;i < 4;i++){
			next.x = cur.x + dx[i];
			next.y = cur.y + dy[i];
			if(!judge2(next))
				continue;
			vis2[next.x][next.y] = 1;
			next.step = cur.step + 1;
			if(maze[next.x][next.y] == '@')
				ans[next.x][next.y].y = next.step;
			q2.push(next);
		}
	} 
}

void solve(){
	int min = 50010;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(maze[i][j] == '@' && ans[i][j].x != -1 &&ans[i][j].y != -1&& ans[i][j].x+ans[i][j].y < min){
				min = ans[i][j].x + ans[i][j].y;
			}
		}
	}
	printf("%d\n",min*11);
}


int main(){
	//freopen("..//data//n.in","r",stdin);
	while(~scanf("%d %d",&n,&m)){
		init();
		bfs1();
		bfs2();
		solve();
		//printf("%d %d\n",n,m);
	}
	return 0;
}
