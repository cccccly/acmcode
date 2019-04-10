#include <stdio.h>
#include <stack>
#include <string.h>

using namespace std;
int m,n,cnt;
char maze[110][110];
bool vis[110][110];
int dx[8] = {1,-1,0,0};
int dy[8] = {0,0,1,-1};

void init(){
    for(int i = 0;i < m;i++){
        scanf("%s",maze[i]);
    }
    memset(vis,0,sizeof(vis));
    cnt = 0;
}

void printAll(){
    for(int i = 0;i < m;i++){
        printf("%s\n",maze[i]);
    }
    puts("");
}

void dfs(int i,int j){

}

int main(){
    freopen("data//in.txt","r",stdin);
    while(~scanf("%d %d",&m,&n)){
        if(m == 0 && n == 0){
            break;
        }
        init();
        //printAll();
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(vis[i][j] == 1 || maze[i][j] == '*')
                    continue;
                dfs(i,j);
                cnt++;
            }
        }
    }
    return 0;
}