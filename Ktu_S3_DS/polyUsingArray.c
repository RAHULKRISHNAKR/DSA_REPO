#include<stdio.h>
#include<stdlib.h>


int n1,n2;

struct poly
{
    int exponent;
    int coeff;
}p1[10],p2[10],p3[20];

void addPoly(struct poly* p[10], struct poly* q[10] , struct poly* r[10]);
void readPoly(struct poly* p);
void displayPoly(struct poly* p[10]);

void main(){
    int choice;

    printf("--Menu--");
    printf("1.Read Poly   2.Add Poly   3.Display Poly   4 Exit");
    while(choice!=4){
        switch(choice){
            case 1: printf("Enter 1st poly");
                    readPoly(p1);
                    printf("Enter 2nd poly");
                    readPoly(p2);
                    break;
            
            case 2: addPoly(p1,p2,p3);
                    break;
            
            case 3: displayPoly(p1);
                    displayPoly(p2);
                    displayPoly(p3);
                    break;
            
            case 4: break;
        }

    }
}

void readPoly(struct poly* p){
    printf("Enter size of polynomial");
    scanf("%d",&n1);
    for(int i=0;i<n1;i++){
        printf("Enter coefficient:");
        scanf("%d",&p.coeff);
        printf("Enter exponent:");
        scanf("%d", &p.exponent);
    }
}