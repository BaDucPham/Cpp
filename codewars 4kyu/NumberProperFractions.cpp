#include <cmath>
#include <map>
#include <iostream>
#include <vector>
using namespace std;

vector <long> prime_divisor(long n)
{   
    vector <long> a;
    if (n%2==0) a.push_back(2);
    while (n%2==0) n /= 2;
    for (long i = 3; i<= sqrt(n);i+=2){
      if (n%i==0) a.push_back(i);
      while (n%i==0) n /= i;
    }
    if (n>2) a.push_back(n);
    return a;
}

long properFractions(long n)
{ 
  if (n==1) return 0;
  long res = n;
  for (auto i: prime_divisor(n)) res /= i;
  for (auto i: prime_divisor(n)) res *= (i-1);
  return res;
}

int main(){
  cout << properFractions(15) << endl;
}