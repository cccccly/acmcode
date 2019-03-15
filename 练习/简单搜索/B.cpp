#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
#define maxn 32

char maze[maxn][maxn][maxn];
int vis[maxn][maxn][maxn];
int sx,sy,sz,ex,ey,ez;
int l,r,c,cnt;
int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};
char temp[maxn];

struct Node{
	int x,y,z,step;
};

int check(Node temp){
	if(temp.x<0||temp.y<0||temp.z<0||temp.x>=c||temp.y>=r||temp.z>=l||maze[temp.z][temp.y][temp.x]=='#'||vis[temp.z][temp.y][temp.x]==1)
		return 1;
	else 
		return 0;
}

int bfs(){
	Node cur,next;
	queue<Node> q;
	cur.x = sx;
	cur.y = sy;
	cur.z = sz;
	cur.step = 0;
	q.push(cur);
	while(!q.empty()){
		cur = q.front();
		q.pop();
		if(cur.x == ex && cur.y == ey && cur.z == ez)
			return cur.step;
		for(int i = 0;i < 6;i++){
			next = cur;
			next.x = cur.x+dx[i];
			next.y = cur.y+dy[i];
			next.z = cur.z+dz[i];
			next.step++;
			if(check(next))
				continue;
			vis[next.z][next.y][next.x] = 1;
			q.push(next);
			
			//printf("%d %d %d\n",next.x,next.y,next.z);
		}
	}
	return -1;
}

void print(){
	for(int i = 0;i < l;i++){
		for(int j = 0;j < r;j++){
			//printf("%s\n",maze[i][j]);
			for(int k = 0;k < c;k++)
				printf("%c",maze[i][j][k]);
			puts("");
		}
	}
}

int main(){
	
	#ifdef ONLINE_JUDGE
	#else
	    freopen("inB.txt","r",stdin);
	#endif
	
	while(1){
		cnt = 0;
		memset(vis,0,sizeof(vis));  
		scanf("%d%d%d",&l,&r,&c);
		if(l == 0 && r == 0 && c == 0)
			break;
		//make map 
		for(int i = 0;i < l;i++){
			for(int j = 0;j < r;j++){
				scanf("%s",maze[i][j]);
				for(int k = 0;k < c;k++){
					if(maze[i][j][k] == 'S'){
						sx = k;
						sy = j;
						sz = i;
					}		 
					else if(maze[i][j][k] == 'E'){
						ex = k;
						ey = j;
						ez = i;
					}		
				}	
			}
			getchar();
		}
		//printf("%d%d%d%d%d%d\n",sx,sy,sz,ex,ey,ez);
		
		cnt = bfs();
		//print();
		if(cnt == -1)
			puts("Trapped!");
		else printf("Escaped in %d minute(s).\n",cnt);
	}
	return 0;
} 
