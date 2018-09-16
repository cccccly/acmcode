#include <bits/stdc++.h>

using namespace std;

int getMaxSum(const char *numberStr,int nlen){
	int area[100002];
	area[0] = 0;
	int cnt = 0,flag = 0;
	for(int i = 0;i < nlen;i++){
//		if(numberStr[i] >= 48 && numberStr[i] <= 57)
		if(numberStr[i] == ' '){
			area[++flag] = i;
			area[++flag] = i+1;
			cnt++;
		}
	}
	area[++flag] = nlen;
	cnt++;
	int num[50002],cal = 0,sign = 1;
	for(int i = 0;i <= cnt*2-1;i+=2){
		int j;
		for(j = area[i];j < area[i+1];j++){
			if(j == area[i] && numberStr[j] == '-'){
				sign = -1;
				continue;
			}
			if(numberStr[j] < 48 || numberStr[j] > 57){
				num[i/2] = 0;
				cal = 0;
				break;
			}
			else{
				cal *= 10;
				cal += numberStr[j] - 48;
			}	
		}
		if(j >= area[i+1]){
			num[i/2] = cal*sign;
			cal = 0;
		}
		sign = 1;
	}
	int sum = 0,mx = 0;
	for(int i = 0;i < cnt - 1;i++){
		mx = num[i];
		sum = max(sum ,mx);
		for(int j = i+1;j < cnt;j++){
			mx += num[j];
			sum = max(sum,mx);
		}
	}
	return sum;
}

int main(){
	char ss[100000];
	while(gets(ss)){
		printf("%d\n",getMaxSum(ss,strlen(ss)));
	}
	return 0;
} 
