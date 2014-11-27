#include <iostream>

using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int main(void) {
  int N, ans = 0, i = 1;
  cin >> N;
  while(i <= N) if(gcd(N, i++) == 1) ans++;
  cout << ans << endl;
  return 0;
}
