#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
#define maxn 20000
bool cheak[maxn];
int prime[maxn],tot,N;
void isprime(){
	N = maxn; 
	memset(cheak,0,sizeof(cheak));
	tot = 0;
	for(int i = 2;i <= N;i++){
		if(!cheak[i]){  //是素数 没被筛过 
			prime[tot++] = i;
		}
		for(int j = 0;j < tot;j++){
			if(i*prime[j] > N)//溢出 大于N 
				break;
			cheak[i*prime[j]] = true;
			if(i % prime[j] == 0) //很关键 
				break;
		} 
	}
}
int n;

int main(){
	isprime();
	scanf("%d",&n);
	while(n--){
		int tmp;
		scanf("%d",&tmp);
		if(!cheak[tmp])
			printf("%d 0\n",tmp);
		else{
			int pos = lower_bound(prime,prime+tot,tmp)-prime;
			pos = min(prime[pos]-tmp,tmp-prime[pos-1]);
			printf("%d %d\n",tmp,pos);
		}
	}
	return 0;
} 
