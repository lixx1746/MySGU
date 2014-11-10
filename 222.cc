#include <iostream>
using namespace std;

long long fac(int n) {
  long long ans = 1;
  for(int i = 2; i <= n; i++) ans *= i;
  return ans;
}

int main(void) {
  int n, k;
  cin >> n >> k;
  if(k > n) cout << 0 << endl;
  else {
    long long nu = fac(n);
    long long dom1 = fac(k), dom2 = fac(n - k);
    long long cnk = nu / (dom1 * dom2);
    long long cnk1 = nu / dom2;
    cout << cnk * cnk1 << endl;
  }
  return 0;
}
