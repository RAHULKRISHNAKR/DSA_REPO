#include <stdio.h>
int q[20],n,front,rear;

#define size 5
#define MAX_SIZE 5

int a[MAX_SIZE], front=0, rear=0, n;

typedef struct PrioElm{
	int data;
	int prio;
}PrioElm;

typedef struct pq {
    PrioElm queue[MAX_SIZE];
    int MAX_SIZE;
} pq;
void displaycq ()
{
	int i;
	printf ("\nThe queue is:\n");

	if (front==rear)
		printf ("empty\n");
	else
	{
		for (i = front+1; i != rear; i = (i + 1) % n)
			printf ("%d ", a[i]);
		printf ("%d\n", a[i]);
	}
	
}

void pushcq()
{
	if(front==(rear+1)%n)
		printf("Queue overflow\n");
	else
	{
	   	rear=(rear+1)%n;
		printf("\nEnter the element to push\n");
		scanf("%d", &a[rear]);
		displaycq();
	}
}

void popcq()
{
	if(front==rear)
		printf("Queue underflow\n");
	else
	{
		printf("\nPopped element %d from queue\n", a[front+1]);
		if(rear==1)
			front=rear=0;
		else
			front=(front+1)%n;
		displaycq();
	}
}

void cq()
{
	int choice;

	printf("Enter the MAX_SIZE of circular queue\n");
	scanf("%d", &n);
	while(choice != 4)
	{
		printf("\nCircular Queue\n______________\n");
		printf("1. Push\n2. Pop\n3. Display\n4. Exit \n");
		printf("\nEnter your choice\n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:	pushcq(&pq, elm);
					break;
			case 2:	popcq(&pq);
					break;
			case 3: displaycq(&pq);
					break;
			case 4: break;			
		}
	}
}

void initPriorityQueue(pq *pq) {
    pq->MAX_SIZE = 0;
}

int isPriorityQueueEmpty(const pq *pq) {
    return pq->MAX_SIZE == 0;
}

int isPriorityQueueFull(const pq *pq) {
    return pq->MAX_SIZE == MAX_SIZE;
}

void enqueue(pq *pq, PrioElm item) {
    if (isPriorityQueueFull(pq)) {
        printf("Priority queue is full. Cannot enqueue.\n");
    } else {
        int i = pq->MAX_SIZE - 1;
        while (i >= 0 && item.prio < pq->queue[i].prio) {
            pq->queue[i + 1] = pq->queue[i];
            i--;
        }
        pq->queue[i + 1] = item;
        pq->MAX_SIZE++;
        printf("%d enqueued successfully.\n", item.data);
    }
}

void dequeue(pq *pq) {
    if (isPriorityQueueEmpty(pq)) {
        printf("Priority queue is empty. Cannot dequeue.\n");
    } else {
        printf("%d dequeued successfully.\n", pq->queue[0].data);
        for (int i = 1; i < pq->MAX_SIZE; i++) {
            pq->queue[i - 1].data = pq->queue[i].data;
        }
        pq->MAX_SIZE--;
    }
}

void displaypq(const pq *pq) {
    if (isPriorityQueueEmpty(pq)) {
        printf("Priority queue is empty.\n");
    } else {
        printf("Priority queue elements: ");
        for (int i = 0; i < pq->MAX_SIZE; i++) {
            printf("%d ", pq->queue[i].data);
        }
        printf("\n");
    }
}

void pq()
{
	int choice;

	printf("Enter the MAX_SIZE of priority queue\n");
	scanf("%d", &n);
	while(choice != 4)
	{
		printf("\nPriority Queue Queue\n______________\n");
		printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit \n");
		printf("\nEnter your choice\n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:	printf("Enter an item to enqueue in Priority Queue: ");
					scanf("%d", &elm.data);
					printf("Enter Priority of element: ");
					scanf("%d", &elm.prio);
					enqueue();
					break;
			case 2:	dequeue();
					break;
			case 3: displaypq();
					break;
			case 4: break;			
		}
	}
}

int main(){
	pq priorityQueue;
	PrioElm elm;
    int choice;
	initPriorityQueue(&priorityQueue);
	    while(choice !=3){
		    printf("1.Circular Queue   2.Priority Queue   3.Exit\n");
		    printf("Enter choice:"); scanf("%d",&choice);
		    switch (choice)
		    {
		    case 1:     cq();
			       break;
		    case 2:    pq();
			       break;
		    case 3: 
			       break;
		    
		    }
	    }
}





















