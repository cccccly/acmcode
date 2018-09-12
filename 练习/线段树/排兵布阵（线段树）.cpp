#include <bits/stdc++.h>
//https://blog.csdn.net/zearot/article/details/48299459
//https://blog.csdn.net/zearot/article/details/52280189
using namespace std;
using ll = long long;
#define maxn 100007  //元素总个数
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
int Sum[maxn<<2],Add[maxn<<2];//Sum求和，Add为懒惰标记 
int A[maxn];//存原数组数据下标[1,n]

//PushUp函数更新节点信息 ，这里是求和
void PushUp(int rt){Sum[rt]=Sum[rt<<1]+Sum[rt<<1|1];}
//Build函数建树 
void Build(int l,int r,int rt){ //l,r表示当前节点区间，rt表示当前节点编号
	if(l==r) {//若到达叶节点 
		Sum[rt]=A[l];//储存数组值 
		return;
	}
	int m=(l+r)>>1;
	//左右递归 
	Build(l,m,rt<<1);
	Build(m+1,r,rt<<1|1);
	//更新信息 
	PushUp(rt);
}

void Update(int L,int C,int l,int r,int rt){//l,r表示当前节点区间，rt表示当前节点编号
	if(l==r){//到叶节点，修改 
		Sum[rt]+=C;
		return;
	}
	int m=(l+r)>>1;
	//根据条件判断往左子树调用还是往右 
	if(L <= m) Update(L,C,l,m,rt<<1);
	else       Update(L,C,m+1,r,rt<<1|1);
	PushUp(rt);//子节点更新了，所以本节点也需要更新信息 
}

void PushDown(int rt,int ln,int rn){
	//ln,rn为左子树，右子树的数字数量。 
	if(Add[rt]){
		//下推标记 
		Add[rt<<1]+=Add[rt];
		Add[rt<<1|1]+=Add[rt];
		//修改子节点的Sum使之与对应的Add相对应 
		Sum[rt<<1]+=Add[rt]*ln;
		Sum[rt<<1|1]+=Add[rt]*rn;
		//清除本节点标记 
		Add[rt]=0;
	}
}

int Query(int L,int R,int l,int r,int rt){//L,R表示操作区间，l,r表示当前节点区间，rt表示当前节点编号
	if(L <= l && r <= R){
		//在区间内，直接返回 
		return Sum[rt];
	}
	int m=(l+r)>>1;
	//下推标记，否则Sum可能不正确
	PushDown(rt,m-l+1,r-m); 
	
	//累计答案
	int ANS=0;
	if(L <= m) ANS+=Query(L,R,l,m,rt<<1);
	if(R >  m) ANS+=Query(L,R,m+1,r,rt<<1|1);
	return ANS;
}

int main(){
	int T,n;
	scanf("%d",&T);
	for(int t = 1;t <= T;t++){
		scanf("%d",&n);
		for(int i = 1;i <= n;i++){
			scanf("%d",&A[i]);
		}
		Build(1,n,1);
		string op;
		int l,r;
		printf("Case %d:\n",t);
		while(cin>>op){
			if(op == "End")
				break;
			scanf("%d %d",&l,&r);
			if(op == "Query"){
				printf("%d\n",Query(l,r,1,n,1));
			}
			else if(op == "Add"){
				Update(l,r,1,n,1);

			}
			else {
				Update(l,-r,1,n,1);
			}
		}
	}
	return 0;
}
