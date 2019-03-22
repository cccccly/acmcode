#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	for(int j = 1;j <= T;j++){
		int n,m;
		scanf("%d%d",&n,&m);
		string str1,str2,str3;
		cin>>str1>>str2>>str3;
		int p = str1[0]-str2[0];
		printf("Case #%d: ",j);
		for(int i = 0;i < m;i++){
			char c = (str3[i]-65+p+26)%26+65;
			printf("%c",c);
		}
		printf("\n");
	}
	return 0;
} 
