#include<bits/stdc++.h>
using namespace std;
const int MAXN=55;
char A[MAXN],B[MAXN],C[MAXN];
int main()
{
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++)
    {
        scanf("%*d%*d");
        scanf("%s%s%s",A,B,C);
        int ost=(A[0]-B[0]+26)%26;
        for(int i=0;C[i];i++)
            C[i]=(C[i]-'A'+ost)%26+'A';
        printf("Case #%d: %s\n",ca,C);
    }
    return 0;
}
