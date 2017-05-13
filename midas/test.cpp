#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>

using namespace std;

vector<int> num, psum;
int memo[3000];
int max(int a, int b){

    return a > b ? a : b;
}
int min(int a, int b){

    return a > b ? b : a;
}
int proc( int s , int e){

    if(s >= e){
        return 0;
    }
    if(memo[s] == -1){
        int mini = min(min(num[s], num[s+1]), num[s+2]);
        memo[s] =  max(proc(s+3, e) + mini, proc(s+1, e));
    }

    return memo[s];
}
int main(void){
    
    int n, a;
    int sum = 0;
    scanf("%d", &n);

    memset(memo, -1, sizeof(memo));

    for(int i = 0; i<n; ++i){
        scanf("%d", &a);
        num.push_back(a);
        sum+= a;
    }

    for(int i = 0; i<n-2; ++i){
        psum.push_back(num[i] + num[i+1] + num[i+2]);
    }

    printf("%d", sum - proc(0, n-2));
     
    return 0;

}
