#include <bits/stdc++.h>

using namespace std;

#define MAXN 1003
stack <char> st;
char s[MAXN];

int main()
{
	int T;
	scanf("%d",&T);
	getchar();
	while(T--){
		gets(s);
		for(int i = 0;s[i] != '\0';i++){
			if(s[i] == ' '){
				while(!st.empty()){
					printf("%c",st.top());
					st.pop();
				}
				printf("%c",s[i]);
			}
			else st.push(s[i]);	
		}
		while(!st.empty()){
			printf("%c",st.top());
			st.pop();
		}
		printf("\n");
	}
	return 0;
}
