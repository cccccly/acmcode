#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
using namespace std;
int main() {
	freopen("DATA\\G.in","w",stdout);
	srand((unsigned)time(NULL));  //首先必须调用这个函数，否则每一次运行时生成的随机数都是相同的。
	int N,C;
	N = rand()%(1000)+1;

	printf("%d\n",N);
	for(int j = 0;j < N;j++){
		C = rand()%(5) +1;
		printf("%d\n",C);
		for(int i = 0;i < C;i++){
			int temp = rand()%2;
			if(temp == 0)
				printf("C");
			else printf("D");
		}
		puts("");
		for(int i = 0;i < C;i++){
			int temp = rand()%2;
			if(temp == 0)
				printf("C");
			else printf("D");
		}
		puts("");
		for(int i = 0;i < 2*C;i++){
			int temp = rand()%2;
			if(temp == 0)
				printf("C");
			else printf("D");
		}
		puts("");
	}
	return 0;
}

