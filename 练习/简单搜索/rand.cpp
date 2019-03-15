#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
using namespace std;
int main() {
	freopen("c.in","w",stdout);
	srand((unsigned)time(NULL));  //首先必须调用这个函数，否则每一次运行时生成的随机数都是相同的。
	int n = 100;
	while(n--){
		printf("%d %d\n",rand()%100001,rand()%100001);
	}
	

	return 0;
}

