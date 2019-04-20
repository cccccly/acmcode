#include <stdio.h>
#include <map>
#include <string.h>
using namespace std;

#define N 100005
int pre[N];     //每个结点
int rk[N];    //树的高度
int ans[N];
void printPre(int n){
	memset(ans,0,sizeof(ans));
	for(int i = 0;i < n;i++){
		printf("%d ",pre[i]);
	}
	puts("");
}

//初始化
void init(int n)     //对n个结点初始化
{
    for(int i = 1; i <= n; i++){
        pre[i] = i;     //每个结点的上级都是自己
        //rk[i] = 1;    //每个结点构成的树的高度为1
    }
}
 
//int find_pre(int x)     //查找结点x的根结点
//{
//    if(pre[x] == x){        //递归出口：x的上级为x本身，即x为根结点
//        return x;      
//    }
//    return find_pre(pre[x]);    //递归查找
//}
 
//改进查找算法：完成路径压缩，将x的上级直接变为根结点，那么树的高度就会大大降低
int find_pre(int x)     //查找结点x的根结点
{
    if(pre[x] == x){        //递归出口：x的上级为x本身，即x为根结点
        return x;      
    }
    return pre[x] = find_pre(pre[x]);   //递归查找  此代码相当于 先找到根结点rootx，然后pre[x]=rootx
}
 
 
bool is_same(int x, int y)      //判断两个结点是否连通
{
    return find_pre(x) == find_pre(y);  //判断两个结点的根结点（亦称代表元）是否相同
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
//        pre[rooty] = rootx;         //令y的根结点的上级为rootx
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
