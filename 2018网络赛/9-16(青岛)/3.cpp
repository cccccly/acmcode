#include <bits/stdc++.h>

using namespace std;

struct operation{
	int type;
	int v;
	int k;
	int y;
}op[10003];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,v,k;
		char s[10];
		for(int i = 1;i <= n;i++){
			scanf("%s",s);
			if(strcasecmp(s,"add")){
				op[i].type = 1;
				scanf("%d",&v);
				op[i].v = v;
				continue;
			}
			if(strcasecmp(s,"beq"))
				op[i].type = 2;
			else if(strcasecmp(s,"bne"))
				op[i].type = 3;
			else if(strcasecmp(s,"blt"))
				op[i].type = 4;
			else if(strcasecmp(s,"bgt"))
				op[i].type = 5;
			scanf("%d %d",&v,&k);
			op[i].v = v;op[i].k = k;op[i].y = 0;
		}
		int r = 0;
		int mod = 256;
		int cnt = 0;
		int flag = 0;
		for(int i = 1;i <= n;){
			if(op[i].type == 1){
				cnt += op[i].v;
				cnt %= mod;
				r += op[i].v;
				r %= mod;
				i++;
			}
			else if(op[i].type == 2){
				if(op[i].v == t){
					if(op[i].k == i){
						break;
					}
					else if()
					i = op[i].k;
				}
				else {
					i++;
				}
			}
			else if(op[i].type == 3){
				if(op[i].v == t){
					if(op[i].k == i){
						break;
					}
					i = op[i].k;
				}
				else {
					i++;
				}
			}
			else if(op[i].type == 4){
				if(op[i].v == t){
					if(op[i].k == i){
						break;
					}
					i = op[i].k;
				}
				else {
					i++;
				}
			}
			else if(op[i].type == 5){
				if(op[i].v == t){
					if(op[i].k == i){
						break;
					}
					i = op[i].k;
				}
				else {
					i++;
				}
			}
		}
		if(flag)
			puts("yes");
		else puts("no");
	}
	return 0;
}
