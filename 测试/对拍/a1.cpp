#include <stdio.h>
#include <queue>
#include <string.h>

#define maxn 0x7ffffff
#define local
using namespace std;
struct node{
	int x,y,step;
	bool operator <(const node &b) const{
		return step>b.step;
	}
};

char maze[15][15];
bool vis[15][15];
int n,m,res,temp,cnt,flag;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};  //xia shang you zuo

priority_queue<node> pq;
//queue<node> pq;
void init(){
	cnt = 0,res = maxn;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			vis[i][j] = 0;
			if(maze[i][j] == '#')
				cnt++;
		}	
	}
}

bool judge(int x,int y){
	if(x < 0 || x >= n || y<0 || y>=m||maze[x][y] == '.'||vis[x][y] == 1)
		return 0;
	else return 1;
}

void print(){
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++)
			printf("%c",maze[i][j]);
		puts("");
	}
}

void pNode(node nd){
	printf("(%d,%d):%d\n",nd.x,nd.y,nd.step);
}



int bfs(node n1,node n2){
	if(flag == cnt)
		return 0;
	vis[n1.x][n1.y] = vis[n2.x][n2.y] = 1;
	pq.push(n1);
	pq.push(n2);
	node cur,next;
	while(!pq.empty()){
		cur = pq.top();
		//pNode(cur);
		pq.pop();
		for(int i = 0;i < 4;i++){
			next.x = cur.x + dx[i];
			next.y = cur.y + dy[i];
			if(!judge(next.x,next.y))
				continue;
			next.step = cur.step+1;
			flag++;
			if(flag == cnt)
				return next.step;
			vis[next.x][next.y] = 1;
			pq.push(next);
		}
	}
	return -1;
}

int main(){
	int T;
	#ifdef local
		freopen("data\\wa.in","r",stdin);
		//freopen("data\\a1.out","w",stdout);
	#endif
	
	scanf("%d",&T);
	for(int i = 1;i <= T;i++){
		scanf("%d %d",&n,&m);
		
		for(int j = 0;j < n;j++)
			scanf("%s",maze[j]);
		init();	
		//print();
		
		for(int j = 0;j < n*m;j++){
			node n1;
			n1.x = j/n,n1.y = j%n;
			for(int k = 0;k < n*m;k++){
				node n2;
				n2.x = k/n,n2.y = k%n;
				memset(vis,0,sizeof(vis));
				if(judge(n1.x,n1.y)==0 || judge(n2.x,n2.y)==0){
					continue;
				}
				n1.step = 0,n2.step = 0;
				pNode(n1);
				pNode(n2);
				puts("");
				if(n1.x == n2.x && n1.y == n2.y)
					flag = 1;
				else flag = 2;
				
				while(!pq.empty()){
					pq.pop();
				}
				temp = bfs(n1,n2);
				
				if(temp != -1 && res > temp)
					res = temp;
				puts("");
			}
			//printf("flag%d:%d\n",i,flag);
		}
		//printf("%d\n",res);
		if(res == maxn)
			res = -1; 
		printf("Case %d: %d\n",i,res);
	}
	return 0;
}
