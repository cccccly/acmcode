#include <stdio.h>
#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
#define LL long long

const int MAXV=100000+3;
int V, deg[MAXV];

int main()
{
    int T_T;
    scanf("%d", &T_T);
    while(T_T--)
    {
    	LL sum=0;
        scanf("%d", &V);
        for(int i=1;i<=V;++i){
        	scanf("%d", &deg[i]);
        	sum+=deg[i];
		}
        if(sum%2){
        	puts("N");
        	continue;
		}
		sort(deg+1, deg+V+1, greater<int>());
		LL pre_sum = 0,bac_sum = 0;
		int flag = V;
        bool ok=true;
        for(int i=1;i<=V;++i)
        {
            pre_sum+=deg[i];
            while(deg[flag] <= i && flag>=i+1){
            	bac_sum += deg[flag--];
			}
			while(i > flag){
				bac_sum -= deg[++flag];
			}
            LL res = 0;
			res += (LL)i*(i-1) + (LL)i*(flag-i) + bac_sum;
			if(pre_sum > res){
				ok = false;
				break;
			}
        }
        puts(ok?"Y":"N");
    }
    return 0;
}

 
