/*二叉树的相关操作(数据结构)，C语言描述*/ 
#include "myhead.h"
#define stacksize 30
typedef struct treenode{
	int data;
	struct treenode *left,*right;
}Tree,*TREE;
typedef struct{
	TREE *base;
	TREE *top;
	int size;
}Sqstack;
typedef struct qnode{
	TREE data;
	struct qnode *next;
}Qnode,*Queue;
typedef struct {
	Queue front;
	Queue rear;
}LinkQueue;


int print(int e){
	printf("%d ",e);  
	return 1;
}
void initstack(Sqstack *S){
	(*S).base=(TREE *)malloc(stacksize*sizeof(TREE));
	if(!(*S).base) exit(0);
	(*S).top=(*S).base;
	(*S).size=stacksize;
}
void push(Sqstack *S,TREE e){
	if((*S).top-(*S).base>=(*S).size){
		(*S).base=(TREE *)realloc((*S).base,((*S).size+5)*sizeof(TREE));
		(*S).top=(*S).base+(*S).size;
		(*S).size+=5;
	}
	*(*S).top++=e;	
}
void pop(Sqstack *S,TREE *e){	*e=*(--(*S).top);  }
int stackempty(Sqstack S){
	if(S.base==S.top) return 0;
	else return 1;
}

void initqueue(LinkQueue *Q){
	(*Q).front=(*Q).rear=(Queue)malloc(sizeof(Qnode));
	if(!(*Q).front) exit(0);
	(*Q).front->next=NULL;
}
void inqueue(LinkQueue *Q,TREE e){
	Queue p;
	p=(Queue)malloc(sizeof(Qnode));
	if(!p) exit(0);
	p->data=e;p->next=NULL;
	(*Q).rear->next=p;
    (*Q).rear=p;
}
void outqueue(LinkQueue *Q,TREE *e){
	Queue p;
	p=(*Q).front->next;
	*e=p->data;
	(*Q).front->next=p->next;
	if((*Q).rear==p) (*Q).rear=(*Q).front;
	free(p);
}
int queueempty(LinkQueue Q){
	if(Q.front==Q.rear) return 0;
	else return 1;
}	

int n0=0,n1=0,n2=0;
void creattree(TREE *T);
void pretraverse1(TREE T);
void pretraverse2(TREE T);
int  intraverse1(TREE T);
void intraverse2(TREE T);
int  posttraverse1(TREE T);
int  outdegree1(TREE T);
void outdegree2(TREE T);
void floortraverse(TREE T);
int  hight(TREE T);
void exchange(TREE *T);

int menu(){
	int choice;
	printf("%*s",30,"1.前序遍历，递归算法（11）,非递归算法（12）\n");
	printf("2.中序遍历，递归算法（21）,非递归算法（22）\n");
	printf("3.后序遍历，递归算法\n");
	printf("4.求度分别为0、1、2的节点数目，递归算法（41）,非递归算法（42）\n");
	printf("5.按层次遍历二叉树\n");
	printf("6.求二叉树的高度\n");
	printf("7.交换每个结点的左右子树，并中序遍历\n");
	printf("请选择：");
	scanf("%d",&choice);
	return choice;
}
int binatTreeMain(){
	TREE T;
	int choice;
	char c='y';
	printf("请输入带空二叉树先序遍历序列（0表示空节点）,例如3个元素的二叉树输入为\n");
    printf(" 1 2 0 0 3 0 0 (1为根结点)：");
	creattree(&T);
	while(c=='Y'||c=='y'){
	choice=menu();
	switch(choice){
	case 11:printf("递归法前序遍历：");pretraverse1(T);break;
	case 12:printf("非递归法前序遍历：");pretraverse2(T);break;
	case 21:printf("递归法中序遍历：");intraverse1(T);break;
	case 22:printf("非递归法中序遍历：");intraverse2(T);break;
	case 3:printf("递归法后序遍历：");posttraverse1(T);break;	
	case 41:outdegree1(T);
			printf("出度为0的节点数目：%d\n",n0);
	        printf("出度为1的节点数目：%d\n",n1);
	        printf("出度为2的节点数目：%d\n",n2);break;
	case 42:outdegree2(T);break;	
	case 5:floortraverse(T);break;
	case 6:printf("\n此二叉树高度为：%d",hight(T));break;
	case 7:exchange(&T);intraverse1(T);break;
	}
    printf("\n是否继续？(Y/N):");
	fflush(stdin);
	scanf("%c",&c);
	system("cls");
	}
}

