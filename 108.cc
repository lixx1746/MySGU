#include <iostream>

using namespace std;

int main(void) {
  int n, K, j;
  cin >> n;
  if(n < 9) cout << (n + 1) / 2 << endl;
  else cout << 4 + (n + 2) / 11 << endl;
  cin >> K;
  for(int i = 0; i < K; i++) {
    cin >> j;
    if(i > 0) cout << " ";
    if(j <= 4) cout << 2 * j - 1;
    else cout << 11 * (j - 4) - 2;
  }
  cout << endl;
  return 0;
}
