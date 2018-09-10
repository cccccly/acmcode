#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        printf("Case #%d: %.6f %.6f\n",ca,(n==1 ? 1.0 : 0.5),1.0*(m+1)/(2*m));
    }
    return 0;
}

