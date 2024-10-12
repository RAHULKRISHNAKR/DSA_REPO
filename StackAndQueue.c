#include <stdio.h>
#include<stdlib.h>

struct stack{
    int data;
    struct stack link*;
}
struct stack* Top= NULL;

int s[10],n=10,top=0;

int q[10],front=-1,rear=-1;
int qc[10];

struct queue{
    int data;
    struct queue* next;
}

struct pq{
    int value;
    int priority;
    struct pq* next1;
}

struct queue* frontl = NULL;
struct queue* rearl = NULL;

//----------------FUNCTION DECLARATIONS-----------------
void push(int item);int pop();
void pushl(int item); int popl();
void stackUsingArray();void stackUsingLinkedList();
void enqueue(int item);void dequeue();
void enqueuel(int item);void dequeuel();
void normalQueue();void normalQueuel();
void enqueuecircularqueue(int item);void dequeuecircularqueue();
void enqueuecircularqueuel(int item);void dequeuecircularqueuel();
void circularQueue();void circularQueuel();
void enqueuepriorityqueue(int item);void dequeuepriorityqueue();
void enqueuepriorityqueuel(int item);void dequeuepriorityqueuel();
void priorityQueue();void priorityQueuel();
void doubleEndedQueue();void doubleEndedQueuel();
void queueUsingArray();void queueUsingLinkedList();
void stack();void queue();
//--------------------MAIN FUNCTION-----------------------
void main(){
    int choice=0;
    while(choice!=3){
        printf("1.Stack.\n2.Queue.\n");
        printf("Enter choice:");
        scanf("%d",&choice)
        switch(choice){
            case 1: stack();break;
            case 2: queue();break;
            case 3: break;
            default: printf("Invalid choice\n");break;
        }
    }
}
//--------------------STACK(MENU DRIVEN-------------------
void stack(){
    int schoice;
    while(schoice!=3){
        printf("1.Stack Using Array\n2.Stack Using LinkedList\n3.Exit\nEnter Choice:");
        scanf("%d",&schoice);
        switch(schoice){
           case 1: stackUsingArray();break;
           case 2: stackUsingLinkedList();break;
           case 3: break;
           default: printf("Invalid choice\n");break; 
        }
    }
}
//--------------------QUEUE(MENU DRIVEN)------------------
void queue(){
    int qchoice;
    while(qchoice!=3){
        printf("1.Queue Using Array\n2.Queue Using LinkedList\n3.Exit\nEnter Choice:");
        scanf("%d",&qchoice);
        switch(qchoice){
           case 1: queueUsingArray();break;
           case 2: queueUsingLinkedList();break;
           case 3: break;
           default: printf("Invalid choice\n");break; 
        }
    }
}
//--------------------STACK USING ARRAY-------------------
void stackUsingArray(){
    int sschoice,item;
    while(sschoice!=4){
        printf("1.Push   2.Pop   3.Display    4.Exit\nEnter Choice:");
        scanf("%d",&sschoice);
        switch (sschoice)
        {
        case 1: printf("Enter item to push");scanf("%d",&item);push(item);break;
        case 2: item=pop();printf("%d",item);break;
        case 3: printf("\n------------Stack(Array)----------\n");
                for(int i=0;i<top;i++){
                    printf("%d\n",s[top]);
                }  
                break;
        case 4: break;
        default:printf("Invalid!");break;
        }
    }
}
//--------------------STACK USING LINKED LIST-------------
void stackUsingLinkedList(){
    int slchoice;item;
    while(slchoice!=4){
        printf("1.Push   2.Pop   3.Display    4.Exit\nEnter Choice:");
        scanf("%d",&slchoice);
        switch (slchoice)
        {
        case 1: printf("Enter item to push");scanf("%d",&item);pushl(item);break;
        case 2: item=popl();printf("%d",item);break;
        case 3: printf("---------Stack(LinkedList)-----------");
                struct node* temp;
                temp = Top;
                while(temp=NULL){
                    printf("%d\n",temp->data);
                    temp = temp->link;
                }
                break;
        case 4: break;
        default:printf("Invalid!");break;
        }
    }   
}
//-----------------FUNCTION TO PUSH TO STACK(ARRAY)-------
void push(int item){
    if(top == n-1){
        printf("\nStack is Full.Cannot Push.\n");
    }
    else{
        s[++top]=item;
    }
}
//-----------------FUNCTION TO POP FROM STACK(ARRAY)------
int pop(){
    int deleted;
    if(top==0){
        printf("\nStack is Empty.Cannot Pop.\n");
    }
    else{
        deleted =s[top];
        top--;
    }
    return deleted;
}
//-----------------FUNCTION TO PUSH TO STACK(LINKEDLIST)--
void pushl(int item){
    newNode = (struct stack*)malloc(sizeof(struct stack));
    newNode->data = item;
    newNode->link= NULL;
    if(Top == NULL){
        Top = newNode;
    }
    else{
        newNode->next = Top;
        Top=newNode;
    }
}
//-----------------FUNCTION TO POP FROM STACK(LINKEDLST)--
int popl(){
    int deleted;
    if(Top == NULL){
        printf("\nStack is Empty.Cannot Pop.\n");
    }
    else{
        deleted = Top->data;
        Top = Top->link;
        free(Top);
    }
    return deleted;
}
//-----------------QUEUE(USING ARRAY)---------------------
void queueUsingArray(){
    int qqchoice;
    while(qqchoice!=5){
        printf("1.NormalQueue   2.Circular Queue   3.Priority Queue   4.Double Ended Queue   5.Exit\nEnter Choice: ");
        scanf("%d",&qqchoice);
        switch(qqchoice){
            case 1: normalQueue();break;
            case 2: circularQueue();break;
            case 3: priorityQueue();break;
            case 4: doubleEndedQueue();break;
            case 5: break;
            default: printf("Invalid choice\n");break;
        }
    }
}
//-----------------QUEUE(USING LINKED LIST)---------------

