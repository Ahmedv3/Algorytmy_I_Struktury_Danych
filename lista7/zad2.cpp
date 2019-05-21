#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int f(int n){
     int count = 0; 
while (n) 
{ 
    count += n & 1; 
    n >>= 1; 
} 
return count;  
}

int main(){

    int i = 9; 
    cout << f(i) << endl; 

    return 0;
}