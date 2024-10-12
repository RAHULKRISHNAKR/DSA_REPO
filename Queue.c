#include<stdio.h>
#include<stdlib.h>

int q[100],cq[100],front=-1,rear=-1,n,x;

void enqueueSimpleQ(int item){
    if(rear == n-1){
        printf("Queue is full.\n");
    }
    else{
        rear = rear+1;
        q[rear]= item;
    }
}

void dequeueSimpleQ(){
    if(front == rear){
        printf("Queue is empty.\n");
    }
    else{
        front +=1;
    }
}

void displaySimpleQ(){
    for(int i=front;i<=rear;i++){
        printf("%d   ",q[i]);
    }
    printf("\n");
}

void SimpleQ(){
    int schoice;
    printf("Enter size of Queue:");scanf("%d",&n);
    while(schoice!=4){
        printf("1.Enqueue   2.Dequeue   3.Display   4.Exit\n");
        printf("Enter choice:");scanf("%d", &schoice);
        switch(schoice){

            case 1: printf("Enter item:");scanf("%d",&x);enqueueSimpleQ(x);break;
            case 2: dequeueSimpleQ();break;
            case 3: displaySimpleQ();break;
            case 4: break;
        }
    }
}

void enqueueCircularQ(int item,int size){
    rear = front =0;
    rear = (rear+1)%size;
    if(front == rear){
        printf("Error");
        return;
    }
    else{
        cq[rear]= item;
    }
    printf("\n");
}

void dequeueCircularQ(int size){
    if(front == rear){
        printf("Queue is empty");
    }
    else{
        front = (front+1)%size;
    }
}

void displayCircularQ(){
    for(int i=front;i<=rear;i++){
        printf("%d  ",cq[i]);

    }
}

void circularQ(){
    int cchoice;
    printf("Enter size of Queue:");scanf("%d",&n);
    while(cchoice!=4){
        printf("1.Enqueue   2.Dequeue   3.Display   4.Exit\n");
        printf("Enter choice:");scanf("%d", &cchoice);
        switch(cchoice){

            case 1: printf("Enter item:");scanf("%d",&x);enqueueCircularQ(x,n);break;
            case 2: dequeueCircularQ(n);break;
            case 3: displayCircularQ();break;
            case 4: break;
        }
    }
}

int main(){
    int choice;
    while(choice!=3){
        printf("1.Simple Queue   2.CircularQueue   3.Exit\n");
        printf("Enter Choice:");scanf("%d",&choice);
        switch(choice){
            case 1:SimpleQ();break;
            case 2:circularQ(); break;
            case 3: break;
        }
    }
    return 0;
}