void creattree(TREE *T){
	int d;
	scanf("%d",&d);
	if(d==0) (*T)=NULL;
	else{
		if(!((*T)=(TREE)malloc(sizeof(Tree)))) exit(0);
		(*T)->data=d;
		creattree(&((*T)->left));
		creattree(&((*T)->right));
	}
}

void pretraverse1(TREE T){
	if(T){
		     print(T->data);				 
			 pretraverse1(T->left);
			 pretraverse1(T->right);
	}   
}
void pretraverse2(TREE T){
	TREE p;
	Sqstack S;
	initstack(&S);p=T;
	while(p||stackempty(S)){//节点不为空或者栈不空时循环
		if(p) {
			print(p->data);
			push(&S,p);
			p=p->left;
		}
		else{
			pop(&S,&p);
			p=p->right;
		}
	}
}
int intraverse1(TREE T){
	if(T){		
		if(intraverse1(T->left))
			if(print(T->data))
				if(intraverse1(T->right)) return 1;
	}
	else return 1;
}
void intraverse2(TREE T){
	TREE p;
	Sqstack S;
	initstack(&S);p=T;
	while(p||stackempty(S)){//节点不为空或者栈不空时循环
		if(p) {			
			push(&S,p);
			p=p->left;
		}
		else{			
			pop(&S,&p);
			print(p->data);
			p=p->right;
		}
	}
}
int  posttraverse1(TREE T){
	if(T){		
		if(posttraverse1(T->left))			
			if(posttraverse1(T->right)) 
				if(print(T->data)) return 1;
	}
	else return 1;
}

int outdegree1(TREE T){
	int flag1=0,flag2=0;
	if(T){		
		if(outdegree1(T->left))			
			if(outdegree1(T->right)){ 
				if(T->left) flag1=1;
		        if(T->right) flag2=1;
		        if(flag1&&flag2) n2++;
		            else if(!flag1&&!flag2) n0++;
		                 else n1++;
			}
	    flag1=flag2=0; return 1;
	}
	else return 1;
}
	
void outdegree2(TREE T){
	TREE p;
	LinkQueue Q;
	int flag1=0,flag2=0,n0=0,n1=0,n2=0;
	initqueue(&Q);p=T;
	inqueue(&Q,p);
	while(queueempty(Q)){
		outqueue(&Q,&p);
		if(p->left) {inqueue(&Q,p->left);flag1=1;}
		if(p->right){inqueue(&Q,p->right);flag2=1;}
		if(flag1&&flag2) n2++;
		else if(!flag1&&!flag2) n0++;
		     else n1++;
	    flag1=flag2=0;
	}
	printf("出度为0的节点数目：%d\n",n0);
	printf("出度为1的节点数目：%d\n",n1);
	printf("出度为2的节点数目：%d\n",n2);
}
void floortraverse(TREE T){
	TREE p;
	LinkQueue Q;
	initqueue(&Q);p=T;
	inqueue(&Q,p);
	while(queueempty(Q)){
		outqueue(&Q,&p);
		print(p->data);
		if(p->left) inqueue(&Q,p->left);
		if(p->right) inqueue(&Q,p->right);
	}
}
int h=0,maxh=0;

int hight(TREE T)
{
 
	h++;
	if(maxh<h) maxh=h;
	if(T){				 
			 hight(T->left);
			 hight(T->right);
	}   
	h--;
	return maxh-1;
}

void exchange(TREE *T)
{
	TREE p;
	if(!(*T)) return;
	p=(*T)->left;(*T)->left=(*T)->right;(*T)->right=p;
	exchange(&((*T)->left));
	exchange(&((*T)->right));
	
}

