#include<stdio.h>
#include<stdlib.h>
#define S 10

struct node{
    int data;
    struct node* link;
}*hashTable[S];

void inItHashtable(){
    for(int i=0;i<S;i++){
        hashTable[i]=NULL;
    }
}

int hashFunction(int key){
    return(key%S);
}

void insertTable(int key){
    int index = hashFunction(key);
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = key;
    new->link = NULL;

    if(hashTable[index]==NULL){
        hashTable[index]=new;
    }
    else{
        struct node* temp = hashTable[index];
        while(temp->link!=NULL){
            temp = temp->link;
        }
        temp->link = new;
    }
}

void display(){
    for(int i=0;i<S;i++){
        printf("Index: %d ",i);
        if(hashTable[i]==NULL){
            printf("Empty\n");
        }
        else{
            struct node* temp = hashTable[i];
            while(temp->link !=NULL){
                printf("%d",temp->data);
                temp = temp->link;
            }
            printf("NULL\n");
        }
    }
}

int main(){
    inItHashtable();
    int choice,key;
    do{
        printf("Enter choice: ");   scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter element");scanf("%d",&key);inItHashtable(key);break;
            case 2: printf("\n");display();break;
            case 3: break;
        }

    }while(choice!=3);
    return 0;
}