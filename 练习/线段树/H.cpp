#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100007  //Ԫ���ܸ���
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
ll Sum[maxn<<2],Add[maxn<<2];//Sum��ͣ�AddΪ������ 
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


//�����޸� 
void Update(ll L,ll R,ll l,ll r,ll rt){//L,R��ʾ�������䣬l,r��ʾ��ǰ�ڵ����䣬rt��ʾ��ǰ�ڵ��� 
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
	PushUp(rt);//���±��ڵ���Ϣ 
}

ll Query(ll L,ll R,ll l,ll r,ll rt){//L,R��ʾ�������䣬l,r��ʾ��ǰ�ڵ����䣬rt��ʾ��ǰ�ڵ���
	if(L <= l && r <= R){
		//�������ڣ�ֱ�ӷ��� 
		return Sum[rt];
	}
	ll m=(l+r)>>1;	
	//�ۼƴ�
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
