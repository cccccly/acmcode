#include<stdlib.h>
#include<stdio.h>
using namespace std;

struct Node;
typedef struct Node * PNode;
struct Node{
	PNode link;
	int co,index; //ϵ����ָ�� 
};
typedef struct Node * LinkList;

//����������
LinkList createNullList_link(void){
	LinkList llist = (LinkList)malloc(sizeof(struct Node));
	if(llist != NULL) llist -> link = NULL;
	else printf("Out of space\n");
	return llist;
} 

//��ȡ����ʽ 
LinkList read(LinkList llist){
	int co,index;
	char c; 
    PNode p = (PNode)malloc(sizeof(Node));
	scanf("%d %d%c",&co,&index,&c);
//	printf("%d %d%c\n", co,index,c);
	p -> co = co;
	p -> index = index;
//	printf("%d %d\n",p -> co,p -> index);
	llist = p; //��¼ͷ��� 
	PNode q = p; //��¼ǰһ����� 
	while(c != '\n'){
		scanf("%d %d%c",&co,&index,&c);
//		printf("%d %d%c\n", co,index,c);
		p = (PNode)malloc(sizeof(Node));
		p -> co = co;
		p -> index = index;
		p -> link = NULL;
//		printf("%d %d",p -> co,p -> index);
		q -> link = p; //ĩβ����p�ڵ� 
		q = p; //���½�βp�ڵ� 
//		c = getchar();
	}
	return llist;
}
//�������ʽ
void print(LinkList llist){
	PNode p = llist;
	while(p != NULL){
		printf("%d %d",p -> co,p -> index);
		if(p -> link != NULL) printf("+");
		p = p -> link;
	}
	printf("\n");
} 
//���
LinkList add(LinkList l1,LinkList l2) {
	PNode p = l1,r,rr,rf;
//	printf("%d %d\n",l1 -> co,l1 -> index);
	while(p -> link != NULL)
		p = p -> link;
	p -> link = l2;
//	printf("%d %d\n",p -> co,p -> index);
	r = l1;
//	print(r);
	//�����Ƿ�������ȵ�ָ��
	while(r != NULL && r -> link != NULL){
		rr = r -> link;
		rf = r;
		while(rr != NULL){ 	
			if(rr -> index == r -> index){  
				r -> co += rr -> co;
				rf -> link = rr -> link;	//ɾ����ָͬ���Ľڵ� 
				free(rr);
				rr = rf -> link;
				continue;
			}
			rf = rf -> link;
			rr = rr -> link;
		}
		r = r -> link;
	}
	return l1;
}
int main(){
	freopen("in.txt","r",stdin);
	LinkList l1 =createNullList_link();
	LinkList l2 =createNullList_link();
	l1 = read(l1);
	l2 = read(l2);
	l1 = add(l1,l2);
	print(l1);
//	print(l2);
	return 0;
}
