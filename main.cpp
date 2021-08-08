#include<pybind11/pybind11.h>
#include<pybind11/stl.h>
#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>


bool isPrime(int n){
    if(n<2) return false;
    else if((n==2) or (n==3)) return true;
    else if((n%2==0) or (n%3==0)) return false;
    else{
        for(int i=2; i<n;i++){
            if(n%i==0)return false;
        }
        return true;
    }
};

int primeAt(double num){
    double cnt = 0, val = 2;
    if (num<0) return -1;
    else if(num==0) return 2;
    else if (num==1) return 3;

    while (1){
        if(isPrime(val)) cnt+=1;
        if(cnt>num) break;
        else val+=1;
    }
    return val;
};

int nextPrime(int n){
    if(n<1) return -1;
    while(1){
        n++;
        if(isPrime(n)) break;
    }
    return n;
};

int prevPrime(int n){
    if(n<3) return 2;
    while(1){
        n--;
        if(n<2) break;
        if(isPrime(n)) break;
    }
    return n;
};

std::vector<int> PrimeNumbersBetween(int from, int to){
    std::vector<int> items;
    if((from<0) || (to<0)){
        std::cout<<"Number(s) should positive."<<std::endl;
        return {};
    }
    else if(to<from){
        std::cout<<"End number should be greater than initial number."<<std::endl;
        return {};
    }else{
        for(int i=from;i<=to;i++)
            if(isPrime(i)) items.push_back(i);
    }
    return items;
};

std::vector<int> primeUpto(int n){
    std::vector<int> items;
    if (n<2) return items;
    for(int i=2; i<=n; i++){
        if (isPrime(i)) items.push_back(i);
    }
    return items;
};

int randomPrime(int from, int to){
    std::vector<int> items;
    srand((unsigned int)time(NULL));

    if((from<0) || (to<0)){
        std::cout<<"Number(s) should positive."<<std::endl;
        return 0;
    }
    else if(to<from){
        std::cout<<"End number should be greater than initial number."<<std::endl;
        return 0;
    }
    for(int i=from; i<=to; i++){
        if (isPrime(i)) items.push_back(i);
    }
    return items[rand()%items.size()];
};

PYBIND11_MODULE(cerel, handler){
    handler.doc()="Operation on prime number:\n1.Check the number is prime or not.\n2.Get the prime number from index.\n3.Get all the prime numbers between some specofic range.\n4.Get the next prime number.\n5.Get the previous prime number.\n6.Get all prime number till nth number.\n7.Get random prime number from range.";
    handler.def("isPrime", &isPrime);
    handler.def("primeAt", &primeAt);
    handler.def("PrimeNumbersBetween", &PrimeNumbersBetween);
    handler.def("nextPrime", &nextPrime);
    handler.def("prevPrime", &prevPrime);
    handler.def("primeUpto", &primeUpto);
    handler.def("randomPrime", &randomPrime);
};