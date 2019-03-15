#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstdlib>
using namespace std;
int main() {
	
	while(1){
		system("C.exe");
		double t1=clock();
		system("C1.exe");
		double t2=clock();
		system("rand.exe");
		if(system("fc c.out c1.out")) {
			printf("WA time used:%lfms\n",t2-t1);
			return 0;
		}
		else
			printf("AC time used:%lfms\n",t2-t1);
	}
	
	return 0;
}
