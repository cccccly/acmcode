#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100007  //Ԫ���ܸ���
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
ll Add[maxn<<2];//Sum��ͣ�AddΪ������ 
ll A[maxn];//��ԭ���������±�[1,n]

//PushUp�������½ڵ���Ϣ �����������
void PushUp(ll rt){
	Sum[rt]=Sum[rt<<1]+Sum[rt<<1|1];
}
//Build�������� 
void Build(ll l,ll r,ll rt){ //l,r��ʾ��ǰ�ڵ����䣬rt��ʾ��ǰ�ڵ���
	Add[rt] = 0;
	if(l==r) {//������Ҷ�ڵ� 
		Sum[rt]=A[l];//��������ֵ 
		return;
	}
	ll m=(l+r)>>1;
	//���ҵݹ� 
	Build(l,m,rt<<1);
	Build(m+1,r,rt<<1|1);
	//������Ϣ 
	PushUp(rt);
}

void PushDown(ll rt,ll ln,ll rn){ //���Ʊ��  ln,rnΪ��������������������������
	Add[rt<<1] = Add[rt];
	Add[rt<<1|1] = Add[rt];
	//�޸��ӽڵ��Sumʹ֮���Ӧ��Add���Ӧ 
	Sum[rt<<1] =Add[rt]*ln;
	Sum[rt<<1|1] =Add[rt]*rn;
	//������ڵ��� 
	Add[rt]=0;
}



//�����޸� 
void Update(ll L,ll R,ll C,ll l,ll r,ll rt){//L,R��ʾ�������䣬l,r��ʾ��ǰ�ڵ����䣬rt��ʾ��ǰ�ڵ��� 
	if(L <= l && r <= R){//�����������ȫ�ڲ�������[L,R]���� 
		Sum[rt]+=C*(r-l+1);//�������ֺͣ����ϱ�����ȷ
		Add[rt]+=C;//����Add��ǣ���ʾ�������Sum��ȷ���������Sum����Ҫ����Add��ֵ������
		return ; 
	}
	ll m=(l+r)>>1;
	if(Add[rt]) PushDown(rt,m-l+1,r-m);//���Ʊ��
	//�����ж�����������[L,R]���޽������н����ŵݹ� 
	if(L <= m) Update(L,R,C,l,m,rt<<1);
	if(R >  m) Update(L,R,C,m+1,r,rt<<1|1); 
	PushUp(rt);//���±��ڵ���Ϣ 
}



ll Query(ll L,ll R,ll l,ll r,ll rt){//L,R��ʾ�������䣬l,r��ʾ��ǰ�ڵ����䣬rt��ʾ��ǰ�ڵ���
	if(L <= l && r <= R){
		//�������ڣ�ֱ�ӷ��� 
		return Sum[rt];
	}
	ll m=(l+r)>>1;
	//���Ʊ�ǣ�����Sum���ܲ���ȷ
	PushDown(rt,m-l+1,r-m); 
	
	//�ۼƴ�
	ll ANS=0;
	if(L <= m) ANS+=Query(L,R,l,m,rt<<1);
	if(R >  m) ANS+=Query(L,R,m+1,r,rt<<1|1);
	return ANS;
}

int main(){
	ll n;
	while(~scanf("%d",&n)){
		scanf("%lld",&n);
		for(int i = 1;i <= n;i++){
			scanf("%lld",&A[i]);
		}
		Build(1,n,1);
		string op;
		ll l,r;
		printf("Case %d:\n",t);
		while(cin>>op){
			if(op == "End")
				break;
			scanf("%lld %lld",&l,&r);
			if(op == "Query"){
				printf("%lld\n",Query(l,r,1,n,1));
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
