//Menu driven program to implement a list adt using a singly linked list
#include<stdio.h>
#include<cstdio>
#include<stdlib.h>

class list{
private:
struct node{
int data;
struct node *next;
}*head,*temp;
public:
list(){
head=0;
}
void insertbeginning(int value);
void insertend(int value);
void insertpos(int value,int pos);
int deletebeginning();
int DeleteEnd();
void deleteposition(int position);
int search(int target);
void ReverseLink();
void display();
void reverseDisplay();
void reverseDisplayHelper(node* current);
};
int main(){
list mylist;
int choice;
int value;
int pos;
int result;
int target;
do{
printf("\nMenu Driven Program\n");
printf("1)InsertBeginning\n2)InsertEnd\n3)InsertPosition\n4)DeleteBeginning\n5)DeleteEnd\n6)DeletePosition\n7)Search\n8)Display\n9)DisplayReverse\n10)ReverseLink\n11)Exit\n");
printf("Choice: ");
scanf("%d",&choice);
switch(choice){
case 1:
printf("Enter a value to be inserted at beginning: ");
scanf("%d",&value);
mylist.insertbeginning(value);
break;
case 2:
printf("Enter a value to be inserted at end: ");
scanf("%d",&value);
mylist.insertend(value);
break;
case 3:
printf("Enter position: ");
scanf("%d",&pos);
printf("Enter a value to be inserted at position: ");
scanf("%d",&value);
mylist.insertpos(value,pos);
break;
case 4:
result=mylist.deletebeginning();
if(result!=-1){
printf("%d is deleted from the list.",result);
}
else{
printf("List is empty.");
}
break;
case 5:
result=mylist.DeleteEnd();
if(result!=-1){
printf("%d is deleted from the list.",result);
}
else{
printf("List is empty.");
}
break;
case 6:
printf("Enter position: ");
scanf("%d",&pos);
mylist.deleteposition(pos);
break;
case 7:
printf("Enter target: ");
scanf("%d",&target);
result=mylist.search(target);
if(result!=-1){
printf("Target found at position %d.",result);
}
else{
printf("Target not found.");
}
break;
case 8:
mylist.display();
break;
case 9:
mylist.reverseDisplay();
break;
case 10:
mylist.ReverseLink();
break;
case 11:
printf("Exiting Program...");
return 0;
default:
printf("Enter a valid choice.\n");
break;
}
}while(choice!=11);
}
//Function to insert a element at the beginning of a singly linked list.
void list::insertbeginning(int value){
struct node *newnode=(struct node *)malloc(sizeof(struct node));
newnode->data=value;
newnode->next=head;
head=newnode;
}
//Function to insert a element at the end of a singly linked list.
void list::insertend(int value){
struct node *newnode=(struct node *)malloc(sizeof(struct node));
newnode->data=value;
newnode->next=0;
if(head==0){
head=newnode;
return;
}else{
temp=head;
while(temp->next!=0){
temp=temp->next;
}
temp->next=newnode;}
}

//Function to delete a element from the beginning
int list::deletebeginning(){
int value;
if(head==NULL){
return -1;
}
temp=head;
value=temp->data;
head=head->next;
free(temp);
return value;
}
//Function to delete a element from the end
int list::DeleteEnd(){
int value;
if(head==NULL){
return -1;
}
else{
temp=head;
struct node *prevnode=(struct node *)malloc(sizeof(struct node));
while(temp->next!=0){
prevnode=temp;
temp=temp->next;
}
value=temp->data;
prevnode->next=0;
free(temp);
return value;
}
}
//Function to delete an element from a given position.
void list::deleteposition(int position) {
    if (head == nullptr) {
       printf("List is empty.\n");
        return;
    }
    if (position == 1) {
        temp = head;
        head = head->next; 
        delete temp; 
        return;
    }
    temp = head;
    for (int i = 1; temp != nullptr && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == nullptr || temp->next == nullptr) {
        printf("Position is out of range.\n");  
    } else {
        struct node *nodeToDelete=(struct node *)malloc(sizeof(struct node));
         nodeToDelete = temp->next;
        temp->next = temp->next->next;  
        delete nodeToDelete; 
    }
}

//Function to search for an element
int list::search(int target){
if(head==NULL){
return -1;
}
int position=1;
temp=head;
while(temp!=0){
if(temp->data==target){
return position;

}
temp=temp->next;
position++;
}
return -1;
}

//Function to reverse the link
void list::ReverseLink(){
struct node *prevnode=(struct node *)malloc(sizeof(struct node));
struct node *nextnode=(struct node *)malloc(sizeof(struct node));
struct node *current=(struct node *)malloc(sizeof(struct node));
current=head;
prevnode=0;
nextnode=head;
while(current!=0){
nextnode=current->next;
current->next=prevnode;
prevnode=current;
current=nextnode;
}
head=prevnode;
}
//Function to display the contents of a singly linked list.
void list::display(){
if(head==0||head->next==0){
printf("List is empty.");
return;
}
temp=head;
while(temp!=0){
printf("%d->",temp->data);
temp=temp->next;
}
printf("NULL");
}

//Function to insert a element at the given position of a singly linked list.
void list::insertpos(int value,int pos){
struct node* newnode=(struct node *)malloc(sizeof(struct node));
newnode->data=value;
if(pos==1){
newnode->next=head;
head=newnode;
return;
}
temp=head;
if(temp->next!=NULL){
temp=temp->next;
}
temp->next=newnode;
newnode->next=temp->next;
}

//Function to display the list in reversed order.
void list::reverseDisplayHelper(node* current) {
    if (current == NULL) {
        return;
    }
    reverseDisplayHelper(current->next);  
    printf("%d ", current->data);  
}

void list::reverseDisplay() {
    reverseDisplayHelper(head);
    printf("\n");
}
