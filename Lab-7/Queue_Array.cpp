//Menu driven program to implement queue using array
#include<cstdio>
#define SIZE 5

class QueueADT{
    private:
    int Queue[SIZE];
    int rear;
    int front;
    public:
    QueueADT(){
        rear=-1;
        front=-1;
    }
    void enqueue(int);
    int dequeue();
    int peek();
    void display();
};

int main(){
    QueueADT queue;
    int choice;
    int result;
    int data;
    do{
        printf("\nMenu Driven Program\n");
        printf("1)Enqueue\n2)Dequeue\n3)Peek\n4)Display\n5)Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the value to be enqueued: ");
            scanf("%d",&data);
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
            printf("Exiting Program....\n");
            return 0;
            default:
            printf("Enter a valid choice: ");
            break;
        }
        
    }while(choice!=5);
}

//Fuunction to enqueue an element into the queue
void QueueADT::enqueue(int value){
    if(rear==SIZE-1){
        printf("Queue is full.");
        return;
    }
    else if(rear==-1 && front==-1){
        rear=0;
        front=0;
        Queue[rear]=value;
    }
    else{
        rear++;
        Queue[rear]=value;
    }
}

//Function to dequeue an element from the queue
int QueueADT::dequeue(){
    int num;
     if(rear==-1 && front==-1){
        return -1;
     }
     else if(front==rear){
        front=-1;
        rear=-1;
     }
     else{
        num=Queue[front];
        front++;
       
     }
      return num;
}

//Function to peek the front element
int QueueADT::peek(){
    int num;
    if(rear==-1 && front==-1){
        return -1;
    }
    else{
        num=Queue[front];
    }
    return num;
}

//Function to display the elements of the queue
void QueueADT::display(){
    if(rear==-1 && front==-1){
        printf("Queue is empty.");
        
    }
    else{
    for(int i=front;i<rear+1;i++){
        printf("%d ",Queue[i]);
    }
    }
}
