#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int nextval[101010];

void getnext(char p[],int next[])  //求nextval数组 p为模板串 
{
    int j=0,k=next[0]=-1;
    int len=strlen(p);
    while (j<len-1)
    {
        if(k==-1||p[k]==p[j])
            next[++j]=++k;
        else
            k = next[k];
    }
}
int kmp(char s[],char p[])
{
    int cnt=0;
    int i=0,j=0;
    int la=strlen(s),lb=strlen(p);
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
            cnt++;
            j=0;            
        }    
    }
    return cnt;
}

int main(){
	char a[1010],b[1010];
	while(cin>>a)
	{
		if(strcmp(a,"#") == 0)
			break;
		cin>>b;
		memset(nextval,0,sizeof(nextval));
		getnext(b,nextval);
		int res = kmp(a,b);
		printf("%d\n",res);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
	}
} 

