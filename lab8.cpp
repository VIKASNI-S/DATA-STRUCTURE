//Program to find the largest number of blocks in tower1
//Input:No.of testcases and towers, sorting them and comparing tower1 with other towers
#include<cstdio>
#include<algorithm>


int main(){
    int cases,towers;
    printf("Enter the no.of Testcases: ");
    scanf("%d",&cases);
    for(int i=1;i<=cases;i++){
        printf("Enter the details of Teatcase %d:\n",i);
        printf("Enter the no.of Towers: ");
        scanf("%d",&towers);
        int arr[towers];
        for(int t=0;t<towers;t++){
            printf("Enter the no.of blocks in tower %d: ",t+1);
            scanf("%d",&arr[t]);
        
             }
             std::sort(arr+1,arr+towers);
            for(int j=1;j<towers;j++){
               
                if(arr[j]>arr[0]){
                    if((arr[j]+arr[0])%2==0){
                        arr[0]=((arr[j]+arr[0])/2);
                        
                    }
                    else{
                        arr[0]=((arr[j]+arr[0])/2)+1;
                    }
                    
                }
            
                
            }
           printf("For testcase %d, no.of blocks in tower1 is %d.\n",i,arr[0]);
            
         

    }
    return 0;

}