#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100005;
const int MAXM = 200005;
const int inf = 0x3f3f3f3f;
typedef long long ll;

inline int rd(){
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)) {f=ch=='-'?0:1;ch=getchar();}
    while(isdigit(ch))  {x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return f?x:-x;
}

ll dp[MAXN][12];
bool vis[MAXN][12];
int head[MAXN],tot = 0;
int t,n,m,k;
struct Edge{    //�ߴ�0��ʼ�� 
	int to ,next;
	ll val;
}eg[MAXM];

struct Node {
    ll len;  //����ǰ��x����̾��� 
    int x,y;  //x��ǰ���±�  y��¼ʹ������ѱߵ����� 
    bool operator <(const Node &r) const {
        return len<r.len;
    }
    bool operator >(const Node &r) const {
        return r<*this;
    }
};

void dij(int S)  //SΪԴ���±� 
{
	priority_queue< Node,vector<Node>,greater<Node> > q;
	memset(dp,inf,sizeof(dp));
	memset(vis,0,sizeof(vis));
	dp[S][0]=0;  
	q.push({dp[S][0],S,0});
	while (!q.empty()){
		Node cur=q.top();
		q.pop();
		int u=cur.x,y=cur.y;
		if (y>k) continue;  //����k�򲻴��� 
		vis[u][y]=true;
		for (int i=head[u];i!=-1;i=eg[i].next) {  //�ɳڲ��� 
            int v=eg[i].to;
            if (!vis[v][y]) {  //��ǰ�߲���Ϊ��ѱ� 
                if (cur.len+eg[i].val<dp[v][y]) {
                    dp[v][y]=cur.len+eg[i].val;
                    q.push({dp[v][y],v,y});
                }
            }
            if (!vis[v][y+1]) {  //��ǰ����Ϊ��ѱ� 
                if (cur.len<dp[v][y+1]) {
                    dp[v][y+1]=cur.len;
                    q.push({dp[v][y+1],v,y+1});
                }
            }
		}
	}
}
void addEdge(int u ,int v ,int val){
	eg[tot].to = v,eg[tot].next = head[u],eg[tot].val = val,head[u] = tot++;
}

void init(){
	memset(head ,-1 ,sizeof(head));
	tot = 0;
}

int main(){
	scanf("%d",&t);
	while(t--){
		n=rd();m=rd();k=rd();
		int u,v,l;
		init(); 
	    for(int i = 1;i <= m;i++){
	    	u=rd();v=rd();l=rd();
	    	addEdge(u,v,l);
		}
		dij(1);
		printf("%lld\n",*min_element(dp[n],dp[n]+k+1));
	}
	return 0;
}