void queueUsingLinkedList(){
    int qqqchoice;
    while(qqqchoice!=5){
        printf("1.NormalQueue   2.Circular Queue   3.Priority Queue   4.Double Ended Queue   5.Exit\nEnter Choice: ");
        scanf("%d",&qqqchoice);
        switch(qqqchoice){
            case 1: normalQueuel();break;
            case 2: circularQueuel();break;
            case 3: priorityQueuel();break;
            case 4: doubleEndedQueuel();break;
            case 5: break;
            default: printf("Invalid choice\n");break;
        }
    }
}
//---------------NORMAL QUEUE USING ARRAY------------

void normalQueue(){
    int nchoice,x;
    while(nchoice!=4){
        printf("1.Enqueue   2.Dequeue   3.Display   4.Exit\nEnter choice: ");
        scanf("%d",&nchoice);
        switch(nchoice){
            case 1:printf("Enter item to ENQUEUE");scanf("%d",&x);enqueue(x);break;
            case 2:dequeue();break;
            case 3: break;
            case 4: break;
            default: printf("Invalid choice!\n");
        }
    }
}
//------------ENQUEUE NORMAL QUEUE(ARRAY)---------
void enqueue(int item){
    if(rear == n-1){
        printf("Enter Queue is full.\n");
    }
    else if(rear == -1){
        rear=0;           
        front=0;
    }
    else{
        rear =rear+1;
        q[rear]=item; 
    }
}
//----------DEQUEUE NORMAL QUEUE(STACK)----------

void dequeue(){
    if(front == -1){
        printf("Enter Queue is empty.\n");
    }
    else if(front == rear){
        front = -1;
        rear = -1;
    }
    else{
        front++;
    }
}

//----------NORMAL QUEUE USING LINKED LIST-------

void normalQueuel(){
    int lchoice;
    while(lchoice!=4){
        printf("1.Enqueue   2.Dequeue   3.Display   4.Exit\nEnter choice: ");
        scanf("%d",&lchoice);
        switch(lchoice){
            case 1:printf("Enter item to ENQUEUE");scanf("%d",&x);enqueuel(x);break;
            case 2:dequeuel();break;
            case 3: break;
            case 4: break;
            default: printf("Invalid choice!\n");
        }
    } 
}

