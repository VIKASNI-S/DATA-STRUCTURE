#include<cstdio>
void push(char variable){
    if(top==size-1){
        printf("Overflow...");
        return;
    }
    else{
        top++;
        stacks[top]=variable;

    }
}

void display(){
    int i;
    if(top==-1){
        printf("Stack is empty...");
        return;
    }
    else{
        for(i=top;i>=0;i--){
            printf("%c ",stacks[i]);
        }

    }
}

void pop(){
    char value;
    if(top==-1){
        printf("The stack is empty.");
        return;
    }
    else{
        value=stacks[top];
        printf("The poped data is %c",value);
        top--;
    }
}


void peek(){
    char value;
    if(top==-1){
        printf("The stack is empty.");
        return;
    }
    else{
        value=stacks[top];
        printf("The poped data is %c",value);
        
    }
}
