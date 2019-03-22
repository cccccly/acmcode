#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<sstream>
#include<cstring>
#include<cstdio>
#include<string>
#include<deque>
#include<cmath>
#include<queue>
#include<set>
#include<map>
using namespace std;
typedef long long LL;
int nextval[101010];
void getnext(char s[],int next[])
{
    int j=0,k=next[0]=-1;
    int len=strlen(s);
while (j<len-1)
{if(k==-1||s[k]==s[j])next[++j]=++k;¡¡¡¡
        else
            k=next[k];
    }
}
int sea(char s[],char t[])
{
    int cnt=0;
    int i=0,j=0;
    int la=strlen(s),lb=strlen(t);
    while (i<la&&j<lb)
    {
        if(j==-1||s[i]==t[j])
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
int main(void)
{
    char a[1010]={0},b[1010]={0};
    while (cin>>a)
    {
        if(strcmp(a,"#")==0)
        {
            break;
        }
        cin>>b;
        memset(nextval,0,sizeof(nextval));        
        getnext(b,nextval);
        cout<<sea(a,b)<<endl;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
    }
    return 0;
}

