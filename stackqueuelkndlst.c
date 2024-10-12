#include <stdio.h>


struct node{
    int data;
    struct node* link;
};

struct node* top;
struct node* front;
struct node* rear;

void push(int item);
void pop();
void enqueue(int item);
void dequeue();

void stack();

void queue();

int main(){
    int choice;
    while(choice!=3){
        printf("1.Stack\n2.Queue\n3.Exit\n");
        scanf("%d",&choice);
        switch (choice) {
            case 1: stack();break;
            case 2: queue();break;
            case 3: break;
        }
    }
}

void stack(){
    int schoice,x;
    while(schoice!=4){
        printf("1.Push  2.Pop  3.Display  4.Exit\n");
        scanf("%d",&schoice);
        switch(schoice){
            case 1: printf("Enter item to push:");
                    scanf("%d",&x);
                    push(x);
                    break;
            case 2: pop();
                    break;
            case 3: 

                if(top==NULL){
                    printf("Stack is empty\n");
                }
                else{
                    struct node* ptr = top;
                    while(ptr->link!=NULL){
                        printf("%d ",ptr->data);
                        ptr = ptr->link;
                    }
                }
                break;
            case 4: break;
        }
    }
}

void queue(){
    int schoice,x;
    while(schoice!=4){
        printf("1.Enqueue  2.Dequeue  3.Display  4.Exit\n");
        scanf("%d",&schoice);
        switch(schoice){
            case 1: printf("Enter item to push:");scanf("%d",&x);
                    enqueue(x);break;
            case 2: dequeue();break;
            case 3: 
                if(front == NULL) {
                    printf("\nQueue is Empty \n");
                }
                else{
                    struct node* ptr = front;
                    while(ptr != NULL) {
                        printf("%d ", ptr->data );
                        ptr = ptr->link;
                    }
                }
            break;
            case 4: break;
        }
    }
}

void push(int item){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data= item;
    newNode->link = NULL;
    if(top == NULL){
        top = newNode;
    }
    else{
        newNode->link = top;
        top = newNode;
    }
}

void pop(){
    if(top == NULL){
        printf("\nStack Underflow\n");
    }
    else{
        struct node *temp = top;
        top = top -> link;
        free(temp);
    }
}

void enqueue(int item){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = item;
    new->link = NULL;
    if(front == NULL){
        front = rear = new;
    }
    else{
        rear->link = new;
        rear = rear->link;
    }
}

void dequeue(){
    if(front == NULL){
        printf("Queue is empty\n");
    }
    else if(front->link == NULL){
        struct node* temp = front;
        front = NULL;
        rear = NULL;
        free(temp);
    }
    else{
        struct node* ptr = front;
        front = front->link;
        free(ptr);
    }
}