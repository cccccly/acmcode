#include <bits/stdc++.h>
using namespace std;
using ll = long long;

set <int,greater<int> > s1;
set <int,greater<int> > s2;

struct node{
	int x,y;
}nd[50005];
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d %d",&nd[i].x,&nd[i].y);
	}
	ll sum = 0;
	for(int i = n;i >= 1;i--){
		int x=nd[i].x,y=nd[i].y;
		set<int>::iterator it;
		it = s1.upper_bound(x);
		if(it == s1.end()){
			sum += x;
		}else{
			sum += x-*it;
		}
		it = s2.upper_bound(y);
		if(it == s2.end()){
			sum += y;
		}else{
			sum += y-*it;
		}
		s1.insert(x);
		s2.insert(y);
	}
	printf("%lld\n",sum);
	return 0;
} 
