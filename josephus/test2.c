/**
*
* After coding , i found that , in fact , there is no need use double circle linked-list , single circle linked-list is enough .
* So as you can image , here i will use single circle linked-list solve this problem .
* 
* 
* version : 2.0
*
*
* Author : robin 
* 
*
* Date : 2017.07.18
*
* At the beginging , i just think that use single cirle linked-list is easier and simpler , but it turns out i was wrong , because
* delete a node is not a relaxing thind : geting prior node of current node isn't as simple as image , and you must give specific index,
* so you are forced to traverse list and get prior node. 
*
**/

#include <stdlib.h>
#include <stdio.h>

struct Node{
	struct Node* next;
	int id;
};

struct Node* init_node(struct Node* p,int head_data);
struct Node* add_node(struct Node* p,struct Node* pos_l,struct Node* pos_r);
struct Node*  delete_node(struct Node* p);
void traverse(struct Node* p);
struct Node* josefu_begin(struct Node* cur_ele, int rule);
int get_len(struct Node* list);
struct Node* get_prior(struct Node* list);

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

	struct Node* pHead = current_added->next; 
	//printf("List head is %d\n",pHead->id);
	struct Node* cur_ele = pHead;
	traverse(cur_ele);
	printf("\n");
	int len = get_len(cur_ele);
	printf("Initial list len = %d\n",len);
	printf("\n");
	
	struct Node* prior = get_prior(pHead);
	printf("The node before pHead is %d\n",prior->id);
	printf("\n");
	
	cur_ele = josefu_begin(cur_ele,rule);
	printf("Finally , id=%d is left.\n",cur_ele->id); 
	//traverse(cur_ele);
	return 0;
}

struct Node* init_node(struct Node* p,int head_data){
	p = (struct Node*)malloc(sizeof(struct Node));
	p->next = p;
	p->id = head_data;
	return p;
};

struct Node* add_node(struct Node* p,struct Node* pos_l,struct Node* pos_r){//return head node
	p = (struct Node*)malloc(sizeof(struct Node));
	pos_l->next = p;
	p->next = pos_r;
	return p;
};
struct Node* delete_node(struct Node* p){
	struct Node* tmp = p->next;
	struct Node* prior = NULL;
	prior = get_prior(p);
	prior->next = tmp; 
	free(p);
	return tmp;
};

struct Node* josefu_begin(struct Node* cur_ele, int rule){
	int count = 0;
	while(cur_ele != cur_ele->next){//wrong : cur_ele->pre != cur_ele->next
		if(count == rule-1){
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
		printf("p=%p,p->next=%p,p->id=%d\n",p,p->next,p->id);
		p=p->next;
		len++;
	}while(p!=pHead);
	//printf("total : %d\n",len);
};

int get_len(struct Node* list){
	int len;
	struct Node* pHead = list;	
	for(len = 0;;len++){
		list = list->next;
		if(list == pHead){len++;break;}	
	}
	return len;
}

struct Node* get_prior(struct Node* list){
	int len = get_len(list);
	for(int i = 1; i < len; i++){
		list = list->next;	
	}
	return list;
}

