#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>

using namespace std;

char before[14];
char after[14];
int max(int a, int b){

    return a > b ? a : b;
}
int proc(void){

    int memo[14][14];

    for(int i = 0; i<=13; ++i){
        memo[0][i] = memo[i][0] = 0;    
    }

    for(int i =1; i<= 13; ++i){
        for(int j = 1; j<=13; ++j){
        
            if(after[i] == before[j]){
                memo[i][j] = memo[i-1][j-1] + 1;
            }
            else{
                memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
            }
        }
    }

    return memo[13][13];
}
int main(void){

    char input[3];
   
    for(int i = 1; i<=13; ++i){
        scanf("%s", input);
        if((int)strlen(input) == 2){
            before[i] = 'B';
        }
        else
            before[i] = input[0];
    }
    
    for(int i = 1; i<=13; ++i){
        scanf("%s", input);
        if((int)strlen(input) == 2){
            after[i] = 'B';
        }
        else
            after[i] = input[0];
    }

    printf("%d", proc());
    return 0;

}
