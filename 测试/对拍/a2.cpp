#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
#define inf 0x3f3f3f3f
int n,m;
bool vis[15][15];
char grid[15][15];
int casee=0;
int ans=inf;
struct node
{
    int x,y,depth;
};
vector <node>grass;
bool check (int x,int y)
{
    if (!vis[x][y]&&grid[x][y]=='#'&&x>=0&&x<n&&y>=0&&y<m)
    return true;
    else
    return false;
}
bool judge ()
{
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            if (grid[i][j]=='#'&&!vis[i][j])
            return false;
        }
    }
    return true;
}
void init()
{
    grass.clear();
    memset(vis,false,sizeof vis);
}
int bfs (node n1,node n2)
{
    queue <node> q;
    memset(vis,false,sizeof vis);
    while (!q.empty()) q.pop();
    q.push(n1);
    q.push(n2);
    int depthest=0;
    while (!q.empty())
    {
        node now=q.front();
        q.pop();
        if (vis[now.x][now.y])
        continue;
        vis[now.x][now.y]=true;
        depthest=now.depth;
        if (check(now.x-1,now.y))
        {
            node nxt=now;
            nxt.x--;
            nxt.depth++;
            q.push(nxt);
        }
        if (check(now.x+1,now.y))
        {
            node nxt=now;
            nxt.x++;
            nxt.depth++;
            q.push(nxt);
        }
        if (check(now.x,now.y-1))
        {
            node nxt=now;
            nxt.y--;
            nxt.depth++;
            q.push(nxt);
        }
        if (check(now.x,now.y+1))
        {
            node nxt=now;
            nxt.y++;
            nxt.depth++;
            q.push(nxt);
        }
    }
    return depthest;
}
int main()
{
    freopen("data\\a.in","r",stdin);
    freopen("data\\a2.out","w",stdout);
    int t;
    scanf("%d",&t);
    while (t--)
    {
        init();
        ans=inf;
        scanf("%d%d",&n,&m);
        for (int i=0;i<n;++i)
        scanf("%s",grid[i]);
        for (int i=0;i<n;++i){
            for (int j=0;j<m;++j){
                if (grid[i][j]=='#'){
                    node g;
                    g.x=i;
                    g.y=j;
                    g.depth=0;
                    grass.push_back(g);
                }
            }
        }
        for (int i=0;i<grass.size();++i)
        {
            for (int j=i;j<grass.size();++j)
            {
                grass[i].depth=0;
                grass[j].depth=0;
                int temp=min(bfs(grass[i],grass[j]),ans);
                if (judge())
                ans=min(ans,temp);
            }
        }
        printf("Case %d: ",++casee);
        if (ans==inf)
        printf("-1\n");
        else
        printf("%d\n",ans);
    }
    return 0;
}
