/**
*
* Base on version 1.0 , i found there is something can be improved . 
* (1) Struct can be remove from its declaration by using typedef --> by practicing , i found that it cannot be replaced by typedef , because "(p->pre)->next = p->next;(p->next)->pre = p->pre;"
* (2) The main process about Josephus can be abstracted into a method , and it shoulud allow user import his own number and rule; 
* 
* 
* version : 1.1
*
*
* Author : robin 
* 
*
* Date : 2017.07.18
*
**/

#include <stdlib.h>
#include <stdio.h>

struct Node{
	struct Node* pre;
	struct Node* next;
	int id;
	
};

struct Node* init_node(struct Node* p,int head_data);
struct Node* add_node(struct Node* p,struct Node* pos_l,struct Node* pos_r);
struct Node*  delete_node(struct Node* p);
void traverse(struct Node* p);
struct Node* josefu_begin(struct Node* cur_ele, int rule);

int main(){
	
	int num, rule;
        puts("Please input number and rules: ");
        scanf("%d%d", &num, &rule);
	struct Node * p ;
	p = init_node(p,1);
	struct Node* added_left = p;
	struct Node* added_right = p->next;
	struct Node* current_added = NULL;
	for(int i=1;i<num;i++){
		current_added = add_node(current_added,added_left,added_right);
		current_added->id = i+1;
		//printf("p->pre=%p,p->next=%p,p->id=%d\n",current_added->pre,current_added->next,current_added->id);
		added_left = current_added;
		added_right = current_added->next;
	}

	
	int count = 0;
	struct Node* pHead = current_added->next; 
	//printf("List head is %d\n",pHead->id);
	struct Node* cur_ele = pHead;
	traverse(cur_ele);
	printf("\n");

	cur_ele = josefu_begin(cur_ele,rule);

	printf("Finally , id=%d is left.\n",cur_ele->id); 
	//traverse(cur_ele);
	return 0;
}

struct Node* init_node(struct Node* p,int head_data){
	p = (struct Node*)malloc(sizeof(struct Node));
	p->pre = p;
	p->next = p;
	p->id = head_data;
	return p;
};

struct Node* add_node(struct Node* p,struct Node* pos_l,struct Node* pos_r){//return head node
	p = (struct Node*)malloc(sizeof(struct Node));
	pos_l->next = p;
	pos_r->pre = p;
	p->pre = pos_l;
	p->next = pos_r;
	return p;
};
struct Node* delete_node(struct Node* p){
	(p->pre)->next = p->next;
	(p->next)->pre = p->pre;
	struct Node* p1 = p->next;
	free(p);
	return p1;
};

struct Node* josefu_begin(struct Node* cur_ele, int rule){
	int count = 0;
	while(cur_ele != cur_ele->next){//wrong : cur_ele->pre != cur_ele->next
		if(count == rule-1){//attention : because d=3 , that means "count" can only have 3 options .
			cur_ele = delete_node(cur_ele);
			traverse(cur_ele);
			printf("\n");
			count = 0;
		} else {
			cur_ele = cur_ele->next;
			count++;
		}
	}
	return cur_ele;
};

void traverse(struct Node* p){
	struct Node* pHead = p;
	int len = 0;
	do{
		printf("p=%p,p->pre=%p,p->next=%p,p->id=%d\n",p,p->pre,p->next,p->id);
		p=p->next;
		len++;
	}while(p!=pHead);
	//printf("total : %d\n",len);
};

