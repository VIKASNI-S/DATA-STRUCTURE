//PROGRAM TO SORT THE N NUMBERS IN ASCENDING ORDER

#include<stdio.h>
#include<cstdlib>
//FN FOR BUBBLE_SORT
void bubble_sort(int arr[],int n){
for(int i=0;i<n-1;i++){
for(int j=0;j<n-i-1;j++){
if(arr[j]>arr[j+1]){
int temp=arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;
}
}
}
}
//fn for selection_sort
void selection_sort(int arr[],int n){
for(int i=0;i<n-1;i++){
int min_index=i;
for(int j=i+1;j<n;j++){
if(arr[j]<arr[min_index]){
min_index=j;
}
}
int temp=arr[min_index];
arr[min_index]=arr[i];
arr[i]=temp;
}
}
//fn for insertion_sort
void insertion_sort(int arr[],int n){
for(int i=1;i<n;i++){
int key=arr[i];
int j=i-1;
while(j>=0&&arr[j]>key){
arr[j+1]=arr[j];
j=j-1;
}
arr[j+1]=key;
}
}

//fn for printing the array
void print(int arr[],int n){
for(int i=0;i<n;i++){
printf("%d ", arr[i]);
}
}
int main(){
int n;
int arr[n];
int choice;
printf("Enter the no.of elements: ");
scanf("%d",&n);
printf("Enter the elements: ");
for(int i=0;i<n;i++){
scanf("%d",&arr[i]);
}
while(1)
{
printf("\nMenu Driven Function: \n");
printf("1)Bubble Sort\n2)Selection Sort\n3)Insertion Sort\n4)Exit\n");
scanf("%d",&choice);
printf("Choice: %d\n",choice);
switch(choice){
case 1:
bubble_sort(arr,n);
printf("The sorted array using Bubble Sort: ");
print(arr,n);
break;
case 2:
selection_sort(arr,n);
printf("The sorted array using Selection Sort: ");
print(arr,n);
break;
case 3:
insertion_sort(arr,n);
printf("The sorted array using Insertion Sort: ");
print(arr,n);
break;
case 4:
printf("Exiting program...\n");
return 0;
default:
printf("Enter a valid choice. \n");
}
}
return 0;
}
