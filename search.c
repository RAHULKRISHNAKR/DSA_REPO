#include <stdio.h>

int n,a[100],key;

void binarySearch();
void linearSearch();

int main(){
    int choice;
    printf("Initializing Array:\n   Enter Number of elements in array: ");
    scanf("%d", &n);
    printf("Enter the elements one by one:\n");
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }

    while(choice!=3){
        printf("\n1.Binary Search   2.Linear Search   3.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: binarySearch();break;
            case 2: linearSearch();break;
            case 3: break;
            default: printf("\nInvalid choice! Try again.\n");break;
        }
    }
    return 0;
}

void binarySearch(){
    printf("Enter element to search");
    scanf("%d",&key);
    int low =0;
    int high = n;
    while(low<high){
        int mid = (low+high)/2;
        if(key == mid){
            printf("\nElement found at index %d",mid);
            break;
        }
        else if(key<mid){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
}

void linearSearch(){
    printf("Enter element to search");
    scanf("%d",&key);
    int i;
    for(i=0;i<n;i++){
        if(a[i] == key){
            printf("Element founda at index %d",i);
            break;
        }
    }
}