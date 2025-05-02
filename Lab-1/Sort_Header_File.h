//HEADER TO SORT THE N NUMBERS IN ASCENDING ORDER
#include<stdio.h>

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
