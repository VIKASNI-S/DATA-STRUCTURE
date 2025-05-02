//Menu driven program to implement queue using Singly Linked List
#include<cstdio>
#include<stdlib.h>


class ADT{
    private:
    struct node{
        int data;
        struct node *next;
    }*front,*rear;
    public:
    
        ADT(){
            front=NULL;
            rear=NULL;
        }
        void enqueue(int);
        int dequeue();
        int peek();
        void display();
    
};

int main(){
    int choice;
    int value;
    int result;
    ADT queue;
    do{
        printf("\nMenu driven Function\n");
        printf("1)Enqueue\n2)Dequeue\n3)Peek\n4)Display\n5)Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter an element to be enqueued into the queue: ");
            scanf("%d",value);
            queue.enqueue(value);
            break;
            case 2:
            result=queue.dequeue();
            if(result!=-1){
                printf("The dequeued element is %d.\n",result);
            }
            else{
                printf("The queue is empty.");
            }
            break;
            case 3:
            result=queue.peek();
            if(result!=-1){
                printf("The peeked element is %d.\n",result);
            }
            else{
                printf("The queue is empty.");
            }
            break;
            case 4:
            queue.display();
            break;
            case 5:
            printf("Exiting Program...");
            return 0;
            default:
            printf("Invalid Choice.");
        }
    }while(choice!=5);
    
}


//Function to enqueue an element
void ADT::enqueue(int value){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=0;
    if(front==0 && rear==0){
       front=rear=newnode;
        
    }else{
        rear->next=newnode;
        rear=newnode;
    }
}


//Function to dequeue an element 
int ADT::dequeue(){
    int num;
    struct node *temp;
    temp=front;
    num=temp->data;
    front=front->next;
    free(temp);
    return num;
}


//Function to peek the front element
int ADT::peek(){
    int num;
    if(front=rear=0){
        return -1;
    }
    else{
        num= front->data;
        
    }
    return num;
}

//Function to display the contents of Queue
void ADT::display(){
    if(front==0 && rear==0 ){
        printf("Queue is empty.");
    }
    else{
        struct node *temp;
        temp=front;
        while(temp!=0){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}

