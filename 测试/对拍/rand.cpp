#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
using namespace std;
int main() {
	freopen("DATA\\G.in","w",stdout);
	srand((unsigned)time(NULL));  //���ȱ�������������������ÿһ������ʱ���ɵ������������ͬ�ġ�
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

