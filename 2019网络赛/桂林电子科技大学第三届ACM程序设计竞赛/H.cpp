#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int T;
string ss;
int main(){
	scanf("%d",&T);
	while(T--){
		cin>>ss;
		for(int i = 0;i < ss.size();i+=2){
			printf("%c",ss[i]);
		}
		puts("");
	}
	return 0;
}
