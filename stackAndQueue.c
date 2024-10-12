#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;

};

struct node* top;
struct node *front;
struct node*rear;


void push();
void pop();
void display();
void insert();
void delete_q();

void push(int item){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = item;
    newNode->link = NULL;
    if(top == NULL){
        top = newNode;
       
    }
    else{
        rear->link = newNode;
        top = newNode;
    }
}

void pop(){
    if(top == NULL){
        printf("Stack is empty\n");
    }
    else{
        struct node* ptr = top;
        top = top->link;
        free(ptr);
    }
}

void display(){
    struct node* dis = top;
    while(dis!= NULL){
        printf("%d\n",dis->data);
        dis = dis->link;
    }
}

void Stack(){
    int item; int choice;
    while(choice!=4){
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the item\n");
                scanf("%d",&item);
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Wrong choice\n");
        }
    }
}
    void insert(int item){
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = item;
        newNode->link = NULL;
        if(front == NULL){
            front = newNode;
            rear = newNode;
        }
        else{
            rear->link = newNode;
            rear = newNode;
        }
    }

    void delete_q(){
        if(front == NULL){
            printf("Queue is empty\n");
        }
        else{
            struct node* ptr = front;
            front = front->link;
            free(ptr);
        }
    }
    void queue(){
        int item; int choice;
        while(choice!=4){
            printf("1.Insert\n");
            printf("2.Delete\n");
            printf("3.Display\n");
            printf("4.Exit\n");
            printf("Enter your choice\n");
            scanf("%d",&choice);
            switch(choice){
                case 1:
                    printf("Enter the item\n");
                    scanf("%d",&item);
                    insert(item);
                    break;
                case 2:
                    delete_q();
                    break;
                case 3:
                    display();
                    break;
                case 4:
                    exit(0);
                    break;
                default:
                    printf("Wrong choice\n");
            }
        }
    }

void main(){
    int which =0;
    while(which!=3){
        printf("1.Stack\n");
        printf("2.Queue\n");
        printf("3.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&which);
        switch(which){
            case 1:
                Stack();
                break;
            case 2:
                queue();
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Wrong choice\n");
        }
    }
}