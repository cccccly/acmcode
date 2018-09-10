#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int N = 1e5+5;
struct node{
	ll x;
	ll y;
	bool operator < (node const& _A)const{
		if(x < _A.x)  return true;
        if(x == _A.x) return y < _A.y;
        return false;
	}
};
struct cal{
	int sum;
	bool change;
};
map <node,cal> mp;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		mp.clear();
		scanf("%d",&n);
		int mx = 0;
		for(int i = 1;i <= n;i++){
			int k;scanf("%d",&k);
			if(!k)
				continue;
			ll xx,yy;
			while(k--){
				scanf("%lld %lld",&xx,&yy);
				node temp;
				temp.x = xx;
				temp.y = yy;
				if(mp.count(temp)){
					if(mp[temp].change == 0){
						mp[temp].sum++;
						mx = max(mx,mp[temp].sum);
						mp[temp].change = 1;
					}
				}
				else{
					mp[temp].sum = 1;
					mx = max(mx,mp[temp].sum);
					mp[temp].change = 1;
				}
			} 
			map<node,cal>::iterator it;
			map<node,cal>::iterator temp1;
			it = mp.begin();			
			while(it != mp.end())
			{
				if(it->second.change){
					it->second.change = 0;
					it++;
				}
				else{
					temp1 = it;
					it++;
					mp.erase(temp1);
				}
			    
			}
		}
		if(mx == 1)
			puts("0");
		else
			printf("%d\n",mx);
	}
	return 0;
} 
