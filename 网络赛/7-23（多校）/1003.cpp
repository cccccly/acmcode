#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct point{
    int x;
    int index;
}p[100003];

bool cmp(point a,point b){
    return a.x < b.x;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int x,y;
        for(int i = 1;i <= 3*n;i++){
            scanf("%d %d",&x,&y);
            p[i].index = i;
            p[i].x = x;
        }
        sort(p+1,p+1+3*n,cmp);
        for(int i = 1;i <= n;i++){
            printf("%d %d %d\n",p[(i-1)*3+1].index,p[(i-1)*3+2].index,p[(i-1)*3+3].index);
        }
    }
    return 0;
} 
