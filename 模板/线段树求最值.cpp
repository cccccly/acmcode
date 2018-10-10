#include <iostream>
#include <cstdio>

using namespace std;
#define ll long long
#define maxn 50005  //元素总个数
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
#define Inf 1000005  //最小值 
int Mx[maxn<<2],Mn[maxn<<2];//保存最大值和最小值 
int A[maxn];//存原数组数据下标[1,n]

//PushUp函数更新节点信息 ，左右子树最大值 
void PushUp(int rt){
	Mx[rt]=max(Mx[rt<<1],Mx[rt<<1|1]);
	Mn[rt]=min(Mn[rt<<1],Mn[rt<<1|1]); 
}
//Build函数建树 
void Build(int l,int r,int rt){ //l,r表示当前节点区间，rt表示当前节点编号
	if(l==r) {//若到达叶节点 
		Mx[rt]=A[l];//储存数组值
		Mn[rt]=A[l]; 
		return;
	}
	int m=(l+r)>>1;
	//左右递归 
	Build(l,m,rt<<1);
	Build(m+1,r,rt<<1|1);
	//更新信息 
	PushUp(rt);
}

int QueryMx(int L,int R,int l,int r,int rt){//L,R表示操作区间，l,r表示当前节点区间，rt表示当前节点编号
	if(L <= l && r <= R){
		//在区间内，直接返回 
		return Mx[rt];
	}
	int m=(l+r)>>1;

	//累计答案
	int ANS=0;
	if(L <= m) ANS = max(ANS,QueryMx(L,R,l,m,rt<<1));
	if(R >  m) ANS = max(ANS,QueryMx(L,R,m+1,r,rt<<1|1));
	return ANS;
}

int QueryMn(int L,int R,int l,int r,int rt){//L,R表示操作区间，l,r表示当前节点区间，rt表示当前节点编号
	if(L <= l && r <= R){
		return Mn[rt];
	}
	int m=(l+r)>>1;

	//累计答案
	int ANS = Inf;
	if(L <= m) ANS = min(ANS,QueryMn(L,R,l,m,rt<<1));
	if(R >  m) ANS = min(ANS,QueryMn(L,R,m+1,r,rt<<1|1));
	return ANS;
}

int main(){
	int n,m;
//	freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
		for(int i = 1;i <= n;i++){
			scanf("%d",&A[i]);
		}
		Build(1,n,1);
		int l,r;
		for(int i = 1;i <= m;i++){
			scanf("%d %d",&l,&r);
			printf("%d\n",QueryMx(l,r,1,n,1)-QueryMn(l,r,1,n,1));
		}
	return 0;
}
