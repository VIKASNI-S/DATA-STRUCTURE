//Menu Driven Program to implement a Stack using Singly Linked List
#include<stdio.h>
#include<cstdio>
#include<stdlib.h>

class stackADT{
    private:
    struct node{
        char data;
        struct node *next;
    }*top;
    public:
    stackADT(){
        top=NULL;
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
            printf("Enter a character to be pushed into the stack: ");
            scanf(" %c",&value);
            Stack.push(value);
            break;
            case 2:
            result=Stack.pop();
            if(result!='\0'){
                printf("The popped character is %c.\n",result);
            }
            else{
                printf("Stack is empty.");
            }
            break;
            case 3:
            result=Stack.peek();
            if(result!='\0'){
                printf("The peeked character is %c.\n",result);
            }
            else{
                printf("Stack is empty.");
            }
            break;
            case 4:
            Stack.display();
            break;
            case 5:
            printf("Exiting Program...\n");
            return 0;
            default:
            printf("Enter a valid choice.");
            break;
        }
    }while(choice!=5);
}

//Function to push a charater into the Stack
void stackADT::push(char value){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=top;
    top=newnode;
}

//Function to pop a character from the stack
char stackADT::pop(){
    if(top==NULL){
      return '\0';
    }
    else{
        struct node *temp;
        temp=top;
        char value=temp->data;
        top=top->next;
        free(temp);
        return value;
    }
}

//Function to peek a character from the Stack
char stackADT::peek(){
    if(top==NULL){
        return '\0';
    }
    else{
        return top->data;
    }

}


//Function to display the contents of the Stack
void stackADT::display(){
    if(top==NULL){
        printf("Stack is empty.");
        return;
    }
    else{
        struct node *temp;
        temp=top;
        while(temp!=NULL){
            printf("%c ",temp->data);
            temp=temp->next;
        }

    }
   
}
