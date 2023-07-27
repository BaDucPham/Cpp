#include<vector>
#include<iostream>

using namespace std;

using ull = unsigned long long;
ull exp_sum(unsigned int n) {
    vector<ull> ways(n+1, 0);
    ways[0] = 1;
    for(unsigned int i = 1; i <= n; i++){
        for(unsigned int j = i; j <= n; j++){
            ways[j] += ways[j - i];
        }
    }
    return ways[n];
}

int main(){
    //q: test code
    cout << exp_sum(10) << endl;
}