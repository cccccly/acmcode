#include <stdio.h>
#include <set>
#include <string.h>
using namespace std;

#define N 100005
int pre[N];     //ÿ�����
int rk[N];    //���ĸ߶�
//set <int> ans;
void printPre(int n){
	for(int i = 1;i <= n;i++){
		printf("%d ",pre[i]);
	}
	puts("");
}

//��ʼ��
void init(int n)     //��n������ʼ��
{
    for(int i = 1; i <= n; i++){
        pre[i] = i;     //ÿ�������ϼ������Լ�
        rk[i] = 1;    //ÿ����㹹�ɵ����ĸ߶�Ϊ1
    }
//    ans.clear();
}
 
//int find_pre(int x)     //���ҽ��x�ĸ����
//{
//    if(pre[x] == x){        //�ݹ���ڣ�x���ϼ�Ϊx������xΪ�����
//        return x;      
//    }
//    return find_pre(pre[x]);    //�ݹ����
//	while(pre[x] != x)
//		x = pre[x];
//	return x;
//}
 
//�Ľ������㷨�����·��ѹ������x���ϼ�ֱ�ӱ�Ϊ����㣬��ô���ĸ߶Ⱦͻ��󽵵�
int find_pre(int x)     //���ҽ��x�ĸ����
{
    if(pre[x] == x){        //�ݹ���ڣ�x���ϼ�Ϊx������xΪ�����
        return x;      
    }
    return pre[x] = find_pre(pre[x]);   //�ݹ����  �˴����൱�� ���ҵ������rootx��Ȼ��pre[x]=rootx
}
 
 
bool is_same(int x, int y)      //�ж���������Ƿ���ͨ
{
    return find_pre(x) == find_pre(y);  //�ж��������ĸ���㣨��ƴ���Ԫ���Ƿ���ͬ
}
 
void unite(int x,int y)
{
    int rootx, rooty;
    rootx = find_pre(x);
    rooty = find_pre(y);
//    if(rootx != rooty)
//    	pre[rootx] = rooty;
    if(rootx == rooty){
        return ;
    }
    if(rk[rootx] > rk[rooty]){
        pre[rooty] = rootx;         //��y�ĸ������ϼ�Ϊrootx
    }
    else{
        if(rk[rootx] == rk[rooty]){
            rk[rooty]++;
        }
        pre[rootx] = rooty;
    }
}


int main(){
	int n,m;
	//freopen("B.in","r",stdin);
	while(1){
		scanf("%d",&n);
		if(n == 0)
			break;
		scanf("%d",&m);
		init(n);
		int tmp1,tmp2; 
		for(int i = 1;i <= m;i++){
			scanf("%d %d",&tmp1,&tmp2);
			unite(tmp1,tmp2);
		}
		int ans = 0;
		for(int i = 1;i <= n;i++){
			if(pre[i] == i)
				ans++;
		}
		printf("%d\n",ans - 1);
	}
	return 0;
}
