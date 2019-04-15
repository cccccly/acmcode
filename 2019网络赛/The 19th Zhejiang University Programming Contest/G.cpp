#include<stdio.h>
#include<algorithm>

using namespace std;
#define ll long long
#define maxn 100010
ll a1[maxn],a2[maxn];
ll len1,len2,last1,last2,time1,time2;
ll cnt;
int n,k,T;

void init(){
	ll tmp;
	len1 = len2 = 0;
	cnt = 0;
	
	scanf("%d %d",&n,&k);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&tmp);
		if(tmp >= 0){
			a1[len1++] = tmp;
		}
		else {
			a2[len2++] = -tmp;
		}
	}
	sort(a1,a1+len1);
	sort(a2,a2+len2);
	time1 = len1/k + ((len1%k)&&1);

	time2 = len2/k + ((len2%k)&&1);
	last1 = a1[len1-1];
	last2 = a2[len2-1];
	//printf("%lld\n",(len2%k)&&1);
	//printf("%lld %lld\n",len1,len2);
	//printf("%lld %lld\n",time1,time2);
}

void solve(){
	for(int i = 0;i < time1;i++){
		cnt += a1[len1-1]*2;
		len1 -= k;
	}
	for(int i = 0;i < time2;i++){
		cnt += a2[len2-1]*2;
		len2 -= k;
	}
	//printf("%lld %lld\n",last1,last2);
	if(last1 > last2)
		cnt -= last1;
	else cnt -= last2;
}

int main(){
	//freopen("g.in","r",stdin);
	scanf("%d",&T);
	while(T--){
		init();
		solve();
		printf("%lld\n",cnt);
	}
	return 0;
}

