#include<stdio.h>
#include<stdlib.h>

int q[100],n;
int front,rear;
int front =0;
int rear = 0;

void enqueue(int item);
void dequeue();
void display();

int main(){
    int choice,x;
    printf("Enetr size of queue\n");
    scanf("%d",&n);
    while(choice!=4){
        printf("Enter  choice:\n1. Enqueue   2.Dequeue   3.Display   4.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter item:\n");scanf("%d",&x);enqueue(x);break;
            case 2:dequeue();break;
            case 3: display(); break;
            case 4: break;
        }
    }
    return 0;
}

void enqueue(int item){
    if(front == (rear+1)%n){
        printf("Queue is full\n");
    }
    else{
        rear = (rear+1)%n;
        q[rear] = item;
    }
}

void dequeue(){
    if(front == rear){
        printf("Queue is empty\n");
    }
    else{
        if(rear == 1){
            front = rear = 0;
        }
        else{
            front = (front+1)%n;
        }
    }
}

void display(){
    int i;
    for(i = front+1;i<=rear;i++){
        printf("%d\n",q[i]);
    }
}