#include<stdio.h>

int q[100],n,front,rear=-1;

void enqueue(int item){
    if(rear == n-1){
        printf("Queue is full\n");
    }
    else if(rear == -1){
        front =0;
        rear = 0;
    }
    else{
        rear = rear+1;
        q[rear] = item;
    }
}

void dequeue(){
    if(front == rear){
        printf("Queue is empty");
    }
    else{
        front = front+1;
    }
}

void display(){
    if(front == rear){
        printf("Queue is empty\n");

    }
    else if(rear == n-1){
        printf("Queue if full\n");
        printf("Queue elements:\n");
        for(int i=front;i<=rear;i++){
            printf("%d",q[i]);
    }}
    else{
        printf("Queue elements:\n");
        for(int i=front;i<=rear;i++){
            printf("%d",q[i]);
        }
    }
}


int main(){
    int choice,num;
    printf("Enter size of Queue:");
                        scanf("%d",&n);
    while(choice!=4){
        printf("1.Enqueue()   2.Dequeue()   3.Display()   4.Exit");
        scanf("%d",&choice);
        switch(choice){
            case 1:     printf("Enter Element to be inserted:");  
                        scanf("%d",&num);
                        enqueue(num);
                        break;
            case 2:     dequeue();
                        break;
            case 3:     display();
                        break;
            case 4:     break;
        }
    }
    return 0;
}
