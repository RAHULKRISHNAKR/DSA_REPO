#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    int prio;
    struct node*link;
};

struct node* head = NULL;
struct node* front;
struct node* rear;

void enqueue(int item,int priority);
void dequeue();
void display();

int main(){
    int choice,x,p;
    while(choice!=4){
        printf("enter choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("Enter x and p");scanf("%d%d",&x,&p);enqueue(x,p);break;
            case 2: dequeue();break;
            case 3: display();break;
            case 4: break;
        }
    }
    return 0;
}

void enqueue(int item,int priority){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=item;
    newNode->prio=priority;
    newNode->link=NULL;

    if(head == NULL){
        head = newNode;
    }
    else{
        struct node* ptr;
        while(ptr->link != NULL){
            ptr = ptr->link;
        }
        ptr->link = newNode;
    }
}

void dequeue(){
    if(head == NULL){
        printf("Queue is empty\n");
    }
    else if(head->link == NULL){
        struct node* ptr = head;
        head = NULL;
        free(ptr);
    }
    else{
        struct node* temp = head;
        struct node* ptr1;
        while(temp->link == NULL){
            ptr1 = temp;
            temp = temp->link;
        }
        ptr1->link =NULL;
        free(temp);
    }
}

void display(){
    struct node * ptr = head;
    if(head == NULL){
        printf("Queue is empty\n"); 
    }
    else{
        while(ptr->link !=NULL){
            printf("%d  [%d]\n",ptr->data,ptr->prio);
        }
    }
}

