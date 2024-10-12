#include<stdio.h>
#include<stdlib.h>


struct node {
    int coeff;
    int expo;
    struct node *link;
    };

struct node *createNewNode(int coef , int exp){
    struct node* newNode =(struct node*)malloc(sizeof(struct node));
    if(newNode == NULL){
    	printf("Memmory alocation failed");
    	exit(EXIT_FAILURE);
    	}
    newNode->coeff = coef;
    newNode->expo = exp;
    newNode->link = NULL;
    return newNode;
}

struct node* insert(struct node* head, int coef, int exp){
    struct node* ptr;
    struct node* newNode = createNewNode(coef , exp);
    newNode->coeff = coef;
    newNode->expo = exp;
    newNode->link = NULL;
    if((head == NULL) || (exp> head->expo)){
        newNode->link = NULL;
        if (head == NULL) {
            head = newNode;
        } 
        else {
            struct node *ptr = head;
            while (ptr->link != NULL) {
                ptr = ptr->link;
            }
        ptr->link = newNode;
        }
     }
    else{
        ptr = head;
        while(ptr->link !=NULL && ptr->link->expo > exp){
            ptr = ptr->link;
        }
        newNode->link = ptr->link;
        ptr->link = newNode;
    }
    return head;
}

struct node* mulpoly(struct node* poly1 , struct node* poly2){
    int res1,res2;
    struct node* head = NULL;
    struct node* ptr1 = poly1;
    struct node* ptr2 = poly2;
    while(ptr1 != NULL){
            while(ptr2!= NULL){
            res1 = ptr1->coeff * ptr2->coeff;
            res2 = ptr1->expo + ptr2->expo;
            head = insert(head,res1,res2);
            ptr2 = ptr2->link;
        }
        ptr2 = poly2;
        ptr1 = ptr1->link;
        
    }
    return head;
}

void display(struct node* dis){
    struct node* temp = dis;
    while(temp != NULL){
        printf("%dx^%d",temp->coeff, temp->expo);
        if(temp->link != NULL){
        printf("+ ");}
        temp = temp->link;
    }
    printf("\n");
}

int main(){
    struct node* poly1 = NULL;
    struct node* poly2 = NULL;
    struct node* head = NULL;
    int choice, coeff, exp;
    int n;
    while(1){
    printf("\n1.Enter Poly1   2.Enter Poly2   3.Multiply Poly   4.Display Poly   5.Exit\n");
    printf("Enter choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1: printf("Enter number of terms of poly 1:");
                scanf("%d", &n);
                for(int i=0;i<n;i++){
                printf("Enter Coefficient:");
                scanf("%d", &coeff);
                printf("Enter Exponent:");
                scanf("%d", &exp);
                poly1 = insert(poly1,coeff,exp);
                }break;
        case 2: printf("Enter number of terms of poly 2:");
                scanf("%d", &n);
                for(int i=0;i<n;i++){
                printf("Enter Coefficient:");
                scanf("%d", &coeff);
                printf("Enter Exponent:");
                scanf("%d", &exp);
                poly2 = insert(poly2,coeff,exp);
                }break;
        case 3: head = mulpoly(poly1,poly2);
                printf("multiplied sucessfully");
                break;
        case 4: printf("Display poly1: ");
                display(poly1);
                printf("poly 2:");
                display(poly2);
                printf("result poly:");
                display(head);
                break;
        case 5: exit(0);
                break;
    }}
    return 0;
}

struct node *redup(struct node* head){
     struct node* result = NULL;
     struct node* p = head;
     struct node* q = p;
     struct node* temp;
     while(p != NULL){
         q = p->link;
         while(q != NULL){
             if(p->coeff == q->coeff && p->expo == q->expo){
                 temp = q;
                 q = q->link;
                 p->link = q;
                 free(temp);
             }
             else{
                 q = q->link;
             }
         }
         p = p->link;
     }
     return result;
}


