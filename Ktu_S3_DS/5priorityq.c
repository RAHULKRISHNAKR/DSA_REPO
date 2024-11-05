#include<stdio.h>

struct queue {
    int data;
    int prio;
}q[100];

int rear=0,front=0,n;

void enq(int item, int priority){
    if(rear == n-1){
        printf("Queue Full");
    }
    else{
        rear = rear+1;
        q[rear].data = item;
        q[rear].prio = priority;

    }
    int i =rear;
    struct queue temp;
    while(i>front+1){
        if(q[i].prio == q[i-1].prio){
            temp = q[i];
            q[i] = q[i-1];
            q[i-1] = temp;
        }
        i = i-1;
    }

}

void dq(){
    if(front == rear){
        printf("Queue is Empty");
    }
    else{
        front = front +1;
    }
}

void display(){
    if(rear == n-1){
        printf("Queue Empty\n");
    }
    else{
        if(front == rear)
            printf("Queue Full");
        
        for(int i=front;i<=rear;i++){
                printf("%d", q[i].data);
        }
    }
}

int main(){
    printf("Enter size of queue:"); scanf("%d",&n);
    int choice;
    int dat,prioi;
    while(choice!=4){
        printf("Enqueue    Dequeue    Display    Exit");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("enter element to insert");scanf("%d",&dat);
                    printf("Enter priority");scanf("%d",&prioi);
            enq(dat,prioi);display();break;
            case 2: dq();display();break;
            case 3: display();break;
            case 4: break;
        }
    }
    return 0;
}