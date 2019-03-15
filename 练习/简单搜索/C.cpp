#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;
#define maxn 100010

struct node{
	int x,step;
};
int N,K;
int vis[maxn];

int check(int temp){
	if(temp >= 0 &&temp <= maxn&& vis[temp] == 0)
		return 1;
	else return 0;
}


queue <node> q;
int bfs(){
	
	node cur,next;
	
	cur.x = N;
	cur.step = 0;
	vis[N] = 1;
	
	q.push(cur);
	while(!q.empty()){
		cur = q.front();
		q.pop();
		
		for(int i = 0;i < 3;i++){
			if(i == 0) next.x = cur.x - 1;
			else if(i == 1) next.x = cur.x + 1;
			else next.x = cur.x * 2;
			if(check(next.x)){
				next.step = cur.step + 1;
				vis[next.x] = 1;
				q.push(next);
			}
			if(next.x == K)
					return next.step;
		}

	}
}

int main(){
	
	#ifdef ONLINE_JUDGE
	#else
	    freopen("c.in","r",stdin);
	    freopen("c.out","w",stdout);
	#endif
	
	scanf("%d %d",&N,&K);
	memset(vis,0,sizeof(vis));
	if(N >= K)
		printf("%d\n",N-K);
	else printf("%d\n",bfs());
	
	
	
	return 0;
}
