#include <stdio.h>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;
struct node{
	int score;
	int id;
	
//	bool operator < (node a) const{
//		return score > a.score;
//	}
};

struct cmp{
	bool operator < (node a) const{
		return a.score < b.score;
	}
};

priority_queue<node ,vector<node> ,cmp> q1;


int main(){
	node stu[3] = {{50,1},{70,2},{20,3}};
	for(int i = 0;i < 3;i++)
		q1.push(stu[i]);
	while(!q1.empty()){
		node temp = q1.top();
		q1.pop();
		printf("%d:%d\n",temp.id,temp.score);
	}
	return 0;
}
