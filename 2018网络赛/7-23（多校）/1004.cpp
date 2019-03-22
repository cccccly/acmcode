#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define MAXN 100000+3

struct point{
	int l,r;
	bool vis;
}p[MAXN]; 

int res [MAXN];
//按起点排序，相同起点长度长的靠前
bool cmp(point a,point b){   	 
	if(a.l != b.l)
		return a.l < b.l;
	else return (a.r - a.l) > (b.r - b.l);
}

//去重
void rmDuplication(int m){
	sort(p+1,p+1+m,cmp);
	int last = p[1].r;  //第一个总不会被去掉 
	for(int i = 2;i <= m;i++){
		if(p[i].r <= last){
			p[i].vis = 1;  //标记不用 
		}
		else last = p[i].r;
	}
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
    	int n,m;
    	memset(res,0,sizeof(res));
    	scanf("%d %d",&n,&m);
    	for(int i = 1;i <= m;i++){
    		scanf("%d %d",&p[i].l,&p[i].r);
    		p[i].vis = 0;
		}
		rmDuplication(m);
		
		priority_queue <int,vector<int>,greater<int> >pq;  //从小到大 
		for(int i = 1;i <= n;i++)
			pq.push(i);
		int last_l=1,last_r=0;
		for(int i = 1;i <= m;i++){
			if(p[i].vis)
				continue;
			for(int j = last_l;j <= p[i].l-1;j++){
				if(res[j] != 0)
					pq.push(res[j]);
			}
			for(int j = max(last_r+1,p[i].l);j <= p[i].r;j++){
				if(res[j] == 0){
					res[j] = pq.top();
					pq.pop();
				}
			}
			last_l = p[i].l;
			last_r = p[i].r;
		}
		for(int i = 1;i <= n-1;i++){
			if(res[i]!=0)
				printf("%d ",res[i]);
			else
				printf("1 ");
		}
		if(res[n]!=0)
			printf("%d\n",res[n]);
		else
			printf("1\n");	
	}
    return 0;
} 
