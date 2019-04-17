#include <stdio.h>
#include <queue>

uisng namespace std;

struct node{
	int c[3];
};

int S,N,M;
int cnt = 0;
queue <node> q;

node pour(int x,int y){
	node next;
	for(int i = 0;i < 3;i++)
}

void bfs(){
	node cur,next;
	while(!q.empty()){
		for(int i = 0;i < 3;i++){
			for(int j = 1;j <= 2;j++){
				if(next.s)
			}
		}
	}
	
}

int main(){
	freopen("..//data//m.in","r",stdin);
    while(~scanf("%d %d %d",&S,&N,&M) && (S||N||M)){
        //printf("%d %d %d\n",S,N,M);
        if(S%2){
        	puts("NO");
        	continue;
		}
		while(!q.empty()) q.pop();
		cnt = 0;
		node tmp;
		tmp.s[0] = S;
		tmp.s[1] = tmp.s[2] = 0;
		q.push(tmp);
		bfs();
    }
    return 0;
}
