#include <bits/stdc++.h>

using namespace std;


int main(){
	string s;
	while(cin>>s){
		int cnt = 0;
		for(int i = 0;i < s.size();i++){
			if(s[i] == 'W')
				cnt++;
			else cnt--;
		}
		if(cnt){
			puts("0");
		}
		else
			puts("1");
	}
	return 0;
} 
