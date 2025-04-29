#include<cstdio>
#include<stdio.h>
#include<stdlib.h>

class list{
    private:
    struct node{
        int data;
        struct node *previous;
        struct node *next;
    }*head,*tail,*temp;
    int size=0;
    public:
    list(){
        head=NULL;
        tail=NULL;
    }
    void insertbeg(int);
    void insertend(int);
    int deletebeginning();
    void insertposition(int,int);
    int deleteend();
    int search(int);
    int deletepos(int);
    void display();
};


int main(){
    list mylist;
    int choice;
    int value,result,target;
    int pos;
    do{
        printf("Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter a value: ");
            scanf("%d",&value);
            mylist.insertbeg(value);
            mylist.display();
            break;
            case 2:
            printf("Enter a value: ");
            scanf("%d",&value);
            mylist.insertend(value);
            mylist.display();
            break;
            case 3:
            result=mylist.deletebeginning();
            if(result!=-1){
                printf("The deleted element is %d",result);
            }
            mylist.display();
            break;
            
            case 4:
            result=mylist.deleteend();
            if(result!=-1){
                printf("The deleted element is %d",result);
            }
            mylist.display();
            break;
            case 5:
            printf("Enter a value: ");
            scanf("%d",&value);
            printf("pos: ");
            scanf("%d",&pos);
            mylist.insertposition(value,pos);
            mylist.display();
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
            mylist.deletepos(pos);
            mylist.display();
            break;
            case 7:
            printf("Enter target: ");
            scanf("%d", &target);
            result=mylist.search(target);
            if(result!=-1){
                printf("target found at position %d",result);
            }
            else{
                printf("target not found.");
            }
            break;

        }
           
        
    }while(choice!=11);
    
}

void list::insertbeg(int value){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->previous=NULL;
    
    newnode->next=head;
    
    
    if (head != NULL) {  // Avoid segmentation fault
        head->previous = newnode;
    }
    
    else{
        tail=newnode;
    }
    head=newnode;
    size++;
}

void list::display(){
    if (head == nullptr) {
        printf("list is empty.");
         return;
     }
     node* temp = head;
     printf("NULL");
     while (temp != nullptr) {
         printf("<-%d->",temp->data);
         temp = temp->next;
     }
     printf("NULL");
}

void list::insertend(int value){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->previous=tail;
    newnode->next=NULL;
    newnode->data=value;
    if (tail != nullptr) {
        tail->next = newnode;
    } else {
        head = newnode; // If list was empty, head should also point to new node
    }

   tail=newnode;
   size++;
}


int list::deletebeginning(){
    if(head==0){
        printf("List is empty.");
        return -1;
    }
    temp=head;
    int value=temp->data;
   // head->next->previous=0;
    head=head->next;
    if (head != nullptr) {
        head->previous = nullptr;
    } else {
        tail = nullptr; // If list is now empty, update tail
    }
return value;
    free(temp);
    size--;
}


int list::deleteend(){
    if(head==0){
        printf("List is empty.");
        return -1;
    }
temp=tail;
int value=temp->data;
tail=temp->previous;
temp->previous->next=0;
free(temp);
return value;
size--;
}

void list::insertposition(int value,int pos){
    int i=1;
    if(pos<1||pos>size+1){
        printf("Invalid position.");
        return;
    }
    if(pos==1){
        list::insertbeg(value);
        return;
    }
    temp=head;
    while(i<pos-1 && temp != nullptr){
        temp=temp->next;
        i++;
    }
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    

    if (temp->next == nullptr) {  // If inserting at the end
        newnode->next = nullptr;
        newnode->previous = temp;
        temp->next = newnode;
    } else {  // Inserting in the middle
        newnode->next = temp->next;
        newnode->previous = temp;
        newnode->next->previous = newnode;
        temp->next = newnode;
    }
    size++;
}

int list::deletepos(int pos){ 
    if(pos<1||pos>size){
        printf("Invalid position.");
        return -1;
    }
    if(pos==1){
        deletebeginning();
        
    }
    if(pos==size){
        deleteend();
    }
int i=1;
temp=head;
while(i<pos && temp != nullptr){
    temp=temp->next;
    i++;
}int value=temp->data;
temp->previous->next=temp->next;
temp->next->previous=temp->previous;
free(temp);
return value;
size--;
}

int list::search(int target){
    temp=head;
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