#include<stdio.h>

int q[100],front,rear,n;

void enqueue(int item){
    if(front == (rear+1)%n){
        printf("Queue is Full\n");

    }
    else{
        rear = (rear+1)%n;
        q[rear] = item;
    }
}

void dequeue(){
    int item;
    if(front == rear){
        printf("Queue is Empty\n");
    }
    else{
        item = q[front];
        printf("popped element is:%d\n", item);
        if(rear == 1){
            front = rear= 0;
        }
        else{
            front = (front+1)%n;
        }
    }
}

void display(){
    if(front == rear){
        printf("\nQueue empty\n");
    }
    else{
        int i;
        for( i= front+1; i!= rear;i=(i+1)%n){
            printf("%d  ", q[i]);
        }
        printf("%d\n",q[i]);
    }
}

int main(){
    int choice;
    int insert;
    printf("\t\t---Circular Queue---\n");
    printf("Enter size of queue:");
                    scanf("%d",&n);
    while(choice !=4){
        printf("\n1.Enqueue   2.Dequeue   3.Display   4.Exit\n");
        printf("Enter Choice");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                    printf("Enter element to be inserted: ");
                    scanf("%d",&insert);
                    enqueue(insert);
                    display();
                    break;
            case 2:
                    dequeue();
                    display();break;
            case 3: display();break;
            case 4: break;
        }
    }
    return 0;
}
