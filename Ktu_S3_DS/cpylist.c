#include<stdio.h>
#include<stdlib.h>

int n;

struct node{
    int data;
    struct node* link;
};

struct node* ptr = NULL;
struct node* p2;
struct node* p1;

struct node* head = NULL;

struct node* getNode(int dat){

    struct node* new =(struct node*)malloc(sizeof(struct node)); 
    new->data = dat;
    new->link = NULL;

    if(head == NULL){
        head = new;
        ptr = head;
    }
    else{
        ptr->link = new;
        ptr = new;
    }
    return head;
}

void display(struct node* p){
    while(p->link!=NULL){
        printf("%d",p->data);
    }
    printf("\n");
}

int main(){
    p1 = getNode(2);
    p1 = getNode(3);
    display(p1);
    return 0;
}