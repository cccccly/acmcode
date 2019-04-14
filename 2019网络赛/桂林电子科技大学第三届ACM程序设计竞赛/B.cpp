#include <stdio.h>
#include <set>
#include <string>
#include <iostream>
using namespace std;
int n,m;

set <string> s;
string ss;
int main(){
	scanf("%d %d",&n,&m);
	while(n--){
		cin>>ss;
		s.insert(ss);
	}
	printf("%d\n",s.size());
	return 0;
}
