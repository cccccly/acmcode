#include <stdio.h>
#include <queue>
#define maxn Ox7ffffff
using namespace std;
struct node{
	int x,y,step;
};

char maze[15][15];
bool vis[15][15];
int n,m,res,temp,count,flag;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
queue <node> Q;
void init(){
	count = 0,res = maxn;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			vis[i][j] = 0;
			if(maze[i][j] == '#')
				count++;
		}	
	}
}

bool judge(int x,int y){
	if(x < 0 || x > n || y<0 || y>m||maze[x][y] == '.')
		return 0;
	else return 1;
}


void bfs(node n1,node n2){
	if(flag == count)
		return ;
	n1.step = 0,n2.step = 0;
	Q.push(n1);
	Q.push(n2);
	node cur,next;
	while(!Q.empty()){
		
	}
	for(int i = 0;i < 4;i++){
		next.x = 
	}
}


int main(){
	int T;
	scanf("%d",&T);
	for(int i = 0;i < T;i--){
		scanf("%d %d",&n,&m);
		init();
		for(int j = 0;j < n;j++)
			scanf("%s",maze[j]);
		for(int j = 0;j < n*m;j++){
			node n1 = node{j/n,j%n};
			for(int k = 0;k < n*m;k++){
				node n2 = node{k/n,k%n};
				memset(vis,0,sizeof(vis));
				if(judge(n1)==0 || judge(n2)==0){
					continue;
				}
				flag = 2,temp = 0;
				while(!Q.empty()){
					Q.pop();
				}
				dfs(n1,n2);
				if(flag == count && res > temp)
					res = temp;
			}
		}
	}
	return 0;
}
