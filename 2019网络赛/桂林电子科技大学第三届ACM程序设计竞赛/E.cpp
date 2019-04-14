#include <stdio.h>

#define maxn 1010

using namespace std;

int seq[maxn],len[maxn];
int l,r,T,N;
int mlen,mpos;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(int i = 1;i <= N;i++)
			scanf("%d",&seq[i]);
		len[1] = 1;
		mlen = 1;
		mpos = 1;
		for(int i = 2;i <= N;i++){
			if(seq[i] >= seq[i-1])
				len[i] = len[i-1] + 1;
			else len[i] = 1;
			if(len[i] > mlen){
				mlen = len[i];
				mpos = i;
			}
		}
		printf("%d %d\n",mpos-mlen+1,mpos);
	}
	return 0;
}
