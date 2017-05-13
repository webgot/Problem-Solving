#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> num, set;
int ans = 0;

void proc(int k, int s, int n, int m){


    if((int)set.size() == n){
        int even = 0;
        int odd = 0;
    
        for(int i = 0; i<(int)set.size(); ++i){
            if(set[i]%2) odd = 1;
            else  even = 1;
        }

        if(odd && even){
            ++ans;
        }
    
        return ;
    }

    int e = m-n+s;
    for(int i = k; i<=e; ++i){
        set.push_back(num[i]);
        proc(i+1, s+1, n, m);
        set.pop_back();
    }
}
int main(void){

    int n, m, k;
    scanf("%d %d", &n, &m);

    for(int i = 0; i<m; ++i){
        scanf("%d", &k);
        num.push_back(k);
    }

    sort(num.begin(), num.end());

    proc(0, 0, n, m);
    printf("%d", ans);
    return 0;

}
