#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
using namespace std;
int main() {
	freopen("c.in","w",stdout);
	srand((unsigned)time(NULL));  //���ȱ�������������������ÿһ������ʱ���ɵ������������ͬ�ġ�
	int n = 100;
	while(n--){
		printf("%d %d\n",rand()%100001,rand()%100001);
	}
	

	return 0;
}