//------------ENQUEUE NORMAL QUEUE(LIST)-------

void enqueuel(int item){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = item;
    newNode->next = NULL;

    if(frontl == NULL){
        frontl = newNode;
        rearl = newNode;
    }
    else{
        rearl->next = newNode;
        rearl = newNode;
    }
}

//-------------DEQUEUE NORMAL QUEUE(LIST)-----------

void dequeuel(){
    if(frontl = NULL){
        printf("Queue is Empty.");
    }
    else{
        frontl = frontl->next;
    }
}

//-----------CIRCULAR QUEUE(USING ARRAY)-----------

void circularQueue(){
    int kchoice;int item;
    front=-1;rear=-1;
    while(kchoice!=4){
        switch(kchoice){
            case 1 : //enqueue
            printf("\nEnter the element to be added: ");
            scanf("%d",&item);
            enqueuecircularqueue();
            break;
            case 2 : //dequeue
            dequeuecircularqueue();
            break;
            case 3 : 
                for(int i=0;i<rear;i++){
                    printf("%d ",qc[i]);
                }
            break;
            case 4: break;
        }
    }
}

//--------ENQUEUE CIRCULAR QUEUE(ARRAY)---------

void enqueuecircularqueue(int item){
    if((rear+1)%10==front){
        printf("Circular Queue is Full.\n");
    }
    else if (front == -1 && rear == -1 ){
        front=0;
        rear=0;
    }
    else{
        rear=(rear+1)%10;
        qc[rear] = item;
    }
}

//----------DEQUEUE CIRCULAR QUEUE(ARRAY)----------

void dequeuecircularqueue(){
    if(front == -1){
        printf("Circular Queue is Empty.\n");
    }
    else{
        qc[front++];
    }
}

//-------------CIRCULAR QUEUE(LINKEDLIST)---------

void circularQueuel(){
    int dchoice;int x;
    frontl = NULL;
    rearl = NULL;
    while(dchoice !=4){
        printf("\n1. ENQUEUE   2. DEQUEUE   3. DISPLAY   4. EXIT\n");
        scanf("%d",&dchoice);
        switch(dchoice){
            case 1:printf("Enter item to enqueue:");scanf("%d",&x);enqueuecircularqueuel(x);break;
            case 2:dequeuecircularqueuel();break;
            case 3: 
                for(int i = front; i<rear;i++){
                    printf("%d ",qc[i]->data);
                }
                break;
            case 4: break;
            default :printf("Invalid choice, try again.");break;
        }
    }
}

//------------ENQUEUE CIRCULAR QUEUE(LINKED LIST)------------------

void enqueuecircularqueuel(int item){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=item;
    newNode->next=NULL;
    if(rearl==NULL){ 
        frontl=rearl=newNode;
    }
    else{
        rearl->next=newNode;
    }
}

//---------------DEQUEUE CIRCULAR QUEUE(LINKED LIST)-----------

void dequeuecircularqueuel(){
    struct node *temp;
    if(frontl = (rear+1)%10){     
        printf("The queue is Empty \n");
    }
    else{
        temp=frontl;
        printf("Deleted element %d from the Queue \n",temp->data);
        frontl=frontl->next;
    } 
}

void priorityQueue(){
    int pchoice;
    while(pchoice!=4){
        printf("\n1.Enqueue   2.Dequeue   3.Display   4.Exit\n");
        scanf("%d",&pchoice);
        switch(pchoice){
            case 1:
            printf("Enter a number to be added in Priority Queue:\n");
            int value;
            scanf("%d", &value);
            break;
            case 2:
            dequeuecircularqueuel();
            break;
            case 3:
            break;
            case 4: break;
            default :printf("Invalid choice, please enter again.\n");break;
        }
    }
}

void enqueuepriorityqueue(int item, int prio){
    struct pq* newnode=(struct pq*)malloc(sizeof(struct pq));
    newnode->value=item;
    newnode->priority= prio;
    newnode->next1=NULL;
}
  