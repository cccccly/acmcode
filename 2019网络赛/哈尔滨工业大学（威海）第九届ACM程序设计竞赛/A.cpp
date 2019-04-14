#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

string ss;
int cnt[26];

int main(){
	int n,max = -1;
	scanf("%d",&n);
	cin>>ss;
	memset(cnt,0,sizeof(cnt));
	for(int i = 0;i < n;i++){
		cnt[ss[i]-97]++;
		if(max < cnt[ss[i]-97])
			max = cnt[ss[i]-97];
	}
	printf("%d\n",n-max);
	return 0;
}
