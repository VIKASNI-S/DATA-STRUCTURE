//Program to find the no.of deletions to get unique numbers
#include<cstdio>
#include<vector>
#include<unordered_set>
using namespace std;

void count_deletion(int testcase);
int main(){
    int testcase;
    printf("Enter the no.of testcases: ");
    scanf("%d",&testcase);
    for(int k=1;k<=testcase;k++){
        count_deletion(k);
    }
        return 0;
}


//Function to count the no.of deletions
void count_deletion(int testcase){
    printf("Testcase %d:\n",testcase);
    int size;
    printf("Enter the no.of numbers: ");
    scanf("%d",&size);
    vector<int>array(size);
    printf("Enter the numbers: ");
    for(int i=0;i<size;i++){
        scanf("%d",&array[i]);
    }
    unordered_set<int>seen;
    int count=0;
    for(int i=size-1;i>=0;i--){
     if(seen.count(array[i])) break;
     seen.insert(array[i]);
     count++;
    }
    printf("No.of deletions:%d\n",size-count );

}
