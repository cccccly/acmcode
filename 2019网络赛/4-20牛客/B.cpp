#include <stdio.h>
#include <map>
#include <string.h>
using namespace std;

#define N 100005
int pre[N];     //ÿ�����
int rk[N];    //���ĸ߶�
int ans[N];
void printPre(int n){
	memset(ans,0,sizeof(ans));
	for(int i = 0;i < n;i++){
		printf("%d ",pre[i]);
	}
	puts("");
}

//��ʼ��
void init(int n)     //��n������ʼ��
{
    for(int i = 1; i <= n; i++){
        pre[i] = i;     //ÿ�������ϼ������Լ�
        //rk[i] = 1;    //ÿ����㹹�ɵ����ĸ߶�Ϊ1
    }
}
 
//int find_pre(int x)     //���ҽ��x�ĸ����
//{
//    if(pre[x] == x){        //�ݹ���ڣ�x���ϼ�Ϊx������xΪ�����
//        return x;      
//    }
//    return find_pre(pre[x]);    //�ݹ����
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
//    if(rootx == rooty){
//        return ;
//    }
//    if(rk[rootx] > rk[rooty]){
//        pre[rooty] = rootx;         //��y�ĸ������ϼ�Ϊrootx
//    }
//    else{
//        if(rk[rootx] == rk[rooty]){
//            rk[rooty]++;
//        }
//        pre[rootx] = rooty;
//    }
	if(rootx != rooty)
		pre[x] = pre[y];
}


int main(){
	int n,m;
	//freopen("B.in","r",stdin);
	scanf("%d %d",&n,&m);
	init(n);
	int p1,p2;
	char s1[N] = {'\0'},s2[N];
	for(int i = 1;i <= m;i++){
		//printPre(n);
		//printf("%s\n",s1);
		scanf("%d %s",&p2,s2);
		if(strcmp(s1,s2) == 0){
			unite(p2,p1);
		}
		else{
			p1 = p2;
			strcpy(s1,s2);
		}
	}
	for(int i = 1;i <= n;i++){
		ans[pre[i]]++;
	}
	for(int i = 1;i <= n;i++){
		printf("%d ",ans[pre[i]] - 1);
	}
	return 0;
}
