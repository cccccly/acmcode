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
        for(int i=0;i<V;++i){
        	scanf("%d", &deg[i]);
        	sum+=deg[i];
		}
        if(sum%2){
        	puts("N");
        	continue;
		}
        bool ok=true;
        for(int i=0;i<V;++i)
        {
            sort(deg+i, deg+V, greater<int>());
            if(deg[i]<0 || i+deg[i]>=V)
            {
                ok=false;
                break;
            }
            for(int j=1;j<=deg[i];++j){
            	--deg[i+j];
            	if(deg[i+j] < 0){
            		ok=false;
                	break;
				}
			}   
        }
        puts(ok?"Y":"N");
    }
    return 0;
}


/*复杂度n方 Havel-Hakimi定理*/
