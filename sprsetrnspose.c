#include<stdio.h>
#include<stdlib.h>

void input(int r,int c, int a[100][100]){
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&a[i][j]);
        }
    }

    printf("\n--------Matrix in Normal Form---------\n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%d",a[i][j]);
        }
        printf("\n");
    }    
}

void toTuple(int r,int col,int b[100][100],int c[100][3]){
    int k=1;
    for(int i=0;i<r;i++){
        for(int j=0;j<col;j++){
            if(b[i][j]!=0){
                c[k][0]=i;
                c[k][1]=j;
                c[k][2]=b[i][j];
                k++;
            }
        }
    }
    c[0][0]=r;
    c[0][1]=col;
    c[0][2]=k-1;

    for(int i=0;i<k;i++){
        for(int j=0;j<3;j++){
            printf("%d",c[i][j]);
        }
        printf("\n");
    }
}


void transpose(int s[100][3],int t[100][3]){
    int r=s[0][0];
    int c=s[0][1];
    int n = s[0][2];
    int k=1;


    int t[0][0] = c;
    int t[0][1] = r;
    int t[0][2] = n;

    for(int i=0;i<c;i++){
        for(int j=1;j<n;j++){
            if(s[j][i]==i){
                t[k][0]=s[j][1];
                t[k][1]=s[j][0];
                t[k][2]=s[j][2];
                k++;
            }
        }
    }
}


/*void add(int a[100][3],int b[100][3],int d[100][3]){
    int r1=a[0][0];
    int r2=b[0][0];
    int c1=a[0][1];
    int c2=b[0][1];
    int n1=a[0][2];
    int n2=b[0][2];

    int i,j,k;
    i=j=k=1;

    if(r1!=r2||c1!=c2){
        printf("Cannot ADD");
        return;
    }

    d[0][0]=r1;
    d[0][1]=r2;

    while(i<n1 && j<n2){
        
    }
}*/