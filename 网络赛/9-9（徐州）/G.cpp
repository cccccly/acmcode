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
	for(int i = n;i >= 1;i--){
		int x=nd[i].x,y=nd[i].y;
		
	}
	return 0;
} 
