//Menu driven program to determine whether a number is palindrome, armstrong or perfect.
#include<cstdio>
#include<stdlib.h>

//Function to check whether a given number is palindrome or not
int palindrome(int num){
    int *original=(int *)malloc(sizeof(int));
    int *remainder=(int *)malloc(sizeof(int));
    int *reversed=(int *)malloc(sizeof(int));
    *original=num;
    *reversed=0;
    while(num!=0){
        *remainder=(num)%10;//extract the last digit
        *reversed=(*reversed)*10+(*remainder);//form the reversed number 
        (num)/=10;//remove the last digit
    }return((*original)==(*reversed));
    free(original);
    free(remainder);
    free(reversed);
}

//Function to calculate the power
int power(int base,int exp){
    int *result=(int *)malloc(sizeof(int));
    *result=1;
    int *i=(int *)malloc(sizeof(int));
    for(*i=0;*i<exp;(*i)++){
        (*result)*=base;
    }
    return *result;
    free(result);
    free(i);
}

//Function to check whether a number is Armstrong or not
int armstrong(int num){
    int *sum=(int *)malloc(sizeof(int));
    int *remainder=(int *)malloc(sizeof(int));
    int *digit=(int *)malloc(sizeof(int));
    int *original=(int *)malloc(sizeof(int));
    
    *sum=0;
    *digit=0;
    *original=num;
    while((*original)!=0){//To find the no.of digits
        (*original)/=10;
        (*digit)++;
    }
    *original=num;
    while((*original)!=0){
        *remainder=(*original)%10;
        *sum+=power(*remainder,*digit);//raise the no.of digits as powers and add the result
        (*original)/=10;
    }return((*sum)==num);
    free(sum);
    free(remainder);
    free(digit);
    free(original);
}

//Function to check whether a number is perfect or not
int perfect(int num){
    int *sum=(int *)malloc(sizeof(int));
     int *i=(int *)malloc(sizeof(int));
    *sum=0;
    for(*i=1;(*i)<=num/2;(*i)++){
        if(num%(*i)==0){
            (*sum)+=(*i);
        }
    }
    return((*sum)==num);
    free(sum);
    free(i);
}

int main(){
    int *num=(int *)malloc(sizeof(int));
    int *choice=(int *)malloc(sizeof(int));
    if(num==NULL){
        printf("Memory Allocation failed...");
    }
    if(choice==NULL){
        printf("Memory Allocation failed...");
    }
    do{
        printf("\nMenu Driven Program\n 1)Palindrome\n 2)Armstrong\n 3)Perfect\n 4)Exit\n");
        scanf("%d", choice);
        if(*choice<=3 && *choice>=1){
            printf("Enter a number: ");
            scanf("%d", num);
        }

       switch(*choice){
        case 1:
        if(palindrome(*num)){
            printf("%d is a Palindrome.", *num);
        }
        else{
            printf("%d is not a Palindrome.", *num);
        }
        break;
        case 2:
        if(armstrong(*num)){
            printf("%d is an Armstrong Number.", *num);
        }
        else{
             printf("%d is not an Armstrong Number.", *num);
        }
        break;
         case 3:
        if(perfect(*num)){
            printf("%d is a Perfect number.", *num);
        }
        else{
            printf("%d is not a Perfect number.", *num);
        }
        break;
        
        case 4:
        printf("Exiting Program....\n ");
        return 0;
        default:
        printf("Enter a valid choice.\n");
       }
    }while(*choice!=4);
    free(num);
    free(choice);
}