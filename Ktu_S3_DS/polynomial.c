#include<stdio.h>
#include<stdlib.h>

struct poly{
    int expo;
    int coeff;
}p1[10],p2[10],p3[10];

int readPoly(struct poly p[10]);

void displayPoly(struct poly p[10],int terms);

int addPoly(struct poly p1[10], struct poly p2[10], struct poly p3[10],int terms1, int terms2);

int main(){
    int t1,t2,t3,choice;
    while(choice!=4){
        printf("1.Read  2.Add  3.Display 4.exit");
        scanf("%d",&choice);
        switch(choice){
            case 1: 
                    t1=readPoly(p1);
                    
                    t2=readPoly(p2);
                    break;
            case 2: printf("First Polynomial:\n");
                    displayPoly(p1,t1);
                    printf("\nSecond Polynomial:\n");
                    displayPoly(p2,t2);
                    break;
            case 3: addPoly(p1,p2,p3,t1,t2);
                    printf("\nThe sum is :\n");
                    displayPoly(p3,t3);
                    break;
            case 4: break;
        }
    }
    return 0;
}

int readPoly(struct poly p[10]){
    int i,j;
    int terms;

    printf("Enter number of terms of polynomial: ");
    scanf("%d",&terms);

    for(i=0;i<terms;i++){
        printf("Enter coefficient %d",i+1);
        scanf("%d",&p[i].coeff);
        printf("Enter exponent %d",i+1);
        scanf("%d",&p[i].expo);
    }

    for(i=0;i<terms;i++){
        for(j=i+1;j<terms;j++){
            if(p[i].expo > p[j].expo) {
                struct poly temp = p[j];
                p[j] = p[i];
                p[i] = temp;
            }
        }
    }
    return terms;
}

void displayPoly(struct poly p[10],int terms){
    int k;
    for(k=0;k< terms;k++){
        if(p[k].coeff !=0)
            printf("%dx^%d ",p[k].coeff,p[k].expo);
        
        while(k<terms-1){
            printf("+");
            break;
        }
    }
}

int addPoly(struct poly p1[10], struct poly p2[10], struct poly p3[10], int terms1, int terms2){
    int i,j,k;
    i=j=k=0;
    while(i<terms1 && j<terms2){
        if(p1[i].expo == p2[j].expo){
            p3[k].expo = p1[i].expo;
            p3[k++].coeff = p1[i++].coeff + p2[j++].coeff;
            i++;j++;k++;
        }
        else if(p1[i].expo > p2[j].expo){
            p3[k].expo = p1[i].expo;
            p3[k].coeff = p1[i].coeff;
            i++;k++;
        }
        else{
            p3[k].expo = p2[j].expo;
            p3[k].coeff = p2[j].coeff;
            j++;k++;
        }
    }
    while(i<terms1){
        p3[k].coeff = p1[i].coeff;
        p3[k].expo = p1[i].expo;
        i++;k++;
    }
    while(j<terms2){
        p3[k].expo = p2[j].expo;
        p3[k].coeff = p2[j].coeff;
        j++;k++;
    }

    return k;
}