#include <iostream>
#include <cstdio>

using namespace std;
#define ll long long
#define maxn 50005  //Ԫ���ܸ���
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
#define Inf 1000005  //��Сֵ 
int Mx[maxn<<2],Mn[maxn<<2];//�������ֵ����Сֵ 
int A[maxn];//��ԭ���������±�[1,n]

//PushUp�������½ڵ���Ϣ �������������ֵ 
void PushUp(int rt){
	Mx[rt]=max(Mx[rt<<1],Mx[rt<<1|1]);
	Mn[rt]=min(Mn[rt<<1],Mn[rt<<1|1]); 
}
//Build�������� 
void Build(int l,int r,int rt){ //l,r��ʾ��ǰ�ڵ����䣬rt��ʾ��ǰ�ڵ���
	if(l==r) {//������Ҷ�ڵ� 
		Mx[rt]=A[l];//��������ֵ
		Mn[rt]=A[l]; 
		return;
	}
	int m=(l+r)>>1;
	//���ҵݹ� 
	Build(l,m,rt<<1);
	Build(m+1,r,rt<<1|1);
	//������Ϣ 
	PushUp(rt);
}

int QueryMx(int L,int R,int l,int r,int rt){//L,R��ʾ�������䣬l,r��ʾ��ǰ�ڵ����䣬rt��ʾ��ǰ�ڵ���
	if(L <= l && r <= R){
		//�������ڣ�ֱ�ӷ��� 
		return Mx[rt];
	}
	int m=(l+r)>>1;

	//�ۼƴ�
	int ANS=0;
	if(L <= m) ANS = max(ANS,QueryMx(L,R,l,m,rt<<1));
	if(R >  m) ANS = max(ANS,QueryMx(L,R,m+1,r,rt<<1|1));
	return ANS;
}

int QueryMn(int L,int R,int l,int r,int rt){//L,R��ʾ�������䣬l,r��ʾ��ǰ�ڵ����䣬rt��ʾ��ǰ�ڵ���
	if(L <= l && r <= R){
		return Mn[rt];
	}
	int m=(l+r)>>1;

	//�ۼƴ�
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
