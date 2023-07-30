#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>
using namespace std;
class SumOfDivided
{
public:
    static string sumOfDivided(vector<int> &lst){
      cout << "Test\n";
      for (auto i: lst) cout << i << " ";
      cout << "\n";
      map<int,int> m;
      vector<int> lst_temp = lst;
      for (int i = 0; i<(int)lst.size();i++){
        if (lst_temp[i]%2==0){
          m[2] += lst[i];
          while (lst_temp[i]%2==0) lst_temp[i] /= 2;
        }
        for (int j = 3; j<=abs(lst_temp[i]); j+=2){
          if (lst_temp[i]%j==0){
            m[j] += lst[i];
            while (lst_temp[i]%j==0) lst_temp[i] /= j;
          }
        }
      }
      string res;
      for (auto i: m) res += "(" + to_string(i.first) + " " + to_string(i.second) + ")";
      return res;
    };
};

int main(){
  vector<int> lst_1 = {-29804, -4209, -28265, -72769, -31744};
  vector<int> lst_2 = {938, 24325, -39628, 12060, 7345, 36353, 2503, 19320, 35869, 35253, 14751, 15805, 38723, 36044, 9588, 3074, 34417, 17481, 28862, -18702, 14932, 7625, 10206, 5734, 17477, 20042 };
  cout << SumOfDivided::sumOfDivided(lst_2) << endl;
}