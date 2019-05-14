#include<iostream>
 
unsigned int h(string s)
{
  unsigned int h,i;
 
  h = 0;
  for(i = 0; i < s.length(); i++)
    h = 31 * h + s[i] - 65;
  return h % 10;
}
 
 
using namespace std;
 
int main(){
 
}
