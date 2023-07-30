#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class DirReduction
{
public:
    static vector<string> dirReduc(vector<string> &arr){
      if (arr.size() <= 1) return arr;
      vector<vector<string>> neg_list = {{"NORTH","SOUTH"},{"SOUTH","NORTH"},{"EAST","WEST"},{"WEST","EAST"}};
      vector<vector<string>>::iterator it;
      for (int i = 1; i < arr.size(); ++i){
        it = find(neg_list.begin(),neg_list.end(),vector<string>{arr[i-1],arr[i]});
        if (it != neg_list.end()){
          arr.erase(arr.begin()+i-1,arr.begin()+i+1);
          i = 0;
        }
      }
      return arr;
    }  
};

int main(){
  vector<string> arr = {"NORTH","SOUTH","SOUTH","EAST","WEST","NORTH","WEST"};
  DirReduction::dirReduc(arr);
  for (auto i:arr) cout << i << " ";
}