#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int nextval[101010];
int a[1000010],b[10010];
void getnext(int p[],int next[],int len)  //求nextval数组 p为模板串 
{
    int j=0,k=next[0]=-1;
    while (j<len-1)
    {
        if(k==-1||p[k]==p[j])
            next[++j]=++k;
        else
            k = next[k];
    }
}
int kmp(int s[],int p[],int la,int lb)
{
    int res=-1;   //记录首次出现的位置 
    int i=0,j=0;
//   int la=strlen(s),lb=strlen(p);
    while (i<la&&j<lb)
    {
        if(j==-1||s[i]==p[j])
        {
            i++;
            j++;
        }
        else
            j=nextval[j];
        if(j==lb)
        {
        	res = i-lb+1;
            return res;        
        }    
    }
    return res;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int la,lb;
		scanf("%d%d",&la,&lb);
		for(int i = 0;i < la;i++)
			scanf("%d",&a[i]);
		for(int i = 0;i < lb;i++)
			scanf("%d",&b[i]);
		memset(nextval,0,sizeof(nextval));
		getnext(b,nextval,lb);
		int res = kmp(a,b,la,lb);
		printf("%d\n",res);
	}
} 

