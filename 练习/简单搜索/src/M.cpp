#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;

struct node{
	int c[3],step;
};

int C[3];
bool vis[101][101][101];
int cnt = 0;
queue <node> q;

void printN(node tmp){
	printf("%d %d %d %d\n",tmp.c[0],tmp.c[1],tmp.c[2],tmp.step);
}



int bfs(){
	node cur,next;
	while(!q.empty()){
		cur = q.front();
		//printN(cur);
		q.pop();
		for(int i = 0;i < 3;i++){
			for(int j = 1;j <= 2;j++){
				next = cur;
				int k = (i+j)%3;
				if(cur.c[i] + cur.c[k] > C[k]){
					next.c[k] = C[k];
					next.c[i] = cur.c[i] + cur.c[k] - C[k];
				}
				else{
					next.c[k] = cur.c[i] + cur.c[k];
					next.c[i] = 0;
				}
				if(vis[next.c[0]][next.c[1]][next.c[2]])
					continue;
				vis[next.c[0]][next.c[1]][next.c[2]] = 1;
				next.step++;
				//printN(next);
				if(next.c[i] == C[0]/2){
					if(next.c[(i+1)%3] == C[0]/2 || next.c[(i+2)%3] == C[0]/2)
						return next.step;
					else return next.step+1;
				}
				else if(next.c[k] == C[0]/2){
					if(next.c[(k+1)%3] == C[0]/2 || next.c[(k+2)%3] == C[0]/2)
						return next.step;
					else return next.step+1;
				}	
				q.push(next);
			}
		}
	}
	return 0;
}

int main(){
	freopen("..//data//m.in","r",stdin);
    while(~scanf("%d %d %d",&C[0],&C[1],&C[2]) && (C[0]||C[1]||C[2])){
        //printf("%d %d %d\n",S,N,M);
        if(C[0]%2){
        	puts("NO");
        	continue;
		}
		while(!q.empty()) q.pop();
		cnt = 0;
		memset(vis,0,sizeof(vis));
		node tmp;
		tmp.c[0] = C[0];
		tmp.c[1] = tmp.c[2] = 0;
		vis[tmp.c[0]][tmp.c[1]][tmp.c[2]] = 1;
		tmp.step = 0;
		q.push(tmp);
		int ans = bfs();
		if(ans!=0)
			printf("%d\n",ans);
		else puts("NO");
    }
    return 0;
}
