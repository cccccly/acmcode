#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;
#define maxn 10007
int prime[maxn];
bool is_prime[maxn];
bool vis[maxn];
int start,ed,res,count;

struct node{
	int num,step;
};

queue <node> Q;

int init(){
	int p = 0;
	for(int i = 0;i <= 9999;i++){   //假定都是素数，然后筛掉其中的合数 
		is_prime[i] = 1;
	}
	is_prime[0] = is_prime[1] = 0;
	
	for(int i = 2;i <= 9999;i++){
		if(is_prime[i]){
			if(i >= 1000)
				prime[p++] = i;
			for(int j = 2;j*i <= 9999;j++){
				is_prime[j*i] = 0;
			}
//			for(int j = 2*i;j <= 9999;j += i){
//				is_prime[j] = 0;
//			} 
		}
	}
	return p;
}

bool judge(int src,int dest){
	int cnt = 0;
	for(int i = 0;i < 4;i++){
		if(src % 10 != dest % 10)
			cnt++;
		src /= 10,dest /= 10; 
	}
	if(cnt == 1)
		return 1;
	else return 0;
}

void bfs(){
	node cur,next;
	cur.num = start;
	cur.step = 0;
	Q.push(cur);
	while(!Q.empty()){
		cur = Q.front();
		Q.pop();
		if(cur.num == ed){
			res = cur.step;
			return ;
		}		
		for(int i = 0;i < count;i++){
			if(!vis[i] && judge(cur.num, prime[i])){
				next.num = prime[i];
				next.step = cur.step+1;
				vis[i] = 1;
				Q.push(next);
			}
		}
	}
	return ;
}


int main(){
	int n;
	count = init();  //素数个数 
	scanf("%d",&n);
	while(n--){
		while(!Q.empty())
			Q.pop();
		res = -1;
		memset(vis,0,sizeof(vis));
		scanf("%d %d",&start,&ed);
		bfs();
		if(res == -1)
			puts("Impossible");
		else 
			printf("%d\n",res);
	}
	
//	for(int i = 0;i < count;i++)
//		printf("%d ",prime[i]);
	return 0;
}
