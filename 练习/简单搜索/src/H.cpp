#include <stdio.h>
#include <queue>
using namespace std;
struct node{
	int x,y,dir,step;
};

int a,b,c;
int vis[110][110] = {0};
node road[110][110];  //0-fill(1) 5-pour(2,1)


queue <node> q;
node bfs(){
	node cur,next;
	cur.x = 0;
	cur.y = 0;
	cur.step = 0;
	cur.dir = -1;
	q.push(cur);
	while(!q.empty()){
		cur = q.front();
		q.pop();
		for(int i = 0;i < 6;i++){
			if(i == 0){
				next.x = a;
				next.y = cur.y;
			}
			else if(i == 1){
				next.x = cur.x;
				next.y = b;
			}
			else if(i == 2){
				next.x = 0;
				next.y = cur.y;
			}
			else if(i == 3){
				next.x = cur.x;
				next.y = 0;
			}
			else if(i == 4){
				if(cur.x <= b-cur.y){
					next.x = 0;
					next.y = cur.x+cur.y;
				}
				else{
					next.x = cur.x-b+cur.y;
					next.y = b;
				}
			}
			else if(i == 5){
				if(cur.y <= a-cur.x){
					next.x = cur.x+cur.y;
					next.y = 0;
				}
				else{
					next.x = a;
					next.y = cur.x+cur.y-a;
				}
			}
			if(vis[next.x][next.y])
				continue;
			vis[next.x][next.y] = 1;
			next.step = cur.step+1;
			next.dir = i;
			road[next.x][next.y].x = cur.x;
			road[next.x][next.y].y = cur.y;
			road[next.x][next.y].dir = i;
			if(next.x == c || next.y == c){
				return next;
			}
			q.push(next);
		}
	}
	return node{-1,-1,-1,-1};
}

void dfs(node cur){
	if(cur.x == 0 && cur.y == 0)
		return;
	node next;
	next = road[cur.x][cur.y];
	dfs(next);
	int i = next.dir;
	if(i == 0){
		puts("FILL(1)");
	}
	else if(i == 1){
		puts("FILL(2)");
	}
	else if(i == 2){
		puts("DROP(1)");
	}
	else if(i == 3){
		puts("DROP(2)");
	}
	else if(i == 4){
		puts("POUR(1,2)");
	}
	else if(i == 5){
		puts("POUR(2,1)");
	}
}

int main(){
	scanf("%d %d %d",&a,&b,&c);
	node temp = bfs();
	if(temp.x == -1)
		puts("impossible");
	else {
		printf("%d\n",temp.step);
		dfs(temp);
	}
	return 0;
} 
