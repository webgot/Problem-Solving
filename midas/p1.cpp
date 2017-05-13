#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

vector<int> p;

void func(int e){
  

    int is_prime;
    p.push_back(2);

    for(int n = 2; n<=e; ++n){
		
	    if( (n&1) == 0 ) 
	    	continue; 

	    is_prime = 1;
	    for(int i=3; i*i<=n; i++)
	    { 
		    if( n % i == 0)
		    {
		        is_prime = 0; 
		    }
	    }
	    if(is_prime)
            p.push_back(n);
    }
}
int main(void){

    int sum = 0;
    int n, m;

    scanf("%d %d", &n, &m);
    func(100);
    
    
    for( int i = 2; i<=n; ++i){
        
        int midx = 0;
        for(int j = 0; j<(int)p.size(); ++j){
            if( i % p[j] == 0)
                midx = j;
        }
        
        if(p[midx] <= m)
            ++sum;
    }
    
    printf("%d", sum);
    return 0;

}
