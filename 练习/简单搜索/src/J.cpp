#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;
#define maxn 1010

struct Node{
	int x,y,step;
	bool operator <(const Node b)const{
		return step < b.step;
	}
};

char maze[maxn][maxn];
bool vis[maxn][maxn];
bool vis1[maxn][maxn];
queue<Node> q;
queue<Node> q1;
//priority_queue<Node> q1;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int N,R,C;
Node J,F;

void printN(Node tmp){
	printf("%d %d %d\n",tmp.x,tmp.y,tmp.step);
}

void printAll(){
	for(int i = 0;i < R;i++){
		for(int j = 0;j < C;j++){
			printf("%c",maze[i][j]);
		}
		puts("");
	}
}

void init(){
	memset(vis,0,sizeof(vis));
    memset(vis1,0,sizeof(vis1));
	while(!q.empty()){
		q.pop();
	}
	while(!q1.empty()){
		q1.pop();
	}
	for(int i = 0;i < R;i++)
		for(int j = 0;j < C;j++){
			if(maze[i][j] == 'J')
				J.x = i,J.y = j,J.step = 1;
			else if(maze[i][j] == 'F')
				F.x = i,F.y = j,F.step = 1;
		}
	//printN(F);
	q1.push(F);
}

bool judge(Node tmp){
	int x = tmp.x,y = tmp.y;
	if(x>=0 && x<R && y>=0 && y<C && vis[x][y]==0 && maze[x][y]=='.')
		return 1;
	else return 0;
}

bool judgeOut(Node tmp){
	int x = tmp.x,y = tmp.y;
	if(x == 0||x == R-1||y == 0||y == C-1)
		return 1;
	else return 0;
}

void burn(){
	Node cur,next;
	cur = q1.front();
	int tmp = cur.step;
	//printN(cur);
	do{
		q1.pop();
		//printN(cur);
		for(int i = 0;i < 4;i++){
			next.x = cur.x + dx[i];
			next.y = cur.y + dy[i];
			next.step = cur.step + 1;
			if(next.x>=0 && next.x<R && next.y>=0 && next.y<C && (maze[next.x][next.y]=='.'||maze[next.x][next.y]=='J') && vis1[next.x][next.y]==0){
				maze[next.x][next.y] = 'F';
				q1.push(next);
                vis1[next.x][next.y] = 1;
			}
		}
		cur = q1.front();
	}while(cur.step == tmp);
}
Node bfs(){
	Node cur,next;
	Node tmp = {-1,-1,-1};
	q.push(J);
	while(!q.empty()){
		cur = q.front();
		q.pop();
		burn();    //burn first
		for(int i = 0;i < 4;i++){
			next.x = cur.x + dx[i];
			next.y = cur.y + dy[i];
			if(!judge(next))
				continue;
			next.step = cur.step+1;
			if(judgeOut(next))
				return next;
			q.push(next);
			vis[next.x][next.y] = 1;
//			puts("1");
			//printAll();
		}	
	}
	
	return tmp;
}
int main(){
	freopen("..//data//j.in","r",stdin);
	scanf("%d",&N);
	while(N--){
		scanf("%d %d",&R,&C);
		for(int i = 0;i < R;i++){
			scanf("%s",maze[i]);
		}
		init();
		//printAll();
		Node tmp = bfs();
		if(tmp.step == -1)
			puts("IMPOSSIBLE");
		else printf("%d\n",tmp.step);
	}
	return 0;
} 