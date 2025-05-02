#include<stdio.h>
#include<cstdio>
#include<stdlib.h>
class list{
    private:
    struct node{
        int data;
        struct node *next;
       
    }*tail,*temp;
    int size=0;
    public:
    list(){
        tail=0;
            }
    void insertbeginning(int);
    void insertend(int);
    void insertpos(int,int);
    int deletebeginning();
    int deleteend();
    int deletepos(int);
    void display();
    int search(int);
};
int main(){
int choice;
int value;
int target;
int result;
list mylist;
int pos;
do{
    printf("choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        printf("Value");
        scanf("%d",&value);
        mylist.insertbeginning(value);
        mylist.display();
        break;
        case 2:
        printf("Value");
        scanf("%d",&value);
        mylist.insertend(value);
        mylist.display();
        break;
        case 3:
        printf("Value");
        scanf("%d",&value);
        printf("pos: ");
        scanf("%d",&pos);
        mylist.insertpos(value,pos);
        mylist.display();
        break;
        case 4:
        mylist.deletebeginning();
        mylist.display();
        break;
        case 5:
        printf("pos: ");
        scanf("%d",&pos);
        result=mylist.deleteend();
        if(result!=-1){
            printf("The deleted element is %d",result);
        }
        break;
        case 6:
        printf("pos: ");
        scanf("%d",&pos);
        result=mylist.deletepos(pos);
        if(result!=-1){
            printf("The deleted element is %d",result);
        }
        mylist.display();
        break;
        case 7:
        mylist.display();
        break;
        case 8:
        printf("Enter target: ");
        scanf("%d",&target);
        result=mylist.search(target);
        if(result!=-1){
            printf("Target found at position %d",result);
        }
        else{
            printf("Not found.");
        }
        case 9:
        printf("exiting program.");
        return 0;

    }
}while(choice!=9);
}
//Function to insert an element at beginning 
void list::insertbeginning(int value){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=value;
    if(tail==0){
     tail=newnode;
     tail->next=tail;
        return;
    }else{
    newnode->next=tail->next;
    tail->next=newnode;
    };
    size++;
       
}
//Function to display the contents of the list
void list::display(){
    if(tail==0){
        printf("List is empty.");
        return;
    }

    temp=tail->next;
do{
        printf("%d->",temp->data);
        temp=temp->next;
    }while(temp!=tail->next);

}
//Function to insert a element at end
void list::insertend(int value){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=value;
    if(tail==0){
        tail=newnode;
        tail->next=tail;
        return;
    }
    else{
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;

    }
    size++;
}
//Fuction to insert an element at a given position
void list::insertpos(int value,int pos){
    if(pos<1||pos>size+1){
        printf("invalid pos");
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
 temp=tail->next;
 int i=1;
 struct node *newnode=(struct node *)malloc(sizeof(struct node));
 newnode->data=value;
 while(i<pos-1){
    temp=temp->next;
    i++;
 }
 newnode->next=temp->next;
 temp->next=newnode;
 size++;
}
//Function to delete an element from te beginning
int list::deletebeginning(){
    int value;
    temp=tail->next;
    if(temp->next==temp){
        value=temp->data;
        tail=0;
        free(temp);
        
    }
    tail->next=temp->next;
    value=temp->data;
    return value;
    size--;
    free(temp);
}
//Function to delete an element from the end
int list::deleteend(){
    struct node* current;
    struct node *previous;
    int value;
    current=tail->next;
    if(tail==0){
        return -1;
    }
    else if(current->next==current){
        tail=0;
        value=current->data;
        return value;
        free(current);
    }
    else{
        while(current->next!=tail->next){
            previous=current;
            current=current->next;
        }
        previous->next=tail->next;
        tail=previous;
        value=current->data;
        free(current);
        return value;
        size--;
    }
}
//Function to delete an element at a give position
int list::deletepos(int){
    int i=1;
    int pos;
    int value;
    struct node *current,*nextnode;
    current=tail->next;
    if(pos<1||pos>size){
        return -1;
    }
    
    else if(pos==1){
        deletebeginning();
        return value;
    }
else{
    while(i<pos-1){
        current=current->next;
       i++;
    }
    value=temp->data;
    current->next=nextnode->next;
    free(nextnode);
    size--;
    return value;
}

}
//Function to search for an element
int list::search(int target){
    if(tail==0){
        return -1;
    }
    temp=tail->next;
    int position=1;
    while(temp!=0){
        if(temp->data==target){
            return position;
        }
        temp=temp->next;
        position++;
    }
    return -1;
}
