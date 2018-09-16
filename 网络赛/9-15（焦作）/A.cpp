#include <bits/stdc++.h>

using namespace std;

int main(){
	int T;
	char c[] = "Jessie";
	
	scanf("%d",&T);
	while(T--){
		char c1[15];
		scanf("%s",c1);
		if(strcasecmp(c1,"Jessie") == 0){
			puts("Good guy!");
		}
		else puts("Dare you say that again?");
	}
	return 0;
}
