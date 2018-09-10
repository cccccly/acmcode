//AC自动机  kuangbin模板 
#include <bits/stdc++.h>

using namespace std;

struct Trie{
	int next[10010][256],fail[10010],end[10010],code[10010];
	int root ,L,cnt;
	int newnode(){
		for(int i = 0;i < 26;i++)
			next[L][i] = -1;
		end[L++] = 0;
		return L-1;
	}
	void init(){
		L = 0;
		root = newnode();
		cnt = 1;
	}
	void insert(char buf[]){
		int len = strlen(buf);
		int now = root;
		for(int i = 0;i < len;i++){
			if(next[now][buf[i]-'a'] == -1)
				next[now][buf[i]-'a'] = newnode();
			now = next[now][buf[i]-'a'];
		}
		end[now]++;
		code[now] = cnt++;
	}
	void build(){
		queue<int>Q;
		fail[root] = root;
		for(int i = 0;i < 26;i++)
			if(next[root][i] == -1)
				next[root][i] = root;
			else{
				fail[next[root][i]] = root;
				Q.push(next[root][i]);
			}
		while(!Q.empty()){
			int now = Q.front();
			Q.pop();
			for(int i = 0;i < 26;i++)
				if(next[now][i] == -1)
					next[now][i] = next[fail[now]][i];
				else{
					fail[next[now][i]] = next[fail[now]][i];
					Q.push(next[now][i]);
				} 
		}
	}
	int query(char buf[]){
		int len = strlen(buf);
		int now = root;
		int res = 0;
		for(int i = 0;i < len;i++){
			now = next[now][buf[i]-'a'];
			int temp = now;
			while(temp != root){
				res += end[temp];
				end[temp] = 0;
				temp = fail[temp];
			}
		}
		return res;
	}
	void debug(){
		
	}
};
char buf[1000010];
Trie ac;

int main()
{
	int n,m;
	while(cin>>n){
		ac.init();
		while(n--){
			scanf("%s",buf);
			ac.insert(buf);
		}
		cin>>m;
		ac.build();
		while(m--){
			scanf("%s",buf);
			
		printf("%d\n",ac.query(buf));
		}
		
	}
	return 0;
} 
