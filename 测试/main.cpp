#include <bits/stdc++.h>

using namespace std;

int ans[1001];
int main(){
	string ss;
	int cnt = 0,temp = 0,flag = 0;
	while(1){
		getline(cin,ss);
		cnt = 0,flag = 0;
		for(int i = 0;i < ss.size();i++){
			if(ss[i] <= '9' && ss[i] >= '0'){
				if(flag == 0){
					flag = 1;
					temp = ss[i] - 48;
				}
				else{
					temp *= 10;
					temp += ss[i] - 48;
				}
			}
			else{
				if(flag == 1){
					ans[cnt++] = temp;
					flag = 0;
				}	
			}
		}
		if(flag == 1){
			ans[cnt++] = temp;
		}
		for(int i = 0;i < cnt;i++)
			printf("%d ",ans[i]);
		puts("");
	}
	return 0;
} 
