#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100007  //元素总个数
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
ll Sum[maxn<<2],Add[maxn<<2];//Sum求和，Add为懒惰标记 
ll A[maxn];//存原数组数据下标[1,n]

//PushUp函数更新节点信息 ，这里是求和
void PushUp(ll rt){
	Sum[rt]=Sum[rt<<1]+Sum[rt<<1|1];
}
//Build函数建树 
void Build(ll l,ll r,ll rt){ //l,r表示当前节点区间，rt表示当前节点编号
	Add[rt] = 0;
	if(l==r) {//若到达叶节点 
		Sum[rt]=A[l];//储存数组值
		return;
	}
	ll m=(l+r)>>1;
	//左右递归 
	Build(l,m,rt<<1);
	Build(m+1,r,rt<<1|1);
	//更新信息 
	PushUp(rt);
}


//区间修改 
void Update(ll L,ll R,ll l,ll r,ll rt){//L,R表示操作区间，l,r表示当前节点区间，rt表示当前节点编号 
	if(r-l+1 == Sum[rt]){
		return ;
	}
	if(l == r){
		Sum[rt] = sqrt(Sum[rt]);
		return ; 
	}
	ll m=(l+r)>>1;

	if(L <= m) Update(L,R,l,m,rt<<1);
	if(R >  m) Update(L,R,m+1,r,rt<<1|1); 
	PushUp(rt);//更新本节点信息 
}

ll Query(ll L,ll R,ll l,ll r,ll rt){//L,R表示操作区间，l,r表示当前节点区间，rt表示当前节点编号
	if(L <= l && r <= R){
		//在区间内，直接返回 
		return Sum[rt];
	}
	ll m=(l+r)>>1;	
	//累计答案
	ll ANS=0;
	if(L <= m) ANS+=Query(L,R,l,m,rt<<1);
	if(R >  m) ANS+=Query(L,R,m+1,r,rt<<1|1);
	return ANS;
}

int main(){
	ll n;
	int t = 0;
	while(~scanf("%lld",&n)){
		for(int i = 1;i <= n;i++){
			scanf("%lld",&A[i]);
		}
		ll q;
		scanf("%lld",&q);
		Build(1,n,1);
		ll op,l,r;
		printf("Case #%d:\n",++t);
		for(int i = 1;i <= q;i++){
			scanf("%lld %lld %lld",&op,&l,&r);
			if(l > r){
				l = l ^ r;
				r = l ^ r;
				l = l ^ r;
			}
			if(op == 1){
				printf("%lld\n",Query(l,r,1,n,1));
			}
			else if(op == 0){
				Update(l,r,1,n,1);
			}
		}
		puts("");
	}
	return 0;
}
