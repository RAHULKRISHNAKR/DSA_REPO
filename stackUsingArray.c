#include<stdio.h>
#include<stdlib.h>

int s[20],n,top=-1;


void push(int item);
void pop();
void display();

int main(){
    int choice,x;
    printf("Enter size of Stack");scanf("%d",&n);
    while(choice != 4){
        printf("Menu:\n1.Push\n2.Pop\n3.Display\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1 :    printf("Enter the element to be pushed: ");
                        scanf("%d",&x);
                        push(x);
                        break;
            case 2:     pop();break;
            case 3:     display();break;
            case 4:     break;
        }
    }
}

void push(int item){
    if(top == n-1)
        printf("Stack is full!\n");
    else{
        top=top+1
        s[top] = item;
    }    
}

void pop(){
    if(top == -1){
        printf("Stack is empty!\n");
    }
    else{
        printf("Popped element %d \n",s[top]);
        top--;
    }
}

void display(){
    int i;
    for(i=0;i<=top;i++){
        printf("%d ",s[i]);
    }
}