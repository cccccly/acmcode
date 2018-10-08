#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 50007  //Ԫ���ܸ���
ll ls[maxn<<2],rs[maxn<<2],ms[maxn<<2]; //ls��ʾ����˵�Ϊ���������� rs��ʾ���Ҷ˵�Ϊ�յ��������� ms��ʾ���������������� 

//Build�������� 
void Build(ll l,ll r,ll rt){ //l,r��ʾ��ǰ�ڵ����䣬rt��ʾ��ǰ�ڵ���
	ls[rt] = rs[rt] = ms[rt] = r-l+1; 	
	if(l==r) {//������Ҷ�ڵ� 
		return;
	}
	ll m=(l+r)>>1;
	//���ҵݹ� 
	Build(l,m,rt<<1);
	Build(m+1,r,rt<<1|1);
}


//�����޸� 
void Update(ll L,ll C,ll l,ll r,ll rt){//L�޸ĵĽڵ��±� C�� 1�޸� 0�ݻ� 
	if(l==r){//��Ҷ�ڵ㣬�޸� 
		if(C == 1){ //�޸� 
			ls[rt] = rs[rt] = ms[rt] = 1; 	
		}
		else ls[rt] = rs[rt] = ms[rt] = 0; 	
		return;
	}
	ll m=(l+r)>>1;
	//���������ж������������û������� 
	if(L <= m) Update(L,C,l,m,rt<<1);
	else       Update(L,C,m+1,r,rt<<1|1);
	//���±��ڵ���Ϣ 
	ls[rt] = ls[rt*2];
	rs[rt] = rs[rt*2+1];
	//�ýڵ����������Ϊ���������������ֵ���������������ֵ�������м�ڵ������ֵ ��� 
	ms[rt] = max(max(ms[rt*2],ms[rt*2+1]),rs[rt*2]+ls[rt*2+1]);
	//��������������ȫ���� ���׵�ls��Ҫ������������ls 
	if(ls[rt*2] == l-m+1)
		ls[rt] += ls[rt*2+1];
	//ͬ������������ȫ���� 
	if(ls[rt*2+1] == l-m+1)
		rs[rt] += rs[rt*2];
}

ll Query(ll L,ll l,ll r,ll rt){//L��ʾѯ�ʵĵ㣬l,r��ʾ��ǰ�ڵ����䣬rt��ʾ��ǰ�ڵ���
	if(l == r || ms[rt] == r-l+1 || ms[rt] == 0){
		//Ҷ��㣬����ȫ����������ȫ������ֱ�ӷ��� 
		return ms[rt];
	}
	ll m=(l+r)>>1;
	//�ۼƴ�
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
