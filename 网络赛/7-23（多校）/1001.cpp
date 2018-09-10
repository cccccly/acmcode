#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        if(n%3 == 0){
            ll temp = n/3;
            printf("%lld\n",(ll)temp*temp*temp);
            continue;
        }
        else if(n%4 == 0){
            ll a = n/4;
            ll b = n/2;
            printf("%lld\n",(ll)a*a*b);
            continue;
        }
        else puts("-1");
    }
    return 0;
} 
