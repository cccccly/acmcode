#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define maxn 100010

char s[maxn],t[maxn];
int a[256][maxn];
int p[256];
int n,len1,len2,cnt;

void init(){
	int tmp;
	memset(p,0,sizeof(p));
	for(int i = 0;i < len1;i++){
		tmp = s[i];
		a[tmp][p[tmp]++] = i;
	}
} 


void solve(){
	int pre = -1,tmp,pos;
	for(int i = 0;i < len2;i++){
		tmp = t[i];
		if(p[tmp] == 0 || a[tmp][0] < pre){
			puts("NO");
			return;
		}
		pos = lower_bound(a[tmp],a[tmp]+p[tmp],pre) - a[tmp];
		if(pos == p[tmp]){
			puts("NO");
			return ;
		}
		pre = a[tmp][pos];
	}
	
	puts("YES");
}

int main(){
	//freopen("m.in","r",stdin);
	
	scanf("%s",s);
	len1 = strlen(s);
	scanf("%d",&n);
	while(n--){
		scanf("%s",t);
		len2 = strlen(t);
		if(len1 < len2){
			puts("NO");
			continue;
		}
		init();
		solve();
	}
	
	return 0;
}
