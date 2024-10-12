#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    int priority;
}p[100];

int n;
int front = -1;
int rear = -1;

void enqueue(int item, int prio){
    if(rear == n-1){
        printf("Queue is full");
    }
    else{
        rear = rear+1;
        p[rear].data  = item;
        p[rear].priority = prio;
        int i = rear;
        while(i>front+1){
            if(prio < p[i-1].priority){
                struct node temp = p[i];
                p[i] = p[i-1];
                p[i-1] = temp;
            }
            i--;
        }
    }
}

void dequeue(){
    if(rear == -1){
        printf("Queue is emoty");
    }
    else if(rear == front){
        front = rear = -1;
    }
    else{
        front = front+1;
    }
}

void display(){
    int i;
    for(i=front+1;i<=rear;i++){
        printf("%d  [%d]\n",p[i].data,p[i].priority);
    }
}

int main(){
    int choice,x,p;
    printf("Enter size of queue:");
    scanf("%d",&n);
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