#include<stdio.h>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
int a[1003],b[1003];
vector <int> c;
void fun(int r1, int l1, int r2, int l2)
{//�ĸ������ֱ�Ϊ�������������ʼλ�úͽ���λ�ú������������ʼλ�úͽ���λ��
    int i;
    if(r1>l1)//����Ѿ�����Ҷ�ӣ�����
    return;
    for(i=r2;b[i]!=a[r1];++i);//�ҵ����ڵ�����������е�λ��
    fun(r1+1, l1-l2+i,r2,i-1);//�ݹ����������ĺ��������r1+1��ָ�Ѹ�ȥ��֮���λ��
    fun(l1-l2+i+1,l1,i+1,l2);//�ݹ����������ĺ������
    c.push_back(a[r1]);
//    printf("%d ",a[r1]);//�ڵݹ�����������
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
