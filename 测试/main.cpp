#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define maxn 100007  //Ԫ���ܸ���
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
ll Add[maxn<<2];//Sum��ͣ�AddΪ������ 
ll A[maxn];//��ԭ���������±�[1,n]
//PushUp�������½ڵ���Ϣ �����������

struct Line{
	int l,r,c;
}line[maxn];

struct endVex{
	int pos;
	int cnt;
}edv[maxn];
void PushDown(ll rt,ll ln,ll rn){ //���Ʊ��  ln,rnΪ��������������������������
	Add[rt<<1] = Add[rt];
	Add[rt<<1|1] = Add[rt];
	//������ڵ��� 
	Add[rt]=-1;
}

//�����޸� 
void Update(ll L,ll R,ll C,ll l,ll r,ll rt){//L,R��ʾ�������䣬l,r��ʾ��ǰ�ڵ����䣬rt��ʾ��ǰ�ڵ��� 
	if(L <= l && r <= R){//�����������ȫ�ڲ�������[L,R]���� 
		Add[rt] = C;//����Add��ǣ���ʾ�������Sum��ȷ���������Sum����Ҫ����Add��ֵ������
		return ; 
	}
	ll m=(l+r)>>1;
	if(Add[rt] >= 0) PushDown(rt,m-l+1,r-m);//���Ʊ��
	//�����ж�����������[L,R]���޽������н����ŵݹ� 
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
				continue; //�������� 
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
