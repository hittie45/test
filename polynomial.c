// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    float coeff;
    int expo;
    struct node*link;
};

struct node* insert(struct node* head,float co,int ex){
    struct node*temp;
    struct node*newP=malloc(sizeof(struct node));
    newP->coeff=co;
    newP->expo=ex;
    newP->link=NULL;
    if(head==NULL||ex>head->expo){
        newP->link=head;
        head=newP;
    }
    else{
        temp=head;
        while(temp->link!=NULL&&temp->link->expo>=ex)
        temp=temp->link;
        newP->link=temp->link;
        temp->link=newP;
    }
    return head;
}
struct node*create(struct node*head){
    int n,i;
    float coeff;
    int expo;
    
    printf("Enter the no.of terms:");
    scanf("%d,&n");
    for(i=0;i<n;i++){
        printf("Enter the co-efficient of term%d",i+1);
        scanf("%f",&coeff);
        printf("Enter the exponent of term%d",i+1);
        scanf("%d",&expo);
        head=insert(head,coeff,expo);
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
            
            printf("(%.fx^%d)",temp->coeff,temp->expo);
            temp=temp->link;
            if(temp!=NULL){
                printf("+");
            }
                else{
                printf("\n");
            }
        }
    }
}
int main()
{
    struct node*head=NULL;
    printf("Enter the polynomial\n");
    head=create(head);
    print(head);
    return 0;
}

