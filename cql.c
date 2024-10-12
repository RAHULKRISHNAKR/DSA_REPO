#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* link;
};

struct node *front,*rear,*head=NULL;

void enqueue(int item){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = item;
    newNode->link = NULL;

    if(head == NULL){
        front = rear = newNode;
        head = newNode;
    }
    else{
        rear->link =newNode;
        rear = rear->link;
    }
    rear->link = head;
}


void dequeue(){
    if(head == NULL){
        printf("Queue is empty\n");
    }
    else if(head->link == head){
        struct node* temp = head;
        head->link = NULL;
        free(temp);
    }
    else{
        front = front->link;
        struct node* temp = head;
        head = front;
        free(temp);
    }
}

void display(){
    struct node* ptr = head;
    do{
        printf("%d",ptr->data);
        ptr = ptr->link;
    }while(ptr!=head);
}

int main(){
    int choice,x;

    while(choice!=4){
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1 : printf("Enter number:");scanf("%d",&x);enqueue(x);break;
            case 2: dequeue();break;
            case 3: display();break;
            case 4: break;
        }
    }
    return 0;
}

