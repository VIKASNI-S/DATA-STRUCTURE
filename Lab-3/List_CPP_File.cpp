//Menu Driven program to implement operations in a list ADT

#include<stdio.h>
#include<cstdio>
#define MAX_SIZE 5

class listADT{
    private:
    int arr[MAX_SIZE];
    int size=0;
    public:
    void InsertBeginning(int value);
    void InsertEnd(int value);
    void InsertPosition(int value, int pos);
    int DeleteBeginning();
    int DeleteEnd();
    int DeletePosition(int pos);
    int Search(int target);
    void Display();
    void Rotate(int k);
    void Rotate2(int k);

};

int main(){
    listADT list;
     int choice;
    int value;
    int pos;
    int target;
    int result;
    int k;

    do{
        printf("\nMenu Driven Program\n");
        printf("1)Insert Beginning\n2)Insert End\n3)Insert Position\n4)Delete Beginning\n5)Delete End\n6)Delete Postion\n7)Search\n8)Display\n9)Rotate\n10)Exit\n");
        printf("Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter a value to be inserted at beginning: ");
            scanf("%d", &value);
            list.InsertBeginning(value);
            break;
            case 2:
            printf("Enter a value to be inserted at end: ");
            scanf("%d",&value);
            list.InsertEnd(value);
            break;
            case 3:
            printf("Enter the position: ");
            scanf("%d",&pos);
            printf("Enter a value to be inserted at a position: ");
            scanf("%d",&value);
            list.InsertPosition(value,pos);
            break;
            case 4:
            result=list.DeleteBeginning();
            if(result==-1){
             printf("The list is empty.");
            }
            else{
                printf("%d is deleted from the list.",result);
            }         
            break;
            case 5:
            result=list.DeleteEnd();
            if(result!=-1 ){
                printf("%d is deleted from the list.",result);
            }
            else{
                printf("List is empty.");
            }
            break;
            case 6:
            printf("Enter the position to be deleted: ");
            scanf("%d", &pos);
            result=list.DeletePosition(pos);
            if(result!=-1 && result!=-2){
                printf("%d is deleted from the list.",result);
            }
            if(result==-2){
                printf("The list is empty.");
            }
            if(result==-1){
                printf("The position is invalid.");
            }
            break;
            case 7:
            printf("Enter the target to be found: ");
            scanf("%d",&target);
            result=list.Search(target);
            if(result!=-1){
                printf("Target found at index %d.",result);
            }
            else{
                printf("Target not found.");
            }
            break;
            case 8:
            list.Display();
            break;
            case 9:
            printf("Enter the no.of rotations: ");
            scanf("%d",&k);
            list.Rotate(k);
            break;
            case 10:
            printf("Exiting Program...\n");
            return 0;
            default:
            printf("Enter a valid choice.\n");
            break;
        }

    }while(choice!=10);
}

//Function to insert a element at the beginning
void listADT::InsertBeginning(int value){
    if(size>=MAX_SIZE){
        printf("List is full.Cannot insert.");
        return;
    }
    for(int i=size;i>0;i--){
        arr[i]=arr[i-1];
    }
    arr[0]=value;
    size++;
}

//Function to insert a element at the end
void listADT::InsertEnd(int value){
    if(size>=MAX_SIZE){
        printf("List is full.Cannot insert.");
        return;
    }
    arr[size]=value;
    size++;
}

//Function to insert a element at a position
void listADT::InsertPosition(int value,int pos){
    if(size>=MAX_SIZE){
        printf("List is full.Cannot insert.");
        return;
    }
    if(pos<1 || pos>size+1){
        printf("Invalid position.");
        return;
    }
    for(int i=size;i>=pos;i--){
        arr[i]=arr[i-1];
    }
    arr[pos-1]=value;
    size++;
}

//Function to delete an element from the beginning
int listADT::DeleteBeginning(){
    
    if(size==0){
       
        return -1;
    }
    int temp=arr[0];
    for(int i=0;i<size-1;i++){
    arr[i]=arr[i+1];
    }
    
    size--;
    return temp;
}

//Function to delete an element from the end
int listADT::DeleteEnd(){
    if(size==0){
        return -1;
    }
    int temp=arr[size-1];
    size--;
    return temp;
}

//Function to delete an element at a given position
int listADT::DeletePosition(int pos){
    if(size==0){
        return -2;
    }
    if(pos<1 || pos>size){
        return -1;
    }
    int temp=arr[pos-1];
    for(int i=pos-1;i<size-1;i++){
        arr[i]=arr[i+1];
    }
    size--;
    return temp;
}

//Function to search for a target and return the index if found else return -1
int listADT::Search(int target){
    if(size==0){
        printf("The list is empty.");
        return  -1;
    }
    for(int i=0;i<size;i++){
        if(arr[i]==target){
            return i;
        }
        
    }
    return -1;
    
}

//Function to display the elements of the list
void listADT::Display(){
    if(size==0){
        printf("The list is empty.");
        return;
    }
    printf("Elements of the array are: ");
    printf("[");
    for(int i=0;i<size;i++){
        if(i!=size-1){
        printf("%d,", arr[i]);
    }
    else{
        printf("%d",arr[i]);
    }}
    printf("]");

}

//Function to rotate the array
void listADT::Rotate(int k){
    if(size==0){
        printf("The list is empty.");
        return;
    }
    k=k%size;
    for(int i=0;i<k;i++){
        int last=arr[size-1];
        for(int j=size-1;j>0;j--){
            arr[j]=arr[j-1];
        }
        arr[0]=last;
    }
}
//Function to rotate the array using temp array
void listADT::Rotate2(int k){
    if(size==0){
        printf("The list is empty.");
        return;
    }
    k=k%size;
    int temp[MAX_SIZE];
    for(int i=0;i<size;i++){
        temp[(i+k)%size]=arr[i];
    }
    for(int i=0;i<size;i++){
        arr[i]=temp[i];
    }
}
