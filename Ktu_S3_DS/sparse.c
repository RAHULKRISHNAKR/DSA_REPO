#include<stdio.h>

void input(int m[100][100],int r,int c);
void display(int m[][100],int r,int c);
void toTuple(int m[100][100],int s[100][3],int r,int c);
void transpose(int s[100][3],int t[100][3]);
void add(int s[100][3], int t[100][3],int r[100][3]);
int main(){
    int rows,cols;
    int n[100][100];
    int sparse[100][3],transpos[100][3],result[100][3];
    printf("Enter rows,cols:");scanf("%d%d",&rows,&cols);
    input(n,rows,cols);
    display(n,rows,cols);
    toTuple(n,sparse,rows,cols);
    transpose(sparse,transpos);
}

void input(int m[100][100],int r,int c){
    printf("Enter %dby%d matrix:\n",r,c);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&m[i][j]);
        }
    }printf("\n");
}

void display(int m[][100],int r,int c){
    printf("___________Normal Form___________\n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void toTuple(int m[100][100],int s[100][3],int r,int c){
    int k=1;
    printf("________________Tuple Form_______________\n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(m[i][j]!=0){
                s[k][0]=i;
                s[k][1]=j;
                s[k][2]=m[i][j];
                k++;
            }
        }
    }
    s[0][0]=r;
    s[0][1]=c;
    s[0][2]= k-1;

    for(int i=0;i<r;i++){
        for(int j=0;j<=3;j++){
            printf("%d ",s[i][j]);

        }printf("\n");
    }printf("\n");
}

void transpose(int s[100][3],int t[100][3]){
    printf("\n_______Transpose TUple________\n");
    int r = s[0][0];
    int c = s[0][1];
    int n = s[0][2];
    int k = 1;

    t[0][0] = c;
    t[0][1] = r;
    t[0][2] = n;

    for(int i =0;i<c;i++){
        for(int j=0;j<n;j++){
            if(s[j][1]==i){
                t[k][0] = s[j][1];
                t[k][1] = s[j][0];
                t[k][2] = s[j][2];
                k++;
            }
        }
    }

    for(int i=0;i<k;i++){
        for(int j=0;j<=3;j++){
            printf("%d ",t[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void add(int s[100][3], int t[100][3],int r[100][3]){
    printf("\n_______Add TUple________\n");
    int r1 = s[0][0];
    int c1 = s[0][1];
    int n1 = s[0][2];
    int r2 = t[0][0];
    int c2 = t[0][1];
    int n2 = t[0][2];

    r[0][0] = r1;
    r[0][1] = c1;
    

    if((r1!=r2)||(c1!=c2)){printf("csnnot add!");return;}

    while(i<=n1 && j<=n2){
        if()
    }
}