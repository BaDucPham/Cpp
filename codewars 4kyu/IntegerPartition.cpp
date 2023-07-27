#include <iostream>
#include <string>
#include <vector>
#include <numeric>    // std::accumulate
#include <functional> // std::multiplies
#include <set>
#include <sstream>
#include <iomanip>
using namespace std;
using ll = long long;
class IntPart
{
public:
  static vector<vector<ll>> enum_part(ll n){
    vector<vector<vector<ll>>> result(n+1, vector<vector<ll>>());
    for (ll j = 0; j <= n; j++) result[j].push_back(vector<ll>(j,1));
    for (ll j = 1; j <= n; j++){
      for (ll i = j; i <= n; i++){
        for (auto k: result[i-j]){
          k.push_back(j);
          result[i].push_back(k);
        }
      }
    }
    return result[n];
  }
  static set<ll> prod(ll n){
    vector<vector<ll>> e_p = enum_part(n);
    set<ll> result;
    for (auto i: e_p) result.insert(accumulate(i.begin(), i.end(), 1, multiplies<ll>()));
    return result;
  };

  static string part(ll n){
    set<ll> pd = prod(n);
    vector<ll> temp;
    copy(pd.begin(), pd.end(), back_inserter(temp));
    ll range = temp[temp.size() - 1] - temp[0];
    float avg = accumulate(temp.begin(), temp.end(), 0.0) / temp.size();
    float median = (temp.size() % 2 == 0) ? (temp[temp.size() / 2] + temp[temp.size() / 2 - 1]) / 2.0 : temp[temp.size() / 2];
    // Rounding avg and median to 2 decimal places string
    stringstream ss;
    ss << fixed << setprecision(2) << avg;
    string avg_str = ss.str();
    ss.str("");
    ss << fixed << setprecision(2) << median;
    string median_str = ss.str();
    return "Range: " + to_string(range) + " Average: " + avg_str + " Median: " + median_str;
  }
};

int main(){
  IntPart a;
  cout << a.part(5) << endl;
}