#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 50007  //元素总个数
ll ls[maxn<<2],rs[maxn<<2],ms[maxn<<2]; //ls表示以左端点为起点最大连续 rs表示以右端点为终点的最大连续 ms表示整个区间的最大连续 

//Build函数建树 
void Build(ll l,ll r,ll rt){ //l,r表示当前节点区间，rt表示当前节点编号
	ls[rt] = rs[rt] = ms[rt] = r-l+1; 	
	if(l==r) {//若到达叶节点 
		return;
	}
	ll m=(l+r)>>1;
	//左右递归 
	Build(l,m,rt<<1);
	Build(m+1,r,rt<<1|1);
}


//单点修改 
void Update(ll L,ll C,ll l,ll r,ll rt){//L修改的节点下标 C是 1修复 0摧毁 
	if(l==r){//到叶节点，修改 
		if(C == 1){ //修复 
			ls[rt] = rs[rt] = ms[rt] = 1; 	
		}
		else ls[rt] = rs[rt] = ms[rt] = 0; 	
		return;
	}
	ll m=(l+r)>>1;
	//根据条件判断往左子树调用还是往右 
	if(L <= m) Update(L,C,l,m,rt<<1);
	else       Update(L,C,m+1,r,rt<<1|1);
	//更新本节点信息 
	ls[rt] = ls[rt*2];
	rs[rt] = rs[rt*2+1];
	//该节点内最大区间为，左子树区间最大值，右子树区间最大值，包括中间节点的连续值 大的 
	ms[rt] = max(max(ms[rt*2],ms[rt*2+1]),rs[rt*2]+ls[rt*2+1]);
	//若左子树的区间全连续 则父亲的ls还要加上右子树的ls 
	if(ls[rt*2] == l-m+1)
		ls[rt] += ls[rt*2+1];
	//同理右子树区间全连续 
	if(ls[rt*2+1] == l-m+1)
		rs[rt] += rs[rt*2];
}

ll Query(ll L,ll l,ll r,ll rt){//L表示询问的点，l,r表示当前节点区间，rt表示当前节点编号
	if(l == r || ms[rt] == r-l+1 || ms[rt] == 0){
		//叶结点，区间全连续，区间全不连续直接返回 
		return ms[rt];
	}
	ll m=(l+r)>>1;
	//累计答案
	ll ANS = 0;
	if(L <= m){
		if(L < m-rs[rt*2]+1)
			ANS += Query(L,l,m,rt<<1);
		else
			ANS += Query(L,l,m,rt<<1) + Query(m+1,m+1,r,rt<<1|1);
	} 
	if(L >  m){
		if(L > m+ls[rt*2+1]-1)
			ANS += Query(L,m+1,r,rt<<1|1);
		else
			ANS += Query(m,l,m,rt<<1) + Query(L,m+1,r,rt<<1|1);
	}
	return ANS;
}

int main(){
	ll n,m;
	while(~scanf("%lld %lld",&n,&m)){
		Build(1,n,1);
		char op;
		ll pos;
		stack <int> st;
		while(!st.empty()){
			st.pop();
		}
		for(int i = 1;i <= m;i++){
			scanf(" %c",&op);
			if(op == 'D'){
				scanf("%lld",&pos);
				st.push(pos);
				Update(pos,0,1,n,1);
			}
			else if(op == 'Q'){
				scanf("%lld",&pos);
				printf("%lld\n",Query(pos,1,n,1));
			}
			else{
				Update(st.top(),1,1,n,1);
				st.pop();
			}
		}
	}
	return 0;
}
