#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#define maxn 100010
using namespace std;
int T;
int n,m,lm0,lm1,lw0,lw1,cnt;
int a[maxn],b[maxn];
int m0[maxn],m1[maxn],w0[maxn],w1[maxn];
bool vm0[maxn],vm1[maxn],vw0[maxn],vw1[maxn];
//vector <int> m0,m1,w0,w1;


bool cmp(int c1,int c2){
	return c1>c2;
}

void init(){
	scanf("%d %d",&n,&m);
	cnt = lm0 = lm1 = lw0 = lw1 = 0;
	memset(vm0,0,sizeof(vm0));
	memset(vm1,0,sizeof(vm1));
	memset(vw0,0,sizeof(vw0));
	memset(vw1,0,sizeof(vw1));
	int tmp;
	for(int i = 0;i < n;i++){
		scanf("%d",&a[i]);
	}
	for(int i = 0;i < m;i++){
		scanf("%d",&b[i]);
	}
	for(int i = 0;i < n;i++){
		scanf("%d",&tmp);
		if(tmp == 0){
		m0[lm0++] = a[i];
		}
		else m1[lm1++] = a[i];
	}
	for(int i = 0;i < m;i++){
		scanf("%d",&tmp);
		if(tmp == 0){
			w0[lw0++] = b[i];
		}
		else w1[lw1++] = b[i];
	}
	sort(m0,m0+lm0);
	sort(m1,m1+lm1);
	sort(w0,w0+lw0);
	sort(w1,w1+lw1);
	//printf("%d %d %d %d\n",lm0,lm1,lw0,lw1);
}


void solve(){
	int pos;
	for(int i = 0;i < lw1;i++){
		pos = lower_bound(m0,m0+lm0,w1[i]) - m0;
		if(pos == lm0)
			continue;
		while(pos <= lm0-1){
			if(vm0[pos] == 0){
				cnt++;
				vm0[pos] = 1;
				break;
			}
			else pos++;
		}
	}
	
	for(int i = 0;i < lm1;i++){
		//printf("%d\n",m1[i]);
		pos = lower_bound(w0,w0+lw0,m1[i]) - w0;
		if(pos == lw0)
			continue;
		while(pos <= lw0-1){
			if(vw0[pos] == 0){
				cnt++;
				vw0[pos] = 1;
				break;
			}
			else pos++;
		}
	}
}

int main(){
	int T;
	//freopen("A.in","r",stdin);
	scanf("%d",&T);
	while(T--){
		init();
		solve();
		printf("%d\n",cnt);
	}
	return 0;
} 
