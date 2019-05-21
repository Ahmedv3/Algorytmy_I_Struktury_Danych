#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int f(int n){
     int count = 0; // ustawiami licznik
while (n) 
{ 
    count += n & 1; // koniunkcja bitowa // 0 z 0 = 0 , 1 z 0 = 0, 0 z 1 = 0 , 1z1 = 1
    n >>= 1;  // przesunięcie bitowe o w prawo (usuwa jedna liczbe z prawej i dodaje 0 na poczatek )
} 
return count;  
}

int main(){

    int i = 9; 
    cout << f(i) << endl; 

    return 0;
}