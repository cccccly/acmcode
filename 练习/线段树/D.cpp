#include <iostream>
#include <string.h>
#include <cstdio> 
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long
#define maxn 10007  //总共区间数 
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
ll Add[maxn<<4];
int lisan[40007];
bool visit [10007];
struct line{
	int x,y;
}Line[maxn]; 

void PushDown(ll rt,ll ln,ll rn){ //下推标记  ln,rn为左子树，右子树的数字数量。
	Add[rt<<1] = Add[rt];
	Add[rt<<1|1] = Add[rt];
	//清除本节点标记 
	Add[rt] = 0;
}

void Update(ll L,ll R,ll C,ll l,ll r,ll rt){//L,R表示操作区间，l,r表示当前节点区间，rt表示当前节点编号 
	if(L <= l && r <= R){//如果本区间完全在操作区间[L,R]以内 
		Add[rt] = C;//增加Add标记，表示本区间的Sum正确，子区间的Sum仍需要根据Add的值来调整
		return ; 
	}
	ll m=(l+r)>>1;
	if(Add[rt]) PushDown(rt,m-l+1,r-m);//下推标记
	//这里判断左右子树跟[L,R]有无交集，有交集才递归 
	if(L <= m) Update(L,R,C,l,m,rt<<1);
	if(R >  m) Update(L,R,C,m+1,r,rt<<1|1); 
}

int ANS = 0;
void Query(ll l,ll r,ll rt){//L,R表示操作区间，l,r表示当前节点区间，rt表示当前节点编号	
	if(Add[rt]){
		if(!visit[Add[rt]]){
			ANS++;
			visit[Add[rt]] = 1;
		}
		return ;
	}	
	if(l == r){ //最底端返回 
		return ;
	}
	ll m = (l+r)>>1;
	Query(l,m,rt<<1);
	Query(m+1,r,rt<<1|1);
}

int main(){
	int T,n;
//	freopen("in.txt","r",stdin);
	scanf("%d",&T);
	while(T--){
		memset(Add,0,sizeof(Add));
		memset(visit,0,sizeof(visit));
		visit[0] = 1;
		ANS = 0;
		scanf("%d",&n);
		int cnt = 0;
		for(int i = 1;i <= n;i++){
			scanf("%d %d",&Line[i].x,&Line[i].y);
			lisan[cnt++] = Line[i].x;
			lisan[cnt++] = Line[i].y;
		} 
		sort(lisan,lisan+cnt);
		int m = unique(lisan,lisan+cnt)-lisan;
		int t = m;
		for(int i = 1;i < t;i++){
			if(lisan[i]-lisan[i-1] > 1)
				lisan[m++] = lisan[i-1]+1;
		}
		sort(lisan,lisan+m);
		int x,y;
		for(int i = 1;i <= n;i++){
			x = lower_bound(lisan,lisan+m,Line[i].x)-lisan+1;
			y = lower_bound(lisan,lisan+m,Line[i].y)-lisan+1;
			Update(x,y,i,1,m,1);
		}
		Query(1,m,1);
		printf("%d\n",ANS);
	}
	return 0;
}
