//Menu driven program to implement Circular queue using array
#include<cstdio>
#define MAX_SIZE 5
class ADT{
    private:
    int cqueue[MAX_SIZE];
    int front;
    int rear;
    public:
    ADT(){
        front=-1;
        rear=-1;
    }
    void enqueue(int);
    int dequeue();
    int peek();
    void display();

};


int main(){
    ADT queue;
    int choice;
    int data;
    int result;
    do{
        printf("\nMenu Driven Program\n");
        printf("1)Enqueue\n2)Dequeue\n3)Peek\n4)Display\n5)Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter an element to be enqueued into the queue: ");
            scanf("%d",data);
            queue.enqueue(data);
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


//Function to enqueue an element into the queue
void ADT::enqueue(int value){
    if(front=rear=-1){
        front=0;
        rear=0;
        cqueue[rear]=value;
    }
    else if(front==(rear+1)%MAX_SIZE){
        printf("Queue is full.");
        return;
    }
    else{
        rear=(rear+1)%MAX_SIZE;
    }
    cqueue[rear]=value;
}


//Function to dequeue an element from the queue
int ADT::dequeue(){
    int num;
    if(front=rear=-1){
        return -1;
        
    }
    else if(front==rear){
        front=rear=-1;
    }
    else{
    
    num=cqueue[front];

    front=(front+1)%MAX_SIZE;}
    return num;
}

//Function to peek the front element
int ADT::peek(){
    int num;
    if(front=rear=-1){
        return -1;
        
    }
    
    else{
    
    num=cqueue[front];

    }
    return num;
}


//Function to display the elements of the queue
void ADT::display(){
    int i=front;
    if(front=rear=-1){
        printf("Queue is empty.");
        return;
    }else{
    while(i!=rear){
        printf("%d ",cqueue[i]);
        i=(i+1)%MAX_SIZE;
    }
}
}
