//Program to compare the strengths of people
#include<cstdio>
#include<vector>
using namespace std;

void compare_strength(int);
int main(){
    int testcase;
    printf("Enter the no.of Testcases: ");
    scanf("%d",&testcase);
    for(int i=1;i<=testcase;i++){
        compare_strength(i);
    }
    return 0;
}

//Function to compare the strengths of participants by finding the max1 and max2 and subtracting from them 
void compare_strength(int testcase){
    printf("Testcase %d: ",testcase);
    int size;
    printf("Enter the no.of Participants: ");
    scanf("%d",&size);
    vector<int>strength(size);
    printf("Enter the strengths of %d participants: ",size);
    for(int i=0;i<size;i++){
        scanf("%d",&strength[i]);
    }
    int max1=-1;
    int max2=-1;
    int count=0;
    for(int i=0;i<size;i++){
        if(strength[i]>max1){
            max2=max1;
            max1=strength[i];
            count=1;
        }
        else if(strength[i]==max1){
            count+=1;
        }
        else if(strength[i]>max2){
            max2=strength[i];
        }
    }
    printf("Output: ");
    for(int i=0;i<size;i++){
        if(strength[i]==max1 && count==1){
            printf("%d ",strength[i]-max2);
        }
        else{
            printf("%d ", strength[i]-max1);
        }
    }
    printf("\n");
}
