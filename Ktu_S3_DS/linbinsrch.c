#include<stdio.h>
#include<stdlib.h>

int main(){
    int a[10] = {0,5,67,69,567,4366,5678,6000,7000,10000};
    int key = 6000;

    int flag =0;
    int mid;
    int low=0;int high = 10;
    while(low<high){
        mid = (high+low)/2;
        
        if(key == a[mid]){
            flag =1;break;
        }
        else if(key < a[mid]){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    if(flag ==1){
        printf("%d present @ %d",key,mid);
    }
    else{
        printf("Invalid");
    }
    return 0;
}