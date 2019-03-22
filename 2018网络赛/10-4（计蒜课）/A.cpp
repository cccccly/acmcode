#include <bits/stdc++.h>

using namespace std;

struct Node{
	int x,y,cnt;
}node[305];


int main(){
	int n;
	string s;
	while(~scanf("%d",&n)){
		for(int i = 1;i <= n;i++){
			cin>>s;
			node[i] = {0,0,0}; 
			for(int j = 0;j < s.size();j++){
				stack <int> st;
				if(s[j] == '('){
					st.push(s[j]);
					node[i].x++;
				}
				else{
					if(st.empty() || st.top() == ')'){
						node[i].y++;
					}
					else{
						node[i].x--;
						node[i].cnt += 2;
						st.pop();
					}
				}
			}
		}
	}
	return 0;
}
