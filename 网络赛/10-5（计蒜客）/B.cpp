#include <bits/stdc++.h>

using namespace std;
int main(){
	int n;
	while(~scanf("%d",&n)){
		string s;
		for(int i = 1;i <= n;i++){
			cin>>s;
			int sum = 0;
			for(int j = 0;j < s.size();j++){
				if(s[j] == 'C')
					sum += 12;
				else if(s[j] == 'O')
					sum += 16;
				else sum += 1;
			}
			printf("%d\n",sum);
		}
	}
	return 0;
} 
