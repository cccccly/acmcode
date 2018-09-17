#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define maxn 100007  //元素总个数
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
ll Add[maxn<<2];//Sum求和，Add为懒惰标记 
ll A[maxn];//存原数组数据下标[1,n]
//PushUp函数更新节点信息 ，这里是求和

struct Line{
	int l,r,c;
}line[maxn];

struct endVex{
	int pos;
	int cnt;
}edv[maxn];
void PushDown(ll rt,ll ln,ll rn){ //下推标记  ln,rn为左子树，右子树的数字数量。
	Add[rt<<1] = Add[rt];
	Add[rt<<1|1] = Add[rt];
	//清除本节点标记 
	Add[rt]=-1;
}

//区间修改 
void Update(ll L,ll R,ll C,ll l,ll r,ll rt){//L,R表示操作区间，l,r表示当前节点区间，rt表示当前节点编号 
	if(L <= l && r <= R){//如果本区间完全在操作区间[L,R]以内 
		Add[rt] = C;//增加Add标记，表示本区间的Sum正确，子区间的Sum仍需要根据Add的值来调整
		return ; 
	}
	ll m=(l+r)>>1;
	if(Add[rt] >= 0) PushDown(rt,m-l+1,r-m);//下推标记
	//这里判断左右子树跟[L,R]有无交集，有交集才递归 
	if(L <= m) Update(L,R,C,l,m,rt<<1);
	if(R >  m) Update(L,R,C,m+1,r,rt<<1|1); 
}

void Query(ll l,ll r,ll rt){
	if(Add[rt] >= 0){
		if(l != edv[Add[rt]].pos){
			edv[Add[rt]].cnt++;
		}
		if(edv[Add[rt]].cnt == 0)
			edv[Add[rt]].cnt++;
		edv[Add[rt]].pos = r+1;
		return ;
	}
	if(l == r){
		return ;
	}
	ll m=(l+r)>>1;
	Query(l,m,rt<<1);
	Query(m+1,r,rt<<1|1);
}

int main(){
	int n,l,r,c;
//	freopen("in.txt","r",stdin);
	while(~scanf("%d",&n)){
		memset(Add, -1, sizeof(Add));
		memset(edv, 0 ,sizeof(edv));
		int mx = 0;
		for(int i = 0;i < n;i++){
			scanf("%d %d %d",&line[i].l,&line[i].r,&line[i].c);
			mx = max(mx,line[i].r - 1);
		}
		for(int i = 0;i < n;i++){
			if(line[i].l == line[i].r)
				continue; //错误输入 
			Update(line[i].l,line[i].r-1,line[i].c,0,mx,1);
		}
		Query(0,mx,1);
		for(int i = 0;i < 8010;i++){
			if(edv[i].cnt){
				printf("%d %d\n",i,edv[i].cnt);
			}
		}
		puts("");
	}
	return 0;
}
