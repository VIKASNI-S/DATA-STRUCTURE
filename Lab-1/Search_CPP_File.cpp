//PROGRAM TO SEARCH USING LINEAR AND BINARY SEARCH
#include<stdio.h>
#include<cstdlib>
#include "Sort.h"

//fn to perform linear_search
int linear_search(int arr[],int n,int target){
for(int i=0;i<n;i++){
if(arr[i]==target){
return i;
}
}
return -1;
}
//fn to perform binary_search
int binary_search(int arr[],int n,int target){
int left=0;
int right=n-1;
while(left<=right){
int mid=(left+right)/2;
if(arr[mid]==target){
return mid;
}
if(arr[mid]>target){
right=mid-1;
}
if(arr[mid]<target){
left=mid+1;
}
}
return -1;
}
int main(){
int n;
int choice;
int target;
int result;
int arr[n];
printf("Enter the no.of elements: ");
scanf("%d",&n);
printf("Enter the elements: ");
for(int i=0;i<n;i++){
scanf("%d",&arr[i]);
}
printf("Enter target: ");
scanf("%d",&target);
while(1){
printf("\nMenu Driven Function:\n");
printf("1)Linear Search\n2)Binary Search\n3)Exit\n");
scanf("%d", &choice);
switch(choice){
case 1:
result=linear_search(arr,n,target);
printf("The array is: ");
print(arr,n);
if(result!=-1){
printf("Target found at index %d.",result);
}
else{
printf("Element not found.");
}
break;
case 2:
bubble_sort(arr,n);
printf("The array is: ");
print(arr,n);
result=binary_search(arr,n,target);
if(result!=-1){
printf("Target found at index %d.",result);
}
else{
printf("Element not found.");
}
break;
case 3:
printf("Exiting Program...\n");
return 0;
default:
printf("Enter a valid choice.\n");
}
}
return 0;
}
