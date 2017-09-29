/**
*
*     When i complete version 2.0 , i allways think it is too complicated using that way , then it occured to me that i came across a seemly easier way not long ago . 
* So i try my best to find that way , finally i found that way in a blog . After deep and careful reading , i got the point:
*     if you want get the prior node in a single circle linked-list , why not stop at the prior node , then the current node is next , and the next is next next . 
* Therefore ,  i start verion 2.5 proudly .
*     So far , these series of questions about circle linked-list is over . I believe this is a good begging , hoping i can persit for a long time . 
* 
* 
* version : 2.5
*
*
* Author : robin 
* 
*
* Date : 2017.07.19
*
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

struct Node* josefu_begin(struct Node* cur_ele, int rule){
	int count = 1;
	struct Node* tmp = NULL;
	while(cur_ele != cur_ele->next){//wrong : cur_ele->pre != cur_ele->next
		if(count == rule-1){
			tmp = cur_ele->next;
			cur_ele->next = tmp->next;
			traverse(tmp->next);
			printf("\n");
			free(tmp);
			count = 1;
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


