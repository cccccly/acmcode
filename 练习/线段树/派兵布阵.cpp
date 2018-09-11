#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100005;
ll bit[N];
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

int main(){
	int T;
	scanf("%d",&T);
	a[0] = 0;
	for(int t = 1;t <= T;t++){
		scanf("%d",&n);
		memset(bit,0,sizeof(bit));
		for(int i = 1;i <= n;i++){
			scanf("%lld",&a[i]);
			add(bit,i,a[i]);
		}
		string op;
		int l,r;
		printf("Case %d:\n",t);
		while(cin>>op){
			if(op == "End")
				break;
			scanf("%d %d",&l,&r);
			if(op == "Query"){
				printf("%lld\n",sum(bit,r)-sum(bit,l-1));
			}
			else if(op == "Add"){
				add(bit,l,r);
			}
			else {
				add(bit,l,-r);
			}
		}
	}
	return 0;
} 
