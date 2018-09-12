#include <bits/stdc++.h>
//https://blog.csdn.net/zearot/article/details/48299459
//https://blog.csdn.net/zearot/article/details/52280189
using namespace std;
using ll = long long;
#define maxn 100007  //Ԫ���ܸ���
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
int Sum[maxn<<2],Add[maxn<<2];//Sum��ͣ�AddΪ������ 
int A[maxn];//��ԭ���������±�[1,n]

//PushUp�������½ڵ���Ϣ �����������
void PushUp(int rt){Sum[rt]=Sum[rt<<1]+Sum[rt<<1|1];}
//Build�������� 
void Build(int l,int r,int rt){ //l,r��ʾ��ǰ�ڵ����䣬rt��ʾ��ǰ�ڵ���
	if(l==r) {//������Ҷ�ڵ� 
		Sum[rt]=A[l];//��������ֵ 
		return;
	}
	int m=(l+r)>>1;
	//���ҵݹ� 
	Build(l,m,rt<<1);
	Build(m+1,r,rt<<1|1);
	//������Ϣ 
	PushUp(rt);
}

void Update(int L,int C,int l,int r,int rt){//l,r��ʾ��ǰ�ڵ����䣬rt��ʾ��ǰ�ڵ���
	if(l==r){//��Ҷ�ڵ㣬�޸� 
		Sum[rt]+=C;
		return;
	}
	int m=(l+r)>>1;
	//���������ж������������û������� 
	if(L <= m) Update(L,C,l,m,rt<<1);
	else       Update(L,C,m+1,r,rt<<1|1);
	PushUp(rt);//�ӽڵ�����ˣ����Ա��ڵ�Ҳ��Ҫ������Ϣ 
}

void PushDown(int rt,int ln,int rn){
	//ln,rnΪ�������������������������� 
	if(Add[rt]){
		//���Ʊ�� 
		Add[rt<<1]+=Add[rt];
		Add[rt<<1|1]+=Add[rt];
		//�޸��ӽڵ��Sumʹ֮���Ӧ��Add���Ӧ 
		Sum[rt<<1]+=Add[rt]*ln;
		Sum[rt<<1|1]+=Add[rt]*rn;
		//������ڵ��� 
		Add[rt]=0;
	}
}

int Query(int L,int R,int l,int r,int rt){//L,R��ʾ�������䣬l,r��ʾ��ǰ�ڵ����䣬rt��ʾ��ǰ�ڵ���
	if(L <= l && r <= R){
		//�������ڣ�ֱ�ӷ��� 
		return Sum[rt];
	}
	int m=(l+r)>>1;
	//���Ʊ�ǣ�����Sum���ܲ���ȷ
	PushDown(rt,m-l+1,r-m); 
	
	//�ۼƴ�
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
