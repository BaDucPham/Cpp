#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string add(const string& a, const string& b) {
  string res;
  int carry = 0;
  int i = a.size()-1;
  int j = b.size()-1;
  while (i>=0 || j>=0 || carry){
    int sum = carry;
    if (i>=0) sum += a[i--]-'0';
    if (j>=0) sum += b[j--]-'0';
    carry = sum/10;
    res += std::to_string(sum%10);
  }
  reverse(res.begin(),res.end());
  return res;
}

int main(){
  cout << add("123","456") << endl;
}