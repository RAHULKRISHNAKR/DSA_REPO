#include<stdio.h>

int q[200],n,front ,rear;
void insertionRear(int item){
    if((front == 0 && rear==0) || (front = rear+1)){
        printf("Queue is Full.\n");
    }
    else if(front == -1){
            rear =0;
            front =0;
    }
    else if(rear == n-1){
        rear =0;
    }
    else{
        rear = rear+1;
        q[rear] = item;
    }
}

void insertionFront(int item){
    if((front==0 && rear==0) || (front == rear+1)){
        printf("Queue is Full.\n");
    }
    else if(front == -1){
        front =0;rear=0;
    }
    else if(front==0){
        front = n-1;
    }
    else{
        front = front-1;
        q[front] = item;
    }
}  

void deletionRear(){
    if(front == -1){
        printf("Queue empty");
    }
    else if(front == rear){
        front = -1;rear = -1;
    }
    else if(rear == 0){
        rear = n-1;
    }
    else{
        rear = rear-1;
    }
}
deletionFront(){
    if(front == -1){
        printf("Queue Empty\n");
    }
    else if(front == rear){
        front = -1;rear = -1;
    }
    else if(front == n-1){
        front = 0;
    }
    else{
        front = front+1;
    }
}

void display(){
    for(int i = front;i<=rear;i++){
        printf("Queue Elements:\n");
        printf("%d\n",q[i]);
    }
}

int main(){
    int x;
    printf("Enter size");
    scanf("%d",&n);
    int choice;
    while(choice!=6){
        printf("Enter option:");
        scanf("%d", &choice);
        switch(choice){
            case 1:printf("Enter element:");scanf("%d", &x);
            insertionFront(x);break;
            case 2: printf("Enter element:");scanf("%d", &x); 
            insertionRear(x);break;
            case 3: deletionFront();break;
            case 4: deletionRear();break;
            case 5: display();break;
            case 6: break;
        }

    }
return 0;}