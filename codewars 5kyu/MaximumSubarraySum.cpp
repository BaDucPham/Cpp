#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int maxSequence(const std::vector<int>& arr){
    int Max1 = 0, Max2 = 0,x;
    for (auto x:arr){
        Max1 = max(x, Max1 + x);
        Max2 = max(Max2, Max1);
    }
    return Max2;
}

int main(){
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSequence(arr) << endl;
}