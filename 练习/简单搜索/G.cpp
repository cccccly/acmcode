#include <stdio.h>
#include <string.h>
//#define LOCAL
using namespace std;
char s1[105],s2[105],temp[210],dest[210],first1[105],first2[105];
int N,C,pd,cnt;

bool judge(){
	
	int res = strncmp(dest,temp,2*C);
	if(res == 0)
		return 1;
	if(cnt > 1 && strncmp(first1,s1,C)==0 && strncmp(first2,s2,C)==0){
		cnt = -1;
		return 1;
	}
	else return 0;
}

void shuffle(){
	pd = 0;
	//printf("%s\n%s\n%s\n",temp,s1,s2);
	for(int i = 0;i < C;i++){
		temp[pd++] = s2[i];
		temp[pd++] = s1[i];
	}
	temp[2*C] = '\0';

	//printf("%s\n",first);
	strncpy(s1,temp,C);
	strncpy(s2,temp+C,C);
	
	s1[C] = '\0';
	s2[C] = '\0';
	
}

int main(){
	#ifdef LOCAL
		freopen("data\\G_wa.in","r",stdin);
		//freopen("data\\G.out","w",stdout);
	#endif
	scanf("%d",&N);
	
	for(int i = 1;i <= N;i++){
		cnt = 0;
		scanf("%d",&C);
		scanf("%s",s1);
		scanf("%s",s2);
		scanf("%s",dest);
		strcpy(first1,s1);
		strcpy(first2,s2);
		do{
			shuffle();
			cnt++;
		}while(!judge());
		if(cnt == -1)
			printf("%d -1\n",i);
		else printf("%d %d\n",i,cnt);
	}
	return 0;
} 
