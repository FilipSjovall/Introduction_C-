#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

bool checkPrime(const unsigned int n){
    if(n<=2){    
    }else{
        for(unsigned int i=2; i<n-1; i++){
            if(n%i==0){
                return false;
            }
        }
    }
    return true;
}

void findPrimes(std::string& numbers){
    for(unsigned int p=2; p<numbers.length()-1; p++){ // Could check even fewer
        if(!checkPrime(p)){
            numbers[p+1] = 'C';
        }        
    }
}
int findLargest(std::string& primes){
    int largest = primes.find_last_of('P');
    return largest-1;    
}


int main(){
    int len = 35;


    std::string ps(len,'P');
    ps[0]='C';
    ps[1]='C';
    findPrimes(ps);
    std::cout << ps << std::endl;


    len = 100000;
    std::string s(len,'P');
    findPrimes(s);
    int a = findLargest(s);
    std::cout << a << std::endl;
}