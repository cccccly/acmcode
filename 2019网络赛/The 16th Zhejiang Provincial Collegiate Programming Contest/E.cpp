#include <stdio.h>
#include <algorithm>
using namespace std;
#define maxn 100010
int n,ans;

struct node{
	int num,pos;
};
node a[maxn];
void printA(){
	for(int i = 0;i < n;i++){
		printf("(%d,%d) ",a[i].num,a[i].pos);
	}
}

bool cmp(node a,node b){
	if(a.num == b.num)
		return a.pos < b.pos;
	else return a.num < b.num;
}

void init(){
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		scanf("%d",&a[i].num);
		a[i].pos = i;
	}
	sort(a,a+n,cmp);
	ans = n;
}

void solve(){
	int i = n-1;
	int tmp = n;
	while(i >= 0){
		if(a[i].pos < tmp){
			ans--;
			tmp = a[i].pos;
		}
		else{
			int tmp2 = a[i].num;
			while(a[--i].num == tmp2){
				if(a[i].pos < tmp){
					ans--;
				}
			}
			break;
		}
		i--;
	}
}

int main(){
	int T;
	//freopen("e.in","r",stdin);
	scanf("%d",&T);
	while(T--){
		init();
		//printA();
		solve();
		printf("%d\n",ans);
	}
	return 0;
}
