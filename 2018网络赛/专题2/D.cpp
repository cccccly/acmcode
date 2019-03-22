#include<stdio.h>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
int a[1003],b[1003];
vector <int> c;
void fun(int r1, int l1, int r2, int l2)
{//四个参数分别为：先序遍历的起始位置和结束位置和中序遍历的起始位置和结束位置
    int i;
    if(r1>l1)//如果已经到达叶子，返回
    return;
    for(i=r2;b[i]!=a[r1];++i);//找到根节点在中序遍历中的位置
    fun(r1+1, l1-l2+i,r2,i-1);//递归求左子树的后序遍历，r1+1是指把根去掉之后的位置
    fun(l1-l2+i+1,l1,i+1,l2);//递归求右子树的后序遍历
    c.push_back(a[r1]);
//    printf("%d ",a[r1]);//在递归结束后输出根
}
int main(void)
{
    int n;
    while(cin>>n)
    {
    	for(int i = 0;i < n;i++)
    		scanf("%d",&a[i]);
    	for(int i = 0;i < n;i++)
    		scanf("%d",&b[i]);
        fun(0,n-1,0,n-1);
        for(int i = 0;i < n-1;i++){
        	printf("%d ",c[i]);
		}
        printf("%d\n",c[n-1]);
        c.clear();
    }
    return 0;
}
