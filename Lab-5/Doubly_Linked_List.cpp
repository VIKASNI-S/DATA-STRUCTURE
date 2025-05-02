//Menu driven program to implement a list adt using a doubly linked list
#include<stdio.h>
#include<cstdio>
#include<stdlib.h>


class double_list{
    private:
    struct node{
        int data;
        struct node *next;
        struct node *previous;

    }*head,*tail;
    int size=0;
    public:
    double_list(){
        head=NULL;
        tail=NULL;
    }
    void insertbeginning(int);
    void insertend(int);
    void insertposition(int,int);
    int deletebeginning();
    int deleteend();
    int deletepos(int);
    int search(int);
    void display();

};


int main(){
    double_list dll;
    int choice;
    int value;
    int result;
    int target;
    int pos;
    do{
        printf("\nMenu Driven Function\n");
        printf("1)Insert Beginning\n2)Insert End\n3)Insert Position\n4)Delete Beginning\n5)Delete End\n6)Delete Position\n7)Search\n8)Display\n9)Exit\n");
        printf("Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter a value to be inserted: ");
            scanf("%d",&value);
            dll.insertbeginning(value);
            dll.display();
            break;
            case 2:
            printf("Enter a value to be inserted: ");
            scanf("%d",&value);
            dll.insertend(value);
           dll.display();
            break;
            case 3:
            printf("Enter position: ");
            scanf("%d",&pos);
            printf("Enter a value to be inserted: ");
            scanf("%d",&value);
            dll.insertposition(value,pos);
            dll.display();
            break;
            case 4:
            result=dll.deletebeginning();
            if(result!=-1){
                printf("The deleted element is %d.",result);
            }
            else{
                printf("The list is empty.");
            }
            dll.display();
            break;
             case 5:
             result=dll.deleteend();
            if(result!=-1){
                printf("The deleted element is %d.",result);
            }
            else{
                printf("The list is empty.");
            }
            dll.display();
           
            break;
            case 6:
            printf("Enter position: ");
            scanf("%d",&pos);
            result=dll.deletepos(pos);
            if(result!=-1){
                printf("The deleted element is %d.",result);
            }
            else{
                printf("The list is empty.");
            }
            dll.display();
            break;
             case 7:
             printf("Enter target: ");
             scanf("%d",&target);
             result=dll.search(target);
             if(result!=-1){
                printf("Target found at position %d.",result);
             }
             else{
                printf("Target not found.");
             }
             dll.display();
            break;
            case 8:
            dll.display();
            break;
             case 9:
            printf("Exiting Program...\n");
            return 0;
            
        }
    }while(choice!=9);
}

//Function to insert a element at beginning
void double_list::insertbeginning(int value){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->previous=0;
    newnode->next=head;
    if(head!=NULL){
        head->previous=newnode;
    }
    else{
        tail=newnode;
    }
    head=newnode;
    size++;

}

//Function to insert an element at end
void double_list::insertend(int value){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    
    newnode->data=value;
    newnode->next=0;
    newnode->previous=tail;
    
    if(tail!=NULL){
        tail->next=newnode;
    }
    else{
        head=newnode;
    }
    
    tail=newnode;
    size++;
}

//Function to insert an element at a given position
void double_list::insertposition(int value,int pos){
    if(pos<1||pos>size+1){
        printf("Invalid position.");
        return;
    }
    if(pos==1){
        insertbeginning(value);
        return;
    }
    if(pos==size+1){
        insertend(value);
        return;
    }
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    int i=1;
    struct node *temp;
    temp=head;
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    
    newnode->data=value;
    newnode->previous=temp;
    newnode->next=temp->next;
    temp->next=newnode;
    newnode->next->previous=newnode;
    size++;
}


//Function to delete an element from the beginning
int double_list::deletebeginning(){
    int value;
    if(head==0){
        return -1;
    }
    struct node *temp;
    temp=head;
    head=head->next;
    if(head!=0){
        
        head->previous=0;
    }
    else{
        tail=0;
    }
    value=temp->data;
    free(temp);
    size--;
    return value;
}

//Function to delete an element from the end
int double_list::deleteend(){
    int value;
    if(head==0){
        return- 1;
    }
    struct node *temp;
    
    value=temp->data;
    if(head->next=0){
     temp=head;
     head=tail=0;
     
     
    } else{    
        
        temp=tail;
        tail=temp->previous;
        tail->next=0;
        
    }
    free(temp);
        size--;
        return value;
}


//Function to delete an element at the given position
int double_list::deletepos(int pos){
    int value;
        if(pos<1||pos>size){
            return -1;
        }
        if(pos==1){
            value=head->data;
            deletebeginning();
            return value;
        }
        if(pos==size){
            value=tail->data;
            deleteend();
            return value;
        }
        int i=1;
        struct node *temp;
        temp=head;
        while(i<pos){
            temp=temp->next;
            i++;
        }
        value=temp->data;
        temp->previous->next=temp->next;
        temp->next->previous=temp->previous;
        free(temp);
        size--;
        return value;
}


//Fuction to search for an element
int double_list::search(int target){
    if(head==NULL){
        return -1;
    }
    struct node *temp;
    temp=head;
    int position=1;
    while(temp!=NULL){
        if(temp->data==target){
            return position;
        }
        temp=temp->next;
        position++;
    }
    return -1;
}


//Function to display the contents of the list
void double_list::display(){
    if(head==NULL){
        printf("The list is empty.");
        return;
    }
    struct node *temp;
    temp=head;
    
    printf("Forward Transversal:\n");
    printf("[");
    while(temp!=NULL){
        printf("%d,",temp->data);
        temp=temp->next;
        
    }
    printf("]\n");
    printf("\n");
    printf("Backward Transversal:\n");
    printf("[");
    temp=tail;
    while(temp!=0){
        printf("%d,",temp->data);
        temp=temp->previous;
    }
    printf("]\n");
}
