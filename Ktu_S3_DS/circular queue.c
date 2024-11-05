#include <stdio.h>
int q[20],n,f,r;

void insert(int x);
void delete();
void displayCQ();
void displayPQ(int x , int y , int n , int Queue[n]);
void cq();
void pq();

void insert(int x){
    r=(r+1)%n;
    if (f==r)
    {
        printf("Queue is full\n");
        return;
    }
    else if(r==-1){
        f=0;
        r=0;
        q[r]=x;
    }
    else{
        q[r]=x;
    }
}

void delete(){
	int d;
    if (f==-1 && r==-1){
        printf("Queue is empty\n");
        return;
    }
    else if (f==r)
    {
        d=q[f];
        f=-1;
        r=-1;
    }
    else{
        d=q[f];
        f=(f+1)%n;
    }
    printf("Deleted Element is %d",d);
}

void displayCQ(){
    int i;
    if (f==-1 && r==-1){
        printf("Queue is empty\n");
        return;
    }
    else if (f<=r){
        for(i=f;i<=r;i++){
            printf("%d ",q[i]);
        }
    }
    else{
        for(i=f;i<n;i++){
            printf("%d ",q[i]);
        }
        for (i=0;i<=r;i++){
            printf("%d ",q[i]);
        }
    }
}

void cq (){
    int ch,x;
    printf("Enter the size of the queue\n");
    scanf("%d",&n);
    f=-1;
    r=-1;
    while(ch !=4){
        printf("Enter your choice\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:	
            	printf("Enter the element to be inserted : ");
                scanf("%d",&x);
                insert(x);
                r++;
                displayCQ();
                break;
            case 2:	
            	delete(x);
        		f++;
        		displayCQ();
                break;
            case 3:
            	displayCQ();
                break;
            case 4:
                break;
            default:printf("Invalid choice\n");
        }
    }
}



int ElemCount=0;
void displayPQ(int x,int y,int n,int Queue[n]){

	//printf("front:%d\nrear:%d\n",x,y);
	if(ElemCount==0){
		printf("Queue is empty\n");
	
	}
	else{
		printf("Queue is:");
		for(int i=x;i<=y;i++){
			printf("%d ",Queue[i]);
		}
		printf("\n");
	}
}


void pq(){
	int n;
	printf("Enter size of Queue : ");
	scanf("%d",&n);
	
	int queue[n];
	int rear=-1,front=-1;
	
	int choice;
	printf("enter\n1.enqueue\n2.dequeue\n3.stop\n");
	scanf("%d",&choice);
	
	while(choice!=3){
		if(choice==1){
			if(rear==(n-1)){
				printf("Queue is full\n");
			}
			else{
				int x;
				printf("Enter Number to be Inserted : ");
				scanf("%d",&x);
				
				
				rear++;
				queue[rear]=x;
				if(front==-1){
					front++;
				}
				
				int i=rear;
				while(queue[i]>queue[i-1]&&i>=1){
					int temp=queue[i];
					queue[i]=queue[i-1];
					queue[i-1]=temp;
					i--;
				}
				ElemCount++;
				
			}
		}
		else if(choice==2){
			if(front==-1){
				printf("Queue is empty");
			}
			else if(front==(rear+1)){
				printf("Queue is empty");
			}
			else{
				ElemCount--;
				front++;
			}
		}
		if(choice!=3){
			displayPQ(front,rear,n,queue);
		}
		
		printf("\n1.enqueue\n2.dequeue\n3.stop\n");
		printf("Enter Choice : ");
		scanf("%d",&choice);
	
	}
}

int main(){
    int choice;
    while(choice !=3){
    printf("1.Circular Queue   2.Priority Queue   3.Exit");
    printf("Enter choice"); scanf("%d",&choice);
    switch (choice)
    {
    case 1:     cq();
                break;
    case 2:    pq();A
                break;
    case 3: 
                break;
    
    }
    }
}