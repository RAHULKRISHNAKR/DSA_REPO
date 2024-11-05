#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node* top;

void push(int item){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = item;
    new->link = NULL;
    if(top == NULL){
        top = new;
    }
    else{
        new->link = top;
        top = new;
    }
}

void pop(){
    if(top == NULL){
        printf("Stack empty");
    }
    esle{
        struct node* ptr;
        ptr = top;
        int i = top->data;
        top = top->link;
        free(ptr);
        printf("Popped element: %d", i);
    }
}

void display(){}

int main(){

    return 0;
}