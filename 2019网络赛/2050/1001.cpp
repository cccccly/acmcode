#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

string ss,tmp;
string con = "2050";

int main(){
	int T,flag;
	//freopen("1.txt","r",stdin);
	scanf("%d",&T);
	while(T--){
		cin>>ss;
		if(ss.size()%4 != 0){
			puts("No");
			continue;
		}
		flag = 1;
		//printf("%d",ss.size());
		for(int i = 0;i < ss.size();i=i+4){
			tmp = ss.substr(i,4);

			if(tmp != con){
				flag = 0;
				break;
			}
		}
		if(flag)
			puts("Yes");
		else puts("No");
	}
	return 0;
} 
