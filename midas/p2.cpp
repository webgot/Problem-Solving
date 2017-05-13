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
    int s, e;

    scanf("%d %d", &s, &e);
    func(e);
    
    for(int i = 0; i<p.size(); ++i){
        if(p[i] >= s && p[i] <= e)
            sum += p[i];
    }
   
    if(sum == 0)
        printf("-1");
    else
        printf("%d", sum);
    return 0;

}
