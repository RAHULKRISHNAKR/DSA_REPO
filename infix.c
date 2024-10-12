#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char stack[100];
char infix[100],postfix[100];
int top=-1;
void push(char symbol);
void topostfix();
int precedence(char symbol);
int isEmpty();

int main(){
    printf("Enter expression:");
    gets(infix);
    topostfix();
    printf("\nPostfix Expression : %s",postfix);
}

void topostfix(){
    int i,j=0;
    char symbol,next;
    for(i=0;i<strlen(infix);i++){
        symbol = infix[i];
        switch(symbol){
            case '(': 
                push(symbol);
                break;
            case ')':
                while(next = pop() != '('){
                    postfix[j++]=next;
                }
                break;
            case '+'||'-'||'/'||'*'||'^':  
                while(!isEmpty() && (precedence(stack[top])>=precedence(symbol))){
                    postfix[j++] = pop();
                }
                push(symbol);
                break;
            default:
                postfix[j++]=symbol;
        }
    }
    while(!isEmpty()){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
}

int isEmpty(){
    if(top ==-1){
        return 1;
    }
    else{ 
       return 0;
    }
}

int precedence(char symbol){
    switch(symbol){
        case '^':return 3;
        case '/':return 2;
        case '*':return 2;
        case '+':return 1;
        case '-':return 1;
        default:return 0;
    }
}