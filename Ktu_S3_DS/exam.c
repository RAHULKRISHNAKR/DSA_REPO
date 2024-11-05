#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int data;
	struct node* link;
};

struct node* ptr;
int flag =0;

struct node* head1 = NULL;

struct node* insert(char d);
struct node* reverse(struct node* p);
int isPalindrome();

int main(){
	int choice;
	char word[20];
	int i=0;
	word[9]="malayalam";
		
	int n = strlen(word);
	while(1){
		printf("1.Input   2.Reverse   3.Check   4.Exit");
		scanf("%d",&choice);
		switch(choice){
			case 1: 
				for(int i=0;i<n;i++){
					char c  = word[i];
					insert(c);
				}
				break;
			case 2: struct node* head3 = reverse(head1);
				break;
			case 3: 
				isPalindrome(head3);
				break;
			case 4: exit(0);break;
			default: printf("invalid choice");break;
		}
	}
	return 0;
}

struct node* insert(char d){
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = d;
	newNode->link = NULL;
	
	if(head1 == NULL){
		head1 = newNode;
	}
	else{
		ptr = head1;
		while(ptr!=NULL){
			ptr = ptr->link;
			ptr->link = newNode;
		}
	}
	return head1;
}

void insertInReverse(struct node* r,struct node* tounlink1,struct node* previous,struct node* lastt){
	struct node* alink = head1->link;
	while(alink->link!=tounlink1){
		 struct node* ptr4 = alink;
		 previous->link = ptr4;
		 ptr4->link = lastt;
		
	}
}

struct node* reverse(struct node* p){
	ptr = head1;
	struct node * pt+++++++++++	r3 = head1;
	while(ptr!=NULL){
		ptr = ptr->link;
	}
	struct node* tounlink = ptr;
	struct node* ptr2 = ptr;
	ptr->link = ptr2;
	ptr3->link = NULL;
	ptr2->link = ptr3;
	struct node* last = ptr3;
	struct node* prev = ptr2;
	insertInReverse(head1,tounlink,prev,last);
	struct node* head2 = tounlink->link;
	tounlink->link == NULL;
	struct node * ptr5 = head2;
	
	while(ptr5->link!=NULL){
		printf("%d",ptr5->data);
		ptr5 = ptr5->link;
	}
	return head2;
}

int isPalindrome(struct node* head2){
	struct node* p1 = head1;
	struct node* p2 = head2;
	if(p1->data == p2->data){
		flag++;
		p1 = p1->link;
		p2 = p2->link;
	}
	else{
		flag == 0;
		
	}
	if(flag == 0){printf("It is not a palindrome");}
	else{printf("It is a palindrome");}
}