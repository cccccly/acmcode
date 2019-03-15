#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;
#define N 100010
int step[N],vis[N];
queue<int>q;
int bfs(int n,int k){
    int now,next;
    step[n]=0;
    vis[n]=1;
    q.push(n);
    while(!q.empty()){
        now=q.front();
        q.pop();
        for(int i=0;i<3;i++){
            if(i==0) next=now-1;
            else if(i==1) next=now+1;
            else if(i==2) next=now*2;
            if(next<0||next>N) continue;
            if(!vis[next]){
                vis[next]=1;
                q.push(next);
                step[next]=step[now]+1; 
            }
            if(next==k) return step[next];
        }
    }
}
int main(){
	
	#ifdef ONLINE_JUDGE
	#else
	    freopen("c.in","r",stdin);
	    freopen("c1.out","w",stdout);
	#endif
	
    int n,k;
    scanf("%d%d",&n,&k);
	memset(vis,0,sizeof(vis));
	memset(step,0,sizeof(step));
	while(!q.empty()){
		q.pop();
	}
	if(n>=k) printf("%d\n",n-k);  
	else printf("%d\n",bfs(n,k));
	
    return 0;
}
