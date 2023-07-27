#include <iostream>
#include <vector>
using namespace std;
// Your new function as given to you by me, your boss.
int cut_log(const vector<int>& p, int n){
  int solution[n+1];
  for (int i = 0; i<n+1;i++) solution[i] = p[i];
  for(int j = 2 ; j <= n ; j++){
    for(int i = 1 ; i <= j/2 ; i++){ // Two nested loops = Θ(n^2)
      if (solution[j] < solution[j-i]+solution[i]) solution[j] = solution[j-i]+solution[i];
    }
  }
  return solution[n]; // Good luck intern!
}

int main(){
    vector<int> p = {0,1,5,8,9,10,17,17,20,24,30};
    cout << cut_log(p, 4) << endl;
}