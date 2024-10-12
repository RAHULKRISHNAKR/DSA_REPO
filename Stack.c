#include<stdio.h>
#include<stdlib.h>

int top=-1,item,s[100],n;

struct stack{
    int data;
    struct stack* link;
};

void push(int item){
    if(top == n-1){
        printf("Stack is full.\n");
    }
    else{
        top +=1;
        s[top] = item;
    }
}

void pop(){
    if(top == -1){
        printf("Stack is Empty");
    }
    else{
        
        top -=1; 
    }
}

void display(){
    int i;
    if(top == n-1)
        printf("Stack Full\n");

    
    printf("Stack Elements:\t");
    for(i=0;i<=top;i++){
        
        printf("%d  ",s[i]);
    }
}

int stackArray(){
    int Achoice,itemx;
    printf("Enter size of Stack:");   scanf("%d",&n);
    while(Achoice!=4){
        printf("\n1.Push   2.Pop   3.Display   4.Exit\nEnter choice: ");
        scanf("%d",&Achoice);
        switch(Achoice){
            case 1:printf("Enter item to push:");scanf("%d",&itemx);push(itemx);display();break;
            case 2:pop();display();break;
            case 3: display();break;
            case 4: break;
            default:printf("Invalid Choice\n");break;
        }
    }
    return 0;
}
struct stack* topp;

void lpush(int item){
    struct stack* newNode = (struct stack*)malloc(sizeof(struct stack));
    newNode->data = item;
    newNode->link = NULL;
    if(topp == NULL){
        topp = newNode;
    }
    else{
        newNode->link = topp;
        topp = newNode;

    }
}


void lpop(){
    if(topp == NULL){
        printf("Stack Empty.");
    }
    else{
        struct stack* ptr = topp;
        topp = topp->link;
        free(ptr);
    }
}

void ldisplay(){
    struct stack* ptr;
    ptr =topp;
    if(topp == NULL){
        printf("Stack is empty");
    }
    else{
        while(ptr->link!=NULL){
        printf("%d  ",ptr->data);
        ptr = ptr->link;
    }printf("%d",ptr->data);}
    printf("\n");
}

void llist(){
    int lchoice;
                while(lchoice!=4){
                printf("1.Push   2.Pop   3.Display   4.Exit");
                scanf("%d", &lchoice);
                switch(lchoice){int itemi;
                    case 1: printf("Enter item");scanf("%d",&itemi);lpush(itemi);break;
                    case 2: lpop();break;
                    case 3: ldisplay();break;
                    case 4: break;
                }
            
            
                }
}

int main(){
    int choice;
    while(choice!=3){
        printf("1.Stack using Arrays\n2.Stack using LinkedLists\n3.Exit\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:stackArray();break;
            case 2: llist();
            break;
            case 3: break;
            default: printf("Invalid choice\n");break;
        }
    }
    return 0;
}