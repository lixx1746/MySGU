#include <iostream>

using namespace std;

int count(long long a) {
  int ans = 0;
  while(a > 0) {
    a /= 5;
    ans += a;
  }
  return ans;
}

int main(void) {
  int Q;
  cin >> Q;
  int c, l = 1, r = Q * 5;
  while(l < r) {
    int mid = (l + r) >> 1;
    c = count(mid);
    if(c < Q) l = mid + 1;
    else r = mid;
  }
  if(count(l) == Q) cout << l << endl;
  else cout << "No solution" << endl;
  return 0;
}
