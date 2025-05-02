//Program to calculate the score of participants by playing a word game
#include<cstdio>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

void find_score(int);

int main(){
    int testcase;
    printf("Enter the no.of testcases: ");
    scanf("%d",&testcase);
    for(int t=1;t<=testcase;t++){
        find_score(t);
    }
    return 0;
}
//Function to calculate the score of participants
void find_score(int testcase){
    printf("Testcase %d:\n",testcase);
    int n;
    printf("Enter the no.of words: ");
    scanf("%d",&n);
    vector<vector<string>>words(3,vector<string>(n));
    unordered_map<string,int>wordCount;
    for(int i=0;i<3;i++){
        for(int j=0;j<n;j++){
            char temp[100];
            scanf("%s",temp);
            words[i][j]=temp;
            wordCount[words[i][j]]++;
        }
    }
    vector<int>score(3,0);
    for(int i=0;i<3;i++){
        for(int j=0;j<words[i].size();j++){
            const string& word=words[i][j];
            if(wordCount[word]==1){
                score[i]+=3;
            }
            else if(wordCount[word]==2){
                score[i]+=1;
            }
        }
    }
    printf("Scores of the three participants:%d, %d, %d.\n",score[0],score[1],score[2]);
}
