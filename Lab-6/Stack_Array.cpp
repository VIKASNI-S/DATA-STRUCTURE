//Menu Driven Program to implement Stack ADT and its operations
#include<stdio.h>
#include<cstdio>
#define SIZE 5

class stackADT{
    private:
    char stack[SIZE];
    int top;
    public:
    stackADT(){
        top=-1;
    }
    void push(char);
    char pop();
    char peek();
    void display();
};

int main(){
    stackADT Stack;
    int choice;
    char value;
    char result;
    do{
        printf("\nMenu Driven Program\n");
        printf("1)Push\n2)Pop\n3)Peek\n4)Display\n5)Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter a character to be pushed into the Stack: ");
            scanf(" %c",&value);
            Stack.push(value);
            break;
            case 2:
            result=Stack.pop();
            if(result!='\0'){
                printf("The popped character is %c.\n",result);
            }
            else{
                printf("The stack is empty.");
            }
            break;
            case 3:
            result=Stack.peek();
            if(result!='\0'){
                printf("The peeked character is %c.\n",result);
            }
            else{
                printf("The stack is empty.");
            }
            break;
            case 4:
            Stack.display();
            break;
            case 5:
            printf("Exiting Program....\n");
            return 0;
             default:
            printf("Enter a valid choice.");
            break;
        }

    }while(choice!=5);
}


//Function to push a character to the stack
void stackADT::push(char value){
    if(top==SIZE-1){
        printf("Stack is full.");
        return;
    }
    else{
        top++;
        stack[top]=value;
    }
}

//Function to pop a character from the stack
char stackADT::pop(){
    if(top==-1){
        return '\0';
    }
    else{
        char data=stack[top];
        top--;
        return data;
    }
}

//Function to peek a character from the Stack
char stackADT::peek(){
    if(top==-1){
        return '\0';
    }
    else{
        return stack[top];
    }
}

//Function to display the elements of Stack
void stackADT::display(){
   if(top==-1){
    printf("Stack is empty.");
    return;
     }
    else{
        for(int i=top;i>=0;i--){
 printf("%c ", stack[i]);
    }
       }
}
