#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstdlib>
using namespace std;
int main() {
	
	while(1){
		system("rand.exe");
		system("G.exe");
		double t1=clock();
		system("G2.exe");
		double t2=clock();
		if(system("fc DATA\\G.out DATA\\G2.out")) {
			printf("WA time used:%lfms\n",t2-t1);
			return 0;
		}
		else
			printf("AC time used:%lfms\n",t2-t1);
	}
	
	return 0;
}
