//Program to find the no.of survivors in the game
#include<cstdio>
#include<vector>
void find_winners();
int main(){
    int testcase;
    printf("Enter the no.of Testcases: ");
    scanf("%d",&testcase);
    while(testcase--){
        find_winners();
    }
    return 0;
}

//Function to find the no.of winners by comparing each query with the indices[0]
void find_winners(){
    int k,q;
    printf("Enter the no.of elimination indices(k): ");
    scanf("%d",&k);
    printf("Enter the no.of Queries: ");
    scanf("%d",&q);
    printf("Enter the indices: ");
    std::vector<int>indices(k);
    for(int i=0;i<k;i++){
        scanf("%d",&indices[i]);
    }
    printf("Enter the queries: ");
    while(q--){
        int n;
        scanf("%d",&n);
        if(n>=indices[0]){
            printf("%d ",indices[0]-1);
        }
        else{
            printf("%d ",n);
        }
    }
    printf("\n");

}
