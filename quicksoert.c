#include<stdio.h>
void swap(int* a,int* b);
int partition(int a[25],int lb,int ub);
void quicksort(int a[25],int lb,int ub);

int main(){
    int a[25],lob,upb,n;
    printf("enter aray size:\n");
    scanf("%d",&n);
    printf("Enter elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    lob = 0;
    upb = n-1;
    quicksort(a,lob,upb);
    printf("Sorted array\n");
    for(int i=0;i<n;i++){
        printf("%d",a[i]);
    }
    return 0;
}

int partition(int a[25],int lb,int ub){
    int pivot = a[lb];
    int start = lb;
    int end = ub;
    while(start<end){
        while(a[start]<=pivot){
            start++;
        }
        while(a[end]>pivot){
            end--;
        }
        if(start<end){
            swap(&a[start],&a[end]);
        }
    }
    swap(&a[lb],&a[end]);
    return end;
}

void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void quicksort(int a[25],int lb,int ub){
    if(lb<ub){
        int loc=partition(a,lb,ub);
        quicksort(a,lb,loc-1);
        quicksort(a,loc+1,ub);
    }
}