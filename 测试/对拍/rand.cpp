#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
using namespace std;
int main() {
	freopen("data\\a.in","w",stdout);
	srand((unsigned)time(NULL));  //���ȱ�������������������ÿһ������ʱ���ɵ������������ͬ�ġ�
	int T,m,n,s;
	T = rand()%(100)+1;
	
	printf("%d\n",T);
	for(int t = 0;t < T;t++){
		m = rand()%10 + 1;
		n = rand()%10 + 1;
		printf("%d %d\n",n,m);
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				s = rand()%2;
				if(s == 0)
					putchar('.');
				else putchar('#');
			}
			puts("");
		}
	}
	return 0;
}

