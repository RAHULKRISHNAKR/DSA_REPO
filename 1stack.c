//Stack is a LIFO Data Structure
//Stack has operations Push, Pop nd Display
#include<stdio.h>                   //Stndrd Input Output Lib

int stack[100];
int top=-1,n;

void push(int item){
    if(top == n-1){
        printf("Stack Overflow\n");
    }
    else{
        top = top+1;
        stack[top] = item;
    }
}

int pop(){
    int item;
    if(top == -1){
        printf("Stack empty");
    }
    else{
        item = stack[top];
        top = top-1;
    }
    return item;
}

void display(){
    if(top == -1){
        printf("Stack is Empty\n");
    }
    else if(top == n-1){
        printf("Stack Is Full\nStack Elements:");
        for(int i=0;i<=top;i++){
                printf("%d\n",stack[i]);
        }
    }
    else{
        for(int i=0;i<=top;i++){
                printf("%d\n",stack[i]);
    }
}
}

int main(){
    int choice,num;
    printf("Enter size of Stack:");
                        scanf("%d",&n);
    while(choice!=4){
        printf("1.Push()   2.Pop()   3.Display()   4.Exit");
        scanf("%d",&choice);
        switch(choice){
            case 1:     printf("Enter Element to Push:");  
                        scanf("%d",&num);
                        push(num);
                        break;
            case 2:     pop();
                        break;
            case 3:     display();
                        break;
            case 4:     break;
        }
    }
    return 0;
}