#include <iostream>
#include <vector>
using namespace std;


long long determinant(vector< vector<long long> > m) {
  if (m.size() == 1) return m[0][0];
  vector< vector<long long> > m_cop = m;
  vector< vector<long long> > mat_minor;
  int index;
  for (int i = 0; i< m_cop.size(); i++) m_cop[i].erase(m_cop[i].begin());
  long long det = 0;
  for (int i = 0; i<(int)m[0].size(); i++){
    mat_minor = m_cop;
    mat_minor.erase(mat_minor.begin()+i);
    index = (i%2 == 0)? 1 : -1;
    det += index*m[i][0]*determinant(mat_minor);
    index *= -1;
  }
  return det;
}

int main(){
  vector< vector<long long> > m = {{2,5,3},{1,-2,-1},{1,3,4}};
  cout << determinant(m) << endl;
}