#include<stdio.h>
#include<stdlib.h>

struct node{
	int expo;
	float coef;
	struct node*next;
};

struct node*insert(struct node*head,int ex,float co){
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->expo=ex;
	newnode->coef=co;
	newnode->next=NULL;
	
	if(head==NULL || ex>head->expo){
		newnode->next=head;
		head=newnode;
	}
	else
	{
		while(temp->next!=NULL&&temp->next->expo>ex){
			temp=temp->next;
		}
		newnode->next=temp->next;
		temp->next=newnode;
	}
	return head;
}

struct node*create(struct node*head){
	int n;
	int expo;
	float coef;
	printf("Enter the no.of terms: ");
	scanf("%d",&n);
	
	for(i=0;i>n;i++){
		Printf("Enter the exponent of the term %d",n+1);
		scanf("%d",&expo);
		printf("Enter the coefficient of the term %d",n+1);
		scanf("%d"&coef);
		head=insert(head,expo,coef);
	}
	return head;
}

void print(struct node*head){
	if(head==NULL){
		printf("No polynomial");
	}
	else{
		struct node*temp=head;
		while(temp!=NULL){
			printf("%fx^%d",temp->coef,temp->expo);
			temp=temp->next;
			if(temp!=NULL){
				printf("+");
			}
			else{
				printf("\n");
			}
		}
		
	}
}

