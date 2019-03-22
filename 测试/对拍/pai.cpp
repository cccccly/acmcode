#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstdlib>
using namespace std;
int main() {
	
	while(1){
		system("rand.exe");
		system("a1.exe");
		double t1=clock();
		system("a2.exe");
		double t2=clock();
		if(system("fc data\\a1.out data\\a2.out")) {
			printf("WA time used:%lfms\n",t2-t1);
			return 0;
		}
		else
			printf("AC time used:%lfms\n",t2-t1);
	}
	
	return 0;
}
