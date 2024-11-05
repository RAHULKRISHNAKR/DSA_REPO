#include<stdio.h>

void mergesort(int a[25],int lb,int ub);
void merge(int arr[],int low,int mid,int high);

int main(){
    int a[25];
    printf("ente array\n");
    for(int i=0;i<10;i++){
        scanf("%d",&a[i]);
    }
    mergesort(a,0,9);
    printf("Sorted array:\n");
    for(int i=0;i<10;i++){
        printf("%d",a[i]);
    }
    return 0;
}

void mergesort(int a[25],int lb,int ub){
    if(lb<ub){
        int mid = (lb+ub)/2;
        mergesort(a,lb,mid);
        mergesort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
}
void merge(int a[],int lb,int mid,int ub){
    int i,j,k;
    i=lb;
    j=mid+1;
    k=lb;
    int b[25];
    while(i<=mid && j<=ub){
        
        if(a[i]<=a[j]){
             b[k]=a[i];
             i++;k++;
        }
        else{
            b[k]=a[j];
            j++;k++;
        }
    }
    if(i>mid){
        while(j<=ub){
            b[k]=a[j];
            j++;k++;
        }
    }
    else{
        while(i<=mid){
            b[k]=a[i];
            i++;k++;
        }
    }
    for(k=lb;k<=ub;k++){
        a[k]=b[k];
    }
}