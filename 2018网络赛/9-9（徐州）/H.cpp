#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100005;
ll bit1[N], bit2[N];
ll a[N];
int n;
void add(ll* bit, int i, ll x) {
    while(i <= n) {
        bit[i] += x;
        i += (-i) & i;
    }
}

ll sum(ll* bit, int i) {
    ll ret = 0;
    while(i) {
        ret += bit[i];
        i -= (-i) & i;
    }
    return ret;
}

int main() {
    int q;
    while(~scanf("%d %d", &n, &q)){
    	for(int i = 1;i <= n;i++){
    		scanf("%lld",&a[i]);
    		add(bit1,i,a[i]);
    		add(bit2,i,(ll)(n-i+1)*a[i]);
		}
		int op,l,r;
		for(int i = 1;i <= q;i++){
			scanf("%d %d %d",&op,&l,&r);
			if(op == 1){
				printf("%lld\n",sum(bit2,r)-sum(bit2,l-1)-(n-r)*(sum(bit1,r)-sum(bit1,l-1)));
			}
			else {
				add(bit1,l,r-a[l]);
				add(bit2,l,(ll)(n-l+1)*(r-a[l]));
				a[l] = r;
			}
		} 
	}
    
    return 0;
}
