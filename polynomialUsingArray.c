#include<stdio.h>
int n1,n2;
struct poly{
    int coeff;
    int expo;
}p1[10],p2[10],p3[10];

void readpoly();
void displaypoly(struct poly p[10],int size);
int addpoly();

int main(){
    readpoly();
    displaypoly(p1,n1);
    displaypoly(p2,n2);
    int n3 = addpoly();
    displaypoly(p3,n3);
    return 0;
}

void readpoly(){
    printf("enter number of elements in poly1:");scanf("%d",&n1);
    for(int i=0;i<n1;i++){
        printf("enter coeff and expo:");
        scanf("%d%d",&p1[i].coeff,&p1[i].expo);
    }

    printf("enter number of elements in poly2:");scanf("%d",&n2);
    for(int i=0;i<n2;i++){
        printf("enter coeff and expo:");
        scanf("%d%d",&p2[i].coeff,&p2[i].expo);
    
    }
}

void displaypoly(struct poly p[10],int size){
    int i;
    for(i=0;i<=size;i++){
        if (p[i].coeff!=0){
        printf("%d x^%d " ,p[i].coeff,p[i].expo);
        while(i<size-1){printf(" + ");break;}
    }}
    
    printf("\n");
}

int addpoly(){
    int i,j,k;
    while(i<n1){
        while(j<n2){
            if(p1[i].expo==p2[j].expo){
                p3[k].coeff=p1[i].coeff+p2[j].coeff;
                p3[k].expo=p1[i].expo;
                i++;
                j++;
                k++;
            }
            else if(p1[i].expo>p2[j].expo){
                p3[k].coeff=p1[i].coeff;
                p3[k].expo=p1[i].expo;
                i++;
                k++;
            }
            else{
                p3[k].coeff=p2[j].coeff;
                p3[k].expo=p2[j].expo;
                j++;
                k++;
            }
        }
    }
    return k;
}